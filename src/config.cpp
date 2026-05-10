// Copyright (c) 2023-2025 Zhao Yun Shan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include "config.h"
#include <fstream>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include "reflect.h"

namespace reflect
{

    // 确保typedef_map在__init_base_types之前初始化
    struct TypedefMapInit
    {
        std::map<std::string, std::string> map;
        TypedefMapInit()
        {
            map = {
                {"int8_t", "signed char"},
                {"uint8_t", "unsigned char"},
                {"int16_t", "short"},
                {"uint16_t", "unsigned short"},
                {"int32_t", "int"},
                {"uint32_t", "unsigned int"},
                {"int64_t", "long long"},
                {"uint64_t", "unsigned long long"},
            };
        }
    };
    static TypedefMapInit typedef_map_init;
    static std::map<std::string, std::string> &typedef_map = typedef_map_init.map;

    static std::set<std::string> all_fundamentals = {
        "bool",
        "char",
        "signed char",
        "unsigned char",
        "short",
        "unsigned short",
        "int",
        "unsigned int",
        "long",
        "unsigned long",
        "long long",
        "unsigned long long",
        "float",
        "double",
        "long double",
        "std::string",
    };
    auto __init_base_types = []()
    {
        for (auto &t : all_fundamentals)
        {
            insert_base_types(t);
        }
        
        // 添加指针类型
        std::vector<std::string> pointer_types = {"char*", "const char*"};
        for (auto &t : pointer_types)
        {
            insert_base_types(t);
        }
        
        return 0;
    }();
    Conf &get_config()
    {
        static Conf conf;
        return conf;
    }

    int read_config_from_yaml(const std::string &output_file)
    {
        try
        {
            YAML::Node root = YAML::LoadFile(output_file);

            auto &conf = get_config();

            if (root["rfl_dir"])
                conf.rfl_dir = root["rfl_dir"].as<std::string>();
            else
                conf.rfl_dir = "gen_rfl"; // 默认值（可选）

            if (root["src_dir"])
                conf.src_dir = root["src_dir"].as<std::string>();
            else
                conf.src_dir = "./";

            if (root["libs_dir"])
                conf.libs_dir = root["libs_dir"].as<std::string>();
            else
                conf.libs_dir = "libs";

            if (root["include_dir"])
                conf.include_dir = root["include_dir"].as<std::string>();
            else
                conf.include_dir = "include";

            if (root["tpl_dir"])
            {
                conf.tpl_dir = root["tpl_dir"].as<std::string>();
                if (conf.tpl_dir.back() != '/')
                {
                    conf.tpl_dir += "/";
                }
            }
            else
                conf.tpl_dir = "/usr/local/include/gen_rfl/tpl/";

            if (root["source_pattern"])
                conf.source_pattern = root["source_pattern"].as<std::string>();
            else
                conf.source_pattern = "\\.(cpp|c|c++|cc|cxx|h|hpp|hxx)$";

            if (root["cmake_pattern"])
                conf.cmake_pattern = root["cmake_pattern"].as<std::string>();
            else
                conf.cmake_pattern = "^.*/CMakeFiles/.+/CMake.+$";

            return 0;
        }
        catch (...)
        {
            return 1;
        }
        return 0;
    }

