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

        if (root["tmp_dir"])
            conf.tmp_dir = root["tmp_dir"].as<std::string>();
        else
            conf.tmp_dir = "gen_rfl"; // 默认值（可选）

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

        if (root["source_pattern"])
            conf.source_pattern = root["source_pattern"].as<std::string>();
        else
            conf.source_pattern = ".+\\.(cpp|c|c++|cc|cxx|h|hpp|hxx)$";

        if (root["cmake_pattern"])
            conf.cmake_pattern = root["cmake_pattern"].as<std::string>();
        else
            conf.cmake_pattern = "^.*/CMakeFiles/.+/CMake.+$";

        conf.llvm_args.clear();
        if (root["llvm_args"])
        {
            const YAML::Node &llvm_args = root["llvm_args"];
            if (llvm_args.IsSequence())
            {
                for (size_t i = 0; i < llvm_args.size(); ++i)
                {
                    conf.llvm_args.push_back(llvm_args[i].as<std::string>());
                }
            }
        }
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
    root["tmp_dir"] = "gen_rfl";
    root["src_dir"] = "./";
    root["libs_dir"] = "libs";
    root["include_dir"] = "include";
    root["source_pattern"] = ".+\\.(cpp|c++|cc|cxx|h|hpp|hxx)$";
    root["cmake_pattern"] = "^.*/CMakeFiles/.+/CMake.+$";

    YAML::Node llvm_args;
    llvm_args.push_back("--std=c++20");
    llvm_args.push_back("-I/usr/include");
    llvm_args.push_back("-I/usr/include/c++/12");
    llvm_args.push_back("-I/usr/include/x86_64-linux-gnu/c++/12");
    llvm_args.push_back("-I/usr/lib/llvm-15/include");
    llvm_args.push_back("-fparse-all-comments");
    llvm_args.push_back("-D__clang__");
    root["llvm_args"] = llvm_args;

    try
    {
        std::ofstream fout(output_file);
        if (fout)
        {
            fout << root;
            fout.close();
            std::cout << "YAML 文件已成功写入: " << output_file << std::endl;
            return 0;
        }
        else
        {
            std::cerr << "无法打开文件进行写入: " << output_file << std::endl;
            return 1;
        }
    }
    catch (...)
    {

        return 1;
    }

    return 0;
}