    int write_default_to_yaml(const std::string &output_file)
    {
        YAML::Node root;
        root["rfl_dir"] = "gen_rfl";
        root["src_dir"] = "./";
        root["libs_dir"] = "libs";
        root["include_dir"] = "include";
        root["tpl_dir"] = "/usr/local/include/gen_rfl/tpl/";
        root["source_pattern"] = "\\.(cpp|c++|cc|cxx|h|hpp|hxx)$";
        root["cmake_pattern"] = "^.*/CMakeFiles/.+/CMake.+$";

        try
        {
            std::ofstream fout(output_file);
            if (fout)
            {
                fout << root;
                fout.close();
                std::cout << "YAML 文件已成功写入：" << output_file << std::endl;
                return 0;
            }
            else
            {
                std::cerr << "无法打开文件进行写入：" << output_file << std::endl;
                return 1;
            }
        }
        catch (...)
        {
            return 1;
        }

        return 0;
    }
    bool is_typedef_type(const std::string &type)
    {
        // 检查是否是const类型
        std::string type_without_const = type;
        if (type_without_const.find("const ") == 0)
        {
            type_without_const = type_without_const.substr(strlen("const "));
        }

        // 检查是否是typedef类型
        return typedef_map.find(type_without_const) != typedef_map.end();
    }

    std::string get_original_type(const std::string &type)
    {
        // 检查是否是const类型
        bool is_const = false;
        std::string type_without_const = type;
        if (type_without_const.find("const ") == 0)
        {
            is_const = true;
            type_without_const = type_without_const.substr(strlen("const "));
        }

        // 检查是否是typedef类型
        auto it = typedef_map.find(type_without_const);
        if (it != typedef_map.end())
        {
            return is_const ? "const " + it->second : it->second;
        }

        return type;
    }

    void insert_base_types(const std::string &type)
    {
        // 如果是 typedef 类型，直接返回，不添加到 base_types 集合中
        if (is_typedef_type(type))
        {
            return;
        }

        // 转换为原始类型
        std::string original_type = get_original_type(type);

        // 检查是否已经添加了对应的原始类型
        if (get_config().base_types.find(original_type) != get_config().base_types.end())
        {
            return;
        }

        // 恢复原始的拆分逻辑：同时添加 const 和非 const 版本
        if (original_type.find("const ") == 0)
        {
            get_config().base_types.emplace(original_type);
            get_config().base_types.emplace(original_type.substr(strlen("const ")));
        }
        else
        {
            get_config().base_types.emplace(original_type);
            get_config().base_types.emplace(std::string("const ") + original_type);
        }
    }

    // 保存referenced_headers到文件
    void save_referenced_headers()
    {
        auto &conf = get_config();
        std::string file_path = conf.rfl_dir + "/referenced_headers.txt";
        std::ofstream fout(file_path);
        if (fout)
        {
            // 保存 generated 集合
            for (const auto &gen : conf.generated)
            {
                fout << "GEN:" << gen << std::endl;
            }
            // 保存相对路径
            for (const auto &header : conf.referenced_headers)
            {
                fout << "REL:" << header << std::endl;
            }
            // 保存绝对路径
            for (const auto &header : conf.referenced_headers_absolute)
            {
                fout << "ABS:" << header << std::endl;
            }
            fout.close();
        }
    }

    // 从文件加载referenced_headers
    void load_referenced_headers()
    {
        auto &conf = get_config();
        std::string file_path = conf.rfl_dir + "/referenced_headers.txt";
        std::ifstream fin(file_path);
        if (fin)
        {
            std::string line;
            while (std::getline(fin, line))
            {
                if (!line.empty())
                {
                    if (line.substr(0, 4) == "GEN:")
                    {
                        conf.generated.insert(line.substr(4));
                    }
                    else if (line.substr(0, 4) == "REL:")
                    {
                        conf.referenced_headers.insert(line.substr(4));
                    }
                    else if (line.substr(0, 4) == "ABS:")
                    {
                        conf.referenced_headers_absolute.insert(line.substr(4));
                    }
                    else
                    {
                        // 兼容旧格式：只保存头文件的名称
                        size_t last_slash_pos = line.find_last_of("/");
                        std::string header_name_only;
                        if (last_slash_pos != std::string::npos)
                        {
                            header_name_only = line.substr(last_slash_pos + 1);
                        }
                        else
                        {
                            header_name_only = line;
                        }
                        conf.referenced_headers.insert(header_name_only);
                    }
                }
            }
            fin.close();
        }
    }

}