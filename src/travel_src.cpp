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

#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include <regex>
#include <list>
#include <string>
#include <map>
#include <memory>
#include <cstring>
#include "analyzer.h"
#include "format_tpl.h"
#include "branch.h"
#include "reflect.h"
#include "filter.h"
#include "config.h"
#include "gen_rfl.h"
#include "sys.h"
#include "travel_src.h"

extern "C"
{
#include <tree_sitter/api.h>
#include "../third-party/tree-sitter-cpp/bindings/c/tree-sitter-cpp.h"
}

namespace reflect
{
    std::string get_original_type(const std::string &type);

    template <class S, class D>
    auto join(const S str, const D &delimiter)
    {
        std::ostringstream oss;
        auto it = str.begin();
        if (it != str.end())
        {
            oss << *it++;
        }
        while (it != str.end())
        {
            oss << delimiter << *it++;
        }
        return oss.str();
    }

    std::string get_node_text(TSNode node, const char *source_code)
    {
        if (!source_code)
        {
            std::cerr << "source_code is null" << std::endl;
            return "";
        }

        if (ts_node_is_null(node))
        {
            std::cerr << "node is invalid" << std::endl;
            return "";
        }

        uint32_t start_byte = ts_node_start_byte(node);
        uint32_t end_byte = ts_node_end_byte(node);

        if (start_byte > end_byte)
        {
            std::cerr << "Invalid node byte range: start=" << start_byte << ", end=" << end_byte << std::endl;
            return "";
        }

        const char *start = source_code + start_byte;
        const char *end = source_code + end_byte;

        return std::string(start, end - start);
    }

    std::string extract_type_name(const std::string &type_str)
    {
        std::string result = type_str;

        if (result.find("const ") == 0)
        {
            result = result.substr(6);
        }
        if (result.find("class ") == 0)
        {
            result = result.substr(6);
        }
        if (result.find("struct ") == 0)
        {
            result = result.substr(7);
        }
        if (result.find("union ") == 0)
        {
            result = result.substr(6);
        }

        size_t amp_pos = result.find('&');
        if (amp_pos != std::string::npos)
        {
            result = result.substr(0, amp_pos);
        }

        while (!result.empty() && result.back() == ' ')
        {
            result.pop_back();
        }

        return result;
    }

    uint32_t get_access_flags(const std::string &access_str)
    {
        if (access_str == "public")
            return reflect::__flag(reflect::flag_public);
        else if (access_str == "protected")
            return reflect::__flag(reflect::flag_protected);
        else if (access_str == "private")
            return reflect::__flag(reflect::flag_private);
        return reflect::__flag(reflect::flag_member);
    }

    bool has_qualifier(const std::string &type_str, const std::string &qualifier)
    {
        return type_str.find(qualifier) != std::string::npos;
    }

    struct FieldInfo
    {
        std::string name;
        std::string type;
        std::string access;
        bool is_static = false;
        bool is_const = false;
        bool is_volatile = false;
    };

    struct MethodInfo
    {
        std::string name;
        std::string return_type;
        std::list<std::string> parameters;
        std::string access;
        bool is_const = false;
        bool is_virtual = false;
    };

    struct BaseClassInfo
    {
        std::string name;
        std::string access;
    };

    struct ClassInfo
    {
        std::string name;
        std::string raw_name;
        std::string file;
        std::string namespace_name;
        int object_type = 0;
        std::vector<FieldInfo> fields;
        std::vector<MethodInfo> methods;
        std::vector<BaseClassInfo> base_classes;
    };

    class Parser
    {
    public:
        Parser() {}
        ~Parser() {}

    private:
        std::string m_source_code;

    public:
        bool parse_file(const std::string &filename)
        {
            std::ifstream file(filename);
            if (!file.is_open())
            {
                std::cerr << "Failed to open file: " << filename << std::endl;
                return false;
            }

            m_source_code = std::string((std::istreambuf_iterator<char>(file)),
                                        std::istreambuf_iterator<char>());
            file.close();
            return true;
        }

        void extract_classes(std::vector<ClassInfo> &classes)
        {
            // 首先使用 tree-sitter 解析
            std::cout << "Using tree-sitter extraction" << std::endl;
            extract_classes_with_tree_sitter(classes);

            // 如果 tree-sitter 解析失败（没有提取到类），回退到正则表达式解析
            if (classes.empty())
            {
                std::cout << "Tree-sitter extraction failed, falling back to regex extraction" << std::endl;
                extract_classes_with_regex(classes);
            }
        }

        void extract_classes_with_tree_sitter(std::vector<ClassInfo> &classes)
        {
            try
            {
                std::cout << "Starting tree-sitter extraction" << std::endl;

                // 检查源代码是否为空
                if (m_source_code.empty())
                {
                    std::cerr << "Source code is empty" << std::endl;
                    return;
                }

                std::cout << "Source code size: " << m_source_code.size() << " bytes" << std::endl;

                // 初始化 tree-sitter 解析器
                std::cout << "Creating tree-sitter parser" << std::endl;
                TSParser *parser = ts_parser_new();
                if (!parser)
                {
                    std::cerr << "Failed to create tree-sitter parser" << std::endl;
                    return;
                }

                // 设置语言
                std::cout << "Setting tree-sitter language" << std::endl;
                const TSLanguage *language = ::tree_sitter_cpp();
                if (!language)
                {
                    std::cerr << "Failed to get tree-sitter language" << std::endl;
                    ts_parser_delete(parser);
                    return;
                }
                if (!ts_parser_set_language(parser, language))
                {
                    std::cerr << "Failed to set tree-sitter language" << std::endl;
                    ts_parser_delete(parser);
                    return;
                }

                // 解析源代码
                std::cout << "Parsing source code" << std::endl;
                TSTree *tree = ts_parser_parse_string(parser, NULL, m_source_code.c_str(), m_source_code.size());
                if (!tree)
                {
                    std::cerr << "Failed to parse source code" << std::endl;
                    ts_parser_delete(parser);
                    return;
                }

                std::cout << "Parsing completed successfully" << std::endl;

                TSNode root = ts_tree_root_node(tree);
                std::cout << "Root node type: " << ts_node_type(root) << std::endl;

                // 遍历语法树，提取类信息
                std::cout << "Extracting classes from node" << std::endl;
                extract_classes_from_node(root, classes);

                std::cout << "Extraction completed. Found " << classes.size() << " classes" << std::endl;

                // 清理资源
                std::cout << "Cleaning up resources" << std::endl;
                ts_tree_delete(tree);
                ts_parser_delete(parser);
                std::cout << "Resources cleaned up" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error in extract_classes_with_tree_sitter: " << e.what() << std::endl;
            }
        }

        void extract_classes_from_node(TSNode node, std::vector<ClassInfo> &classes, const std::string &current_namespace = "")
        {
            // 检查当前节点是否是类、结构体或联合体定义
            if (ts_node_is_named(node))
            {
                std::string node_type = ts_node_type(node);
                if (node_type == "class_specifier" || node_type == "struct_specifier" || node_type == "union_specifier")
                {
                    std::cout << "Found class/struct/union: " << node_type << std::endl;
                    // 调试：打印所有子节点
                    std::cout << "Node child count: " << ts_node_child_count(node) << std::endl;
                    for (uint32_t i = 0; i < ts_node_child_count(node); i++)
                    {
                        TSNode child = ts_node_child(node, i);
                        if (ts_node_is_named(child))
                        {
                            std::cout << "Child " << i << " type: " << ts_node_type(child) << std::endl;
                            std::cout << "Child " << i << " text: " << get_node_text(child, m_source_code.c_str()) << std::endl;
                        }
                    }
                    // 调试：尝试查找base_class_clause字段
                    TSNode test_node = ts_node_child_by_field_name(node, "base_class_clause", 16);
                    if (!ts_node_is_null(test_node))
                    {
                        std::cout << "Found base_class_clause via field name" << std::endl;
                    }
                    else
                    {
                        std::cout << "base_class_clause not found via field name" << std::endl;
                    }
                    ClassInfo info;
                    TSNode name_node = ts_node_child_by_field_name(node, "name", 4);
                    if (!ts_node_is_null(name_node) && ts_node_is_named(name_node))
                    {
                        info.name = get_node_text(name_node, m_source_code.c_str());
                        std::cout << "Class name: " << info.name << std::endl;
                        if (node_type == "class_specifier")
                        {
                            info.raw_name = "class " + info.name;
                            info.object_type = reflect::flag_class;
                        }
                        else if (node_type == "struct_specifier")
                        {
                            info.raw_name = "struct " + info.name;
                            info.object_type = reflect::flag_struct;
                        }
                        else if (node_type == "union_specifier")
                        {
                            info.raw_name = "union " + info.name;
                            info.object_type = reflect::flag_union;
                        }
                        info.file = "";
                        info.namespace_name = current_namespace;

                        // 提取基类
                        TSNode superclass_node;
                        bool found_base_class_clause = false;
                        // 直接查找base_class_clause子节点
                        for (uint32_t i = 0; i < ts_node_child_count(node); i++)
                        {
                            TSNode child = ts_node_child(node, i);
                            if (ts_node_is_named(child) && std::string(ts_node_type(child)) == "base_class_clause")
                            {
                                superclass_node = child;
                                std::cout << "Found base_class_clause node, type: " << ts_node_type(superclass_node) << std::endl;
                                found_base_class_clause = true;
                                break;
                            }
                        }
                        if (found_base_class_clause && ts_node_is_named(superclass_node))
                        {
                            extract_base_classes_from_node(superclass_node, info.base_classes);
                        }

                        // 提取成员
                        TSNode body_node = ts_node_child_by_field_name(node, "body", 4);
                        if (!ts_node_is_null(body_node) && ts_node_is_named(body_node))
                        {
                            std::cout << "Found body node, extracting members" << std::endl;
                            extract_members_from_node(body_node, info);
                        }
                        else
                        {
                            std::cout << "No body node found" << std::endl;
                        }

                        // 打印类的数据结构
                        std::cout << "\n=== Class Data Structure ===" << std::endl;
                        std::cout << "Class Name: " << info.name << std::endl;
                        std::cout << "Raw Name: " << info.raw_name << std::endl;
                        std::cout << "Object Type: " << info.object_type << std::endl;
                        std::cout << "Namespace: " << info.namespace_name << std::endl;
                        std::cout << "File: " << info.file << std::endl;
                        std::cout << "Base Classes: " << std::endl;
                        for (const auto &base : info.base_classes)
                        {
                            std::cout << "  - " << base.name << std::endl;
                        }
                        std::cout << "Fields: " << std::endl;
                        for (const auto &field : info.fields)
                        {
                            std::cout << "  - Name: " << field.name << std::endl;
                            std::cout << "    Type: " << field.type << std::endl;
                            std::cout << "    Access: " << field.access << std::endl;
                            std::cout << "    Static: " << (field.is_static ? "true" : "false") << std::endl;
                            std::cout << "    Const: " << (field.is_const ? "true" : "false") << std::endl;
                            std::cout << "    Volatile: " << (field.is_volatile ? "true" : "false") << std::endl;
                        }
                        std::cout << "Methods: " << std::endl;
                        for (const auto &method : info.methods)
                        {
                            std::cout << "  - Name: " << method.name << std::endl;
                            std::cout << "    Return Type: " << method.return_type << std::endl;
                            std::cout << "    Access: " << method.access << std::endl;
                            std::cout << "    Const: " << (method.is_const ? "true" : "false") << std::endl;
                            std::cout << "    Virtual: " << (method.is_virtual ? "true" : "false") << std::endl;
                            std::cout << "    Parameters: " << std::endl;
                            for (const auto &param : method.parameters)
                            {
                                std::cout << "      - " << param << std::endl;
                            }
                        }
                        std::cout << "============================" << std::endl;

                        classes.push_back(info);
                    }
                    else
                    {
                        std::cout << "Name node is null or not named" << std::endl;
                    }
                }
                else if (node_type == "namespace_definition")
                {
                    std::cout << "Found namespace definition" << std::endl;
                    // 提取命名空间名称
                    std::string namespace_name = current_namespace;
                    TSNode namespace_name_node = ts_node_child_by_field_name(node, "name", 4);
                    if (!ts_node_is_null(namespace_name_node) && ts_node_is_named(namespace_name_node))
                    {
                        std::string name = get_node_text(namespace_name_node, m_source_code.c_str());
                        std::cout << "Namespace name: " << name << std::endl;
                        if (!namespace_name.empty())
                        {
                            namespace_name += "::";
                        }
                        namespace_name += name;
                    }
                    // 递归遍历命名空间内的节点
                    for (uint32_t i = 0; i < ts_node_child_count(node); i++)
                    {
                        TSNode child = ts_node_child(node, i);
                        extract_classes_from_node(child, classes, namespace_name);
                    }
                }
                else
                {
                    // 递归遍历子节点
                    for (uint32_t i = 0; i < ts_node_child_count(node); i++)
                    {
                        TSNode child = ts_node_child(node, i);
                        extract_classes_from_node(child, classes, current_namespace);
                    }
                }
            }
        }

        void extract_base_classes_from_node(TSNode node, std::vector<BaseClassInfo> &base_classes)
        {
            try
            {
                std::string node_type = ts_node_type(node);

                if (node_type == "base_class_clause")
                {
                    // 对于base_class_clause节点，遍历子节点寻找type_identifier
                    for (uint32_t i = 0; i < ts_node_child_count(node); i++)
                    {
                        TSNode child = ts_node_child(node, i);
                        if (ts_node_is_named(child))
                        {
                            std::string child_type = ts_node_type(child);
                            if (child_type == "type_identifier" || child_type == "qualified_identifier")
                            {
                                // 直接提取type_identifier作为基类
                                BaseClassInfo base_class;
                                base_class.name = get_node_text(child, m_source_code.c_str());
                                base_class.access = "public"; // 默认访问权限
                                base_classes.push_back(base_class);
                            }
                            else if (child_type == "comma" || child_type == "colon")
                            {
                                // 跳过逗号和冒号
                                continue;
                            }
                            else if (child_type == "inheritance_specifier")
                            {
                                // 对于inheritance_specifier节点，提取类型标识符和访问权限
                                std::string access = "public"; // 默认访问权限
                                for (uint32_t j = 0; j < ts_node_child_count(child); j++)
                                {
                                    TSNode grandchild = ts_node_child(child, j);
                                    if (ts_node_is_named(grandchild))
                                    {
                                        std::string grandchild_type = ts_node_type(grandchild);
                                        if (grandchild_type == "type_identifier" || grandchild_type == "qualified_identifier")
                                        {
                                            BaseClassInfo base_class;
                                            base_class.name = get_node_text(grandchild, m_source_code.c_str());
                                            base_class.access = access;
                                            base_classes.push_back(base_class);
                                        }
                                        else if (grandchild_type == "access_specifier")
                                        {
                                            // 提取访问权限
                                            access = get_node_text(grandchild, m_source_code.c_str());
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if (node_type == "inheritance_specifier")
                {
                    // 对于inheritance_specifier节点，直接提取类型和访问权限
                    std::string access = "public"; // 默认访问权限
                    for (uint32_t i = 0; i < ts_node_child_count(node); i++)
                    {
                        TSNode child = ts_node_child(node, i);
                        if (ts_node_is_named(child))
                        {
                            std::string child_type = ts_node_type(child);
                            if (child_type == "type_identifier" || child_type == "qualified_identifier")
                            {
                                BaseClassInfo base_class;
                                base_class.name = get_node_text(child, m_source_code.c_str());
                                base_class.access = access;
                                base_classes.push_back(base_class);
                            }
                            else if (child_type == "access_specifier")
                            {
                                // 提取访问权限
                                access = get_node_text(child, m_source_code.c_str());
                            }
                            else if (child_type == "comma")
                            {
                                // 跳过逗号
                                continue;
                            }
                        }
                    }
                }
                else
                {
                    // 原有的处理逻辑
                    for (uint32_t i = 0; i < ts_node_child_count(node); i++)
                    {
                        TSNode child = ts_node_child(node, i);
                        if (ts_node_is_named(child) && std::string(ts_node_type(child)) == "superclass")
                        {
                            TSNode type_node = ts_node_child_by_field_name(child, "type", 4);
                            if (!ts_node_is_null(type_node) && ts_node_is_named(type_node))
                            {
                                BaseClassInfo base_class;
                                base_class.name = get_node_text(type_node, m_source_code.c_str());
                                base_class.access = "public"; // 默认访问权限
                                base_classes.push_back(base_class);
                            }
                        }
                    }
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error in extract_base_classes_from_node: " << e.what() << std::endl;
            }
        }

        void extract_members_from_node(TSNode node, ClassInfo &info)
        {
            try
            {
                std::string current_access = "public";

                for (uint32_t i = 0; i < ts_node_child_count(node); i++)
                {
                    TSNode child = ts_node_child(node, i);
                    if (ts_node_is_named(child))
                    {
                        std::string node_type = ts_node_type(child);

                        // 处理访问修饰符
                        if (node_type == "access_specifier")
                        {
                            std::string access = get_node_text(child, m_source_code.c_str());
                            if (access == "public:")
                                current_access = "public";
                            else if (access == "protected:")
                                current_access = "protected";
                            else if (access == "private:")
                                current_access = "private";
                        }
                        // 处理字段声明
                        else if (node_type == "field_declaration")
                        {
                            FieldInfo field;
                            TSNode type_node = ts_node_child_by_field_name(child, "type", 4);
                            TSNode declarator_node = ts_node_child_by_field_name(child, "declarator", 10);
                            if (!ts_node_is_null(type_node) && ts_node_is_named(type_node) && !ts_node_is_null(declarator_node) && ts_node_is_named(declarator_node))
                            {
                                // 检查是否有修饰符包含 const
                                bool is_const = false;

                                // 检查字段声明的所有子节点
                                for (uint32_t j = 0; j < ts_node_child_count(child); j++)
                                {
                                    TSNode child_node = ts_node_child(child, j);
                                    std::string child_text = get_node_text(child_node, m_source_code.c_str());
                                    if (child_text == "const")
                                    {
                                        is_const = true;
                                    }
                                    else if (child_text == "static")
                                    {
                                        field.is_static = true;
                                    }
                                }

                                // 检查类型节点是否包含 const 关键字
                                std::string type_text = get_node_text(type_node, m_source_code.c_str());
                                if (type_text.find("const") != std::string::npos)
                                {
                                    is_const = true;
                                }

                                // 检查类型节点的子节点
                                for (uint32_t j = 0; j < ts_node_child_count(type_node); j++)
                                {
                                    TSNode child_node = ts_node_child(type_node, j);
                                    std::string child_text = get_node_text(child_node, m_source_code.c_str());
                                    if (child_text == "const")
                                    {
                                        is_const = true;
                                    }
                                    else if (child_text == "static")
                                    {
                                        field.is_static = true;
                                    }
                                }

                                // 检查是否有修饰符包含 const 或 static
                                TSNode modifiers_node = ts_node_child_by_field_name(child, "modifiers", 9);
                                if (!ts_node_is_null(modifiers_node) && ts_node_is_named(modifiers_node))
                                {
                                    for (uint32_t j = 0; j < ts_node_child_count(modifiers_node); j++)
                                    {
                                        TSNode modifier_node = ts_node_child(modifiers_node, j);
                                        if (ts_node_is_named(modifier_node))
                                        {
                                            std::string modifier = get_node_text(modifier_node, m_source_code.c_str());
                                            if (modifier == "const")
                                            {
                                                is_const = true;
                                            }
                                            else if (modifier == "static")
                                            {
                                                field.is_static = true;
                                            }
                                        }
                                    }
                                }

                                field.type = type_text;
                                field.name = get_node_text(declarator_node, m_source_code.c_str());

                                // 检查是否是函数声明（如果字段名中包含括号，可能是函数声明）
                                if (field.name.find('(') != std::string::npos)
                                {
                                    // 处理函数声明
                                    MethodInfo method;
                                    method.return_type = type_text;

                                    // Extract just the function name without parameters
                                    size_t paren_pos = field.name.find('(');
                                    if (paren_pos != std::string::npos)
                                    {
                                        method.name = field.name.substr(0, paren_pos);
                                        // Remove any whitespace
                                        method.name.erase(0, method.name.find_first_not_of(" \t"));
                                        method.name.erase(method.name.find_last_not_of(" \t") + 1);
                                    }
                                    else
                                    {
                                        method.name = field.name;
                                    }

                                    method.access = current_access;
                                    method.is_const = false;
                                    method.is_virtual = false;

                                    // 检查是否有修饰符
                                    if (!ts_node_is_null(modifiers_node) && ts_node_is_named(modifiers_node))
                                    {
                                        for (uint32_t j = 0; j < ts_node_child_count(modifiers_node); j++)
                                        {
                                            TSNode modifier_node = ts_node_child(modifiers_node, j);
                                            if (ts_node_is_named(modifier_node))
                                            {
                                                std::string modifier = get_node_text(modifier_node, m_source_code.c_str());
                                                if (modifier == "virtual")
                                                    method.is_virtual = true;
                                                else if (modifier == "const")
                                                    method.is_const = true;
                                            }
                                        }
                                    }

                                    // 提取参数
                                    size_t param_start = field.name.find('(');
                                    size_t param_end = field.name.find(')');
                                    if (param_start != std::string::npos && param_end != std::string::npos)
                                    {
                                        std::string params_str = field.name.substr(param_start + 1, param_end - param_start - 1);
                                        // 更抽象的参数提取逻辑
                                        if (!params_str.empty() && params_str != "void")
                                        {
                                            // 分割参数
                                            size_t pos = 0;
                                            while (pos < params_str.size())
                                            {
                                                // 找到下一个逗号
                                                size_t comma_pos = params_str.find(',', pos);
                                                if (comma_pos == std::string::npos)
                                                {
                                                    comma_pos = params_str.size();
                                                }

                                                // 提取参数
                                                std::string param = params_str.substr(pos, comma_pos - pos);
                                                // 移除空格
                                                param.erase(0, param.find_first_not_of(" \t"));
                                                param.erase(param.find_last_not_of(" \t") + 1);

                                                // 提取类型 - 直接使用清理后的参数作为类型
                                                // 这样可以保留指针和引用符号
                                                method.parameters.push_back(param);

                                                pos = comma_pos + 1;
                                            }
                                        }
                                    }

                                    info.methods.push_back(method);
                                    continue;
                                }

                                // 检查 declarator_node 中是否包含 * 符号
                                if (field.name.find('*') != std::string::npos)
                                {
                                    // 如果包含 * 符号，将其添加到类型中
                                    if (field.type.find('*') == std::string::npos)
                                    {
                                        field.type += " *";
                                    }
                                    // 去掉字段名中的 * 符号
                                    size_t star_pos = field.name.find('*');
                                    field.name = field.name.substr(star_pos + 1);
                                }

                                // 检查是否需要添加 const 关键字
                                // 对于 const char * 类型，const 关键字在 modifiers 中
                                // 对于 char * const 类型，const 关键字在 declarator_node 中
                                if (is_const && field.type.find("const") == std::string::npos)
                                {
                                    field.type = "const " + field.type;
                                }

                                if (field.name.find("const") != std::string::npos)
                                {
                                    // 如果 declarator_node 中包含 const 关键字，将其添加到类型中
                                    if (field.type.find("const") == std::string::npos)
                                    {
                                        field.type += " const";
                                    }
                                    // 去掉字段名中的 const 关键字
                                    size_t const_pos = field.name.find("const");
                                    field.name = field.name.substr(const_pos + 5);
                                }

                                // 去除空格
                                field.name.erase(0, field.name.find_first_not_of(" \t"));
                                field.name.erase(field.name.find_last_not_of(" \t") + 1);
                                field.access = current_access;
                                // 不要重置 field.is_static，因为它可能已经在前面被设置为 true
                                field.is_const = is_const;
                                field.is_volatile = false;

                                // 检查是否有修饰符
                                if (!ts_node_is_null(modifiers_node) && ts_node_is_named(modifiers_node))
                                {
                                    std::cout << "Modifiers node found for field: " << field.name << std::endl;
                                    for (uint32_t j = 0; j < ts_node_child_count(modifiers_node); j++)
                                    {
                                        TSNode modifier_node = ts_node_child(modifiers_node, j);
                                        if (ts_node_is_named(modifier_node))
                                        {
                                            std::string modifier = get_node_text(modifier_node, m_source_code.c_str());
                                            std::cout << "Modifier: " << modifier << std::endl;
                                            if (modifier == "static")
                                            {
                                                field.is_static = true;
                                                std::cout << "Field " << field.name << " is static" << std::endl;
                                            }
                                            else if (modifier == "volatile")
                                                field.is_volatile = true;
                                        }
                                    }
                                }
                                else
                                {
                                    std::cout << "No modifiers node for field: " << field.name << std::endl;
                                }
                                std::cout << "Field " << field.name << " is_static: " << field.is_static << std::endl;

                                info.fields.push_back(field);
                            }
                        }
                        // 处理方法声明和定义
                        else if (node_type == "function_declaration" || node_type == "function_definition")
                        {
                            MethodInfo method;
                            TSNode return_type_node = ts_node_child_by_field_name(child, "type", 4);
                            TSNode declarator_node = ts_node_child_by_field_name(child, "declarator", 10);
                            if (!ts_node_is_null(return_type_node) && ts_node_is_named(return_type_node) && !ts_node_is_null(declarator_node) && ts_node_is_named(declarator_node))
                            {
                                method.return_type = get_node_text(return_type_node, m_source_code.c_str());

                                // Extract just the function name without parameters
                                std::string declarator_text = get_node_text(declarator_node, m_source_code.c_str());
                                size_t paren_pos = declarator_text.find('(');
                                if (paren_pos != std::string::npos)
                                {
                                    method.name = declarator_text.substr(0, paren_pos);
                                    // Remove any whitespace
                                    method.name.erase(0, method.name.find_first_not_of(" \t"));
                                    method.name.erase(method.name.find_last_not_of(" \t") + 1);
                                }
                                else
                                {
                                    method.name = declarator_text;
                                }

                                method.access = current_access;
                                method.is_const = false;
                                method.is_virtual = false;

                                // 检查是否有修饰符
                                TSNode modifiers_node = ts_node_child_by_field_name(child, "modifiers", 9);
                                if (!ts_node_is_null(modifiers_node) && ts_node_is_named(modifiers_node))
                                {
                                    for (uint32_t j = 0; j < ts_node_child_count(modifiers_node); j++)
                                    {
                                        TSNode modifier_node = ts_node_child(modifiers_node, j);
                                        if (ts_node_is_named(modifier_node))
                                        {
                                            std::string modifier = get_node_text(modifier_node, m_source_code.c_str());
                                            if (modifier == "virtual")
                                                method.is_virtual = true;
                                            else if (modifier == "const")
                                                method.is_const = true;
                                        }
                                    }
                                }

                                // 提取参数
                                TSNode parameters_node = ts_node_child_by_field_name(declarator_node, "parameters", 10);
                                if (!ts_node_is_null(parameters_node) && ts_node_is_named(parameters_node))
                                {
                                    // 直接从原始源代码中提取参数类型
                                    std::string params_text = get_node_text(parameters_node, m_source_code.c_str());

                                    // 移除括号
                                    size_t start = params_text.find('(');
                                    size_t end = params_text.rfind(')');
                                    if (start != std::string::npos && end != std::string::npos)
                                    {
                                        std::string params_str = params_text.substr(start + 1, end - start - 1);

                                        // 更抽象的参数提取逻辑
                                        if (!params_str.empty() && params_str != "void")
                                        {
                                            // 分割参数
                                            size_t pos = 0;
                                            while (pos < params_str.size())
                                            {
                                                // 找到下一个逗号
                                                size_t comma_pos = params_str.find(',', pos);
                                                if (comma_pos == std::string::npos)
                                                {
                                                    comma_pos = params_str.size();
                                                }

                                                // 提取参数
                                                std::string param = params_str.substr(pos, comma_pos - pos);
                                                // 移除空格
                                                param.erase(0, param.find_first_not_of(" \t"));
                                                param.erase(param.find_last_not_of(" \t") + 1);

                                                // 提取类型 - 从参数中提取类型部分
                                                // 找到最后一个空格
                                                size_t space_pos = param.rfind(' ');
                                                if (space_pos != std::string::npos)
                                                {
                                                    // 检查空格后面是否是指针或引用符号
                                                    std::string param_name = param.substr(space_pos + 1);
                                                    param_name.erase(0, param_name.find_first_not_of(" \t"));

                                                    // 如果参数名以*或&开头，将其添加到类型中
                                                    if (!param_name.empty())
                                                    {
                                                        size_t star_pos = param_name.find('*');
                                                        size_t amp_pos = param_name.find('&');
                                                        if (star_pos != std::string::npos || amp_pos != std::string::npos)
                                                        {
                                                            // 提取类型部分，包括指针和引用
                                                            std::string param_type = param.substr(0, space_pos);
                                                            // 移除空格
                                                            param_type.erase(0, param_type.find_first_not_of(" \t"));
                                                            param_type.erase(param_type.find_last_not_of(" \t") + 1);

                                                            if (star_pos != std::string::npos)
                                                            {
                                                                param_type += " *";
                                                            }
                                                            else if (amp_pos != std::string::npos)
                                                            {
                                                                param_type += " &";
                                                            }

                                                            method.parameters.push_back(param_type);
                                                        }
                                                        else
                                                        {
                                                            // 检查是否是 long long 这样的类型
                                                            std::string temp_param = param;
                                                            temp_param.erase(0, temp_param.find_first_not_of(" \t"));
                                                            temp_param.erase(temp_param.find_last_not_of(" \t") + 1);

                                                            // 检查是否包含多个空格，可能是 long long 这样的类型
                                                            size_t first_space_pos = temp_param.find(' ');
                                                            if (first_space_pos != std::string::npos)
                                                            {
                                                                // 尝试提取完整类型
                                                                method.parameters.push_back(temp_param);
                                                            }
                                                            else
                                                            {
                                                                // 提取类型部分
                                                                std::string param_type = param.substr(0, space_pos);
                                                                // 移除空格
                                                                param_type.erase(0, param_type.find_first_not_of(" \t"));
                                                                param_type.erase(param_type.find_last_not_of(" \t") + 1);

                                                                method.parameters.push_back(param_type);
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        // 提取类型部分
                                                        std::string param_type = param.substr(0, space_pos);
                                                        // 移除空格
                                                        param_type.erase(0, param_type.find_first_not_of(" \t"));
                                                        param_type.erase(param_type.find_last_not_of(" \t") + 1);

                                                        method.parameters.push_back(param_type);
                                                    }
                                                }
                                                else
                                                {
                                                    // 如果没有空格，整个参数就是类型
                                                    method.parameters.push_back(param);
                                                }

                                                pos = comma_pos + 1;
                                            }
                                        }
                                    }
                                }

                                info.methods.push_back(method);
                            }
                        }
                    }
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error in extract_members_from_node: " << e.what() << std::endl;
            }
        }

    private:
        void extract_classes_with_regex(std::vector<ClassInfo> &classes)
        {
            try
            {
                // 首先提取命名空间信息
                std::string current_namespace = "";
                std::regex namespace_regex("namespace\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\{");
                std::smatch namespace_match;
                std::string::const_iterator namespace_search_start = m_source_code.cbegin();

                // 提取类、结构体和联合体定义的开始部分
                std::regex class_start_regex("(class|struct|union)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?:\\s*:\\s*([^{]+))?\\s*\\{");
                std::smatch class_match;
                std::string::const_iterator class_search_start = m_source_code.cbegin();

                // 遍历所有命名空间
                while (std::regex_search(namespace_search_start, m_source_code.cend(), namespace_match, namespace_regex))
                {
                    std::string namespace_name = namespace_match[1].str();
                    size_t namespace_start = namespace_match.position(0);
                    size_t namespace_end = namespace_start + namespace_match.length(0);

                    // 查找命名空间的结束位置
                    int brace_count = 1;
                    size_t end_pos = namespace_end;
                    while (end_pos < m_source_code.size() && brace_count > 0)
                    {
                        if (m_source_code[end_pos] == '{')
                            brace_count++;
                        else if (m_source_code[end_pos] == '}')
                            brace_count--;
                        end_pos++;
                    }

                    // 在命名空间内查找类定义
                    std::string namespace_content = m_source_code.substr(namespace_start, end_pos - namespace_start);
                    std::string::const_iterator ns_class_search_start = namespace_content.cbegin();
                    while (std::regex_search(ns_class_search_start, namespace_content.cend(), class_match, class_start_regex))
                    {
                        ClassInfo info;
                        std::string type = class_match[1].str();
                        info.name = class_match[2].str();
                        info.raw_name = type + " " + info.name;
                        info.file = "";
                        info.namespace_name = namespace_name;

                        if (type == "class")
                            info.object_type = reflect::flag_class;
                        else if (type == "struct")
                            info.object_type = reflect::flag_struct;
                        else if (type == "union")
                            info.object_type = reflect::flag_union;

                        // 提取基类
                        if (class_match[3].matched)
                        {
                            std::string base_classes_str = class_match[3].str();
                            extract_base_classes_from_string(base_classes_str, info.base_classes);
                        }

                        // 查找类的结束位置
                        size_t class_start = class_match.position(0);
                        size_t class_body_start = class_start + class_match.length(0);
                        int brace_count = 1;
                        size_t class_end = class_body_start;
                        while (class_end < namespace_content.size() && brace_count > 0)
                        {
                            if (namespace_content[class_end] == '{')
                                brace_count++;
                            else if (namespace_content[class_end] == '}')
                                brace_count--;
                            class_end++;
                        }

                        // 提取成员
                        std::string body = namespace_content.substr(class_body_start, class_end - class_body_start - 1);
                        extract_members_from_string(body, info);

                        classes.push_back(info);
                        ns_class_search_start = namespace_content.cbegin() + class_end;
                    }

                    namespace_search_start = namespace_match.suffix().first;
                }

                // 查找不在命名空间中的类定义
                while (std::regex_search(class_search_start, m_source_code.cend(), class_match, class_start_regex))
                {
                    // 查找类的结束位置
                    size_t class_start = class_match.position(0);
                    size_t class_body_start = class_start + class_match.length(0);
                    int brace_count = 1;
                    size_t class_end = class_body_start;
                    while (class_end < m_source_code.size() && brace_count > 0)
                    {
                        if (m_source_code[class_end] == '{')
                            brace_count++;
                        else if (m_source_code[class_end] == '}')
                            brace_count--;
                        class_end++;
                    }

                    // 检查这个类定义是否已经在命名空间中被处理过
                    bool already_processed = false;
                    for (const auto &cls : classes)
                    {
                        if (cls.name == class_match[2].str())
                        {
                            already_processed = true;
                            break;
                        }
                    }

                    if (!already_processed)
                    {
                        ClassInfo info;
                        std::string type = class_match[1].str();
                        info.name = class_match[2].str();
                        info.raw_name = type + " " + info.name;
                        info.file = "";
                        info.namespace_name = "";

                        if (type == "class")
                            info.object_type = reflect::flag_class;
                        else if (type == "struct")
                            info.object_type = reflect::flag_struct;
                        else if (type == "union")
                            info.object_type = reflect::flag_union;

                        // 提取基类
                        if (class_match[3].matched)
                        {
                            std::string base_classes_str = class_match[3].str();
                            extract_base_classes_from_string(base_classes_str, info.base_classes);
                        }

                        // 提取成员
                        std::string body = m_source_code.substr(class_body_start, class_end - class_body_start - 1);
                        extract_members_from_string(body, info);

                        classes.push_back(info);
                    }

                    class_search_start = m_source_code.cbegin() + class_end;
                }
            }
            catch (const std::regex_error &e)
            {
                std::cerr << "Regex error in extract_classes_with_regex: " << e.what() << std::endl;
            }
        }

        void extract_base_classes_from_string(const std::string &base_str, std::vector<BaseClassInfo> &base_classes)
        {
            try
            {
                std::regex base_class_regex("((?:public|protected|private)\\s+)?([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?:,\\s*)?", std::regex::multiline);
                std::smatch match;
                std::string::const_iterator search_start = base_str.cbegin();

                while (std::regex_search(search_start, base_str.cend(), match, base_class_regex))
                {
                    if (match[2].matched)
                    {
                        BaseClassInfo base_class;
                        base_class.name = match[2].str();
                        // 提取访问权限，如果没有指定，则使用默认值
                        if (match[1].matched)
                        {
                            std::string access = match[1].str();
                            // 去除空格
                            access.erase(0, access.find_first_not_of(" \\t"));
                            access.erase(access.find_last_not_of(" \\t") + 1);
                            base_class.access = access;
                        }
                        else
                        {
                            // struct 的默认访问权限是 public
                            // class 的默认访问权限是 private
                            base_class.access = "public";
                        }
                        base_classes.push_back(base_class);
                    }
                    search_start = match.suffix().first;
                }
            }
            catch (const std::regex_error &e)
            {
                std::cerr << "Regex error in extract_base_classes_from_string: " << e.what() << std::endl;
            }
        }

        void extract_members_from_string(const std::string &body, ClassInfo &info)
        {
            try
            {
                // 根据类的类型设置默认访问权限
                // struct 的默认访问权限是 public
                // class 的默认访问权限是 private
                std::string current_access = (info.object_type == reflect::flag_struct) ? "public" : "private";
                std::istringstream ss(body);
                std::string line;

                while (std::getline(ss, line))
                {
                    // 去除空白字符
                    line = std::regex_replace(line, std::regex("^\\s+|\\s+$", std::regex::extended), "");
                    if (line.empty() || line == "" || line.substr(0, 2) == "//")
                        continue;

                    // 处理访问修饰符
                    if (line == "public:" || line == "protected:" || line == "private:")
                    {
                        current_access = line.substr(0, line.size() - 1);
                        continue;
                    }

                    // 处理字段声明
                    std::smatch field_match;
                    if (std::regex_match(line, field_match, std::regex("(?:(?:static|const|volatile)\\s+)*([a-zA-Z_][a-zA-Z0-9_:\\*&\\s]+)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?:=\\s*[^;]+)?;")))
                    {
                        FieldInfo field;
                        field.type = extract_type_name(field_match[1].str());
                        field.name = field_match[2].str();
                        field.access = current_access;
                        field.is_static = (field_match[0].str().find("static") != std::string::npos);
                        field.is_const = (field_match[0].str().find("const") != std::string::npos);
                        field.is_volatile = (field_match[0].str().find("volatile") != std::string::npos);
                        std::cout << "Field: " << field.name << ", Line: " << line << ", is_static: " << field.is_static << std::endl;
                        info.fields.push_back(field);
                    }

                    // 处理方法声明
                    std::smatch method_match;
                    if (std::regex_match(line, method_match, std::regex("(?:virtual\\s+)?([a-zA-Z_][a-zA-Z0-9_:\\*&\\s]+)\\s+([a-zA-Z_][a-zA-Z0-9_]+)\\s*\\(([^)]*)\\)\\s*(?:const)?\\s*(?:\\{[^}]*\\}|;)")))
                    {
                        MethodInfo method;
                        method.return_type = extract_type_name(method_match[1].str());
                        method.name = method_match[2].str();
                        method.access = current_access;
                        method.is_const = (method_match[0].str().find("const") != std::string::npos);
                        method.is_virtual = (method_match[0].str().find("virtual") != std::string::npos);

                        // 提取参数
                        std::string params_str = method_match[3].str();
                        std::regex param_regex("(?:[a-zA-Z_][a-zA-Z0-9_:\\*&\\s]+)\\s+[a-zA-Z_][a-zA-Z0-9_]*", std::regex::multiline);
                        std::smatch param_match;
                        std::string::const_iterator param_start = params_str.cbegin();

                        while (std::regex_search(param_start, params_str.cend(), param_match, param_regex))
                        {
                            std::string param_type = extract_type_name(param_match[0].str());
                            method.parameters.push_back(param_type);
                            param_start = param_match.suffix().first;
                        }

                        info.methods.push_back(method);
                    }
                }
            }
            catch (const std::regex_error &e)
            {
                std::cerr << "Regex error in extract_members_from_string: " << e.what() << std::endl;
            }
        }
    };

    // 查找文件路径
    std::string find_file_path(const std::string &filename)
    {
        std::string file_to_parse = filename;

        // 检查文件是否存在
        std::ifstream file_check(file_to_parse);
        if (!file_check.good())
        {
            // 提取文件名
            std::string basename = filename.substr(filename.find_last_of('/') + 1);

            // 尝试在常见目录中查找
            std::vector<std::string> search_dirs = {".", "..", "examples", "src", "include"};

            for (const auto &dir : search_dirs)
            {
                std::string candidate_path = dir + "/" + basename;
                std::ifstream candidate_check(candidate_path);
                if (candidate_check.good())
                {
                    std::cout << "File not found, trying: " << candidate_path << std::endl;
                    file_to_parse = candidate_path;
                    break;
                }
            }
        }

        return file_to_parse;
    }

    void process_class(const reflect::ClassInfo &info, const std::string &filename) {
        static int __init = reflect::format_tpl::init();
        
        ::reflect::get_config().clear();
        ::reflect::get_config().m_file = filename;
        ::reflect::get_config().m_relative_file = filename;
        ::reflect::get_config().m_class = info.name;
        ::reflect::get_config().m_raw_class = info.raw_name;
        ::reflect::get_config().m_namespace = info.namespace_name;

        auto ana_config = std::make_shared<reflect::analyzer::config_t>();
        reflect::branch_info bra;
        bra.ana().init(ana_config);

        std::map<std::string, reflect::branch_info> bra_func;
        auto ana_config_func = std::make_shared<reflect::analyzer::config_t>();
        reflect::rfl_config cfg;
        std::string __header;
        generate_file_name(cfg, __header);
        ::reflect::get_config().generated.emplace(__header);
        
        // 保存原始的 m_relative_file 值
        auto &conf = ::reflect::get_config();
        std::string original_relative_file = conf.m_relative_file;

        for (const auto &base : info.base_classes)
        {
            auto detail = std::make_shared<reflect::analyzer::info_t>();
            detail->m_variant = base.name;
            detail->m_raw_variant = base.name;
            detail->m_raw_type = base.name;
            
            // 计算基类的访问标志
            uint32_t access_flag = 0;
            if (base.access == "public")
                access_flag = reflect::flag_public;
            else if (base.access == "protected")
                access_flag = reflect::flag_protected;
            else if (base.access == "private")
                access_flag = reflect::flag_private;
            else
                access_flag = reflect::flag_member;
            
            detail->m_flags = reflect::__flags(info.object_type, access_flag, reflect::flag_member);
            bra.ana().push_back(base.name, detail);
        }

        for (const auto &field : info.fields)
        {
            auto detail = std::make_shared<reflect::analyzer::info_t>();
            detail->m_raw_variant = field.name;
            detail->m_raw_type = field.type;

            uint32_t flags = reflect::get_access_flags(field.access);
            flags |= reflect::__flag(reflect::flag_member); // Always add flag_member
            if (field.is_volatile)
                flags |= reflect::__flag(reflect::flag_volatile);
            if (field.is_static)
            {
                flags |= reflect::__flag(reflect::flag_static);
                std::cout << "Field " << field.name << " is static, flags: " << std::hex << flags << std::endl;
            }

            detail->m_flags = flags;
            std::cout << "Field " << field.name << " flags: " << std::hex << flags << std::endl;
            bra.ana().push_back(field.name, detail);

            reflect::insert_base_types(field.type);
        }

        for (const auto &method : info.methods)
        {
            if (method.name.empty() || method.name[0] == '~')
            {
                continue;
            }

            // 直接使用标志的枚举值
            uint32_t access_flag = 0;
            if (method.access == "public")
                access_flag = reflect::flag_public;
            else if (method.access == "protected")
                access_flag = reflect::flag_protected;
            else if (method.access == "private")
                access_flag = reflect::flag_private;
            else
                access_flag = reflect::flag_member;
            
            std::cout << "Method: " << method.name << ", Access: " << method.access << ", Access Flag: " << access_flag << std::endl;

            std::string method_sig = "@" + reflect::join(method.parameters, ",");
            std::string method_sig_with_return = method.return_type + method_sig;

            if (!method.return_type.empty() && method.return_type != "void")
            {
                auto detail = std::make_shared<reflect::analyzer::info_t>();
                detail->m_variant = method_sig_with_return;
                detail->m_raw_variant = method.name;
                detail->m_raw_type = method.return_type;
                detail->m_input = method.parameters;
                detail->m_output = method.return_type;
                detail->m_flags = reflect::__flags(access_flag, reflect::flag_argument, reflect::flag_member);

                bra_func[method.name].ana().init(ana_config_func).push_back(method_sig_with_return, detail);
            }

            {
                auto detail = std::make_shared<reflect::analyzer::info_t>();
                detail->m_variant = method_sig;
                detail->m_raw_variant = method.name;
                detail->m_raw_type = method.return_type;
                detail->m_input = method.parameters;
                detail->m_output = "";
                detail->m_flags = reflect::__flags(access_flag, reflect::flag_argument, reflect::flag_member);

                bra_func[method.name].ana().init(ana_config_func).push_back(method_sig, detail);
            }

            if (auto it = bra.ana().get_data().find(method.name); it == bra.ana().get_data().end())
            {
                auto detail = std::make_shared<reflect::analyzer::info_t>();
                detail->m_variant = method.name;
                detail->m_raw_variant = method.name;
                detail->m_raw_type = method.return_type;
                detail->m_flags = reflect::__flags(access_flag, reflect::flag_function, reflect::flag_member);

                bra.ana().push_back(method.name, detail);
            }
        }

        // 修复头文件路径计算问题
        // 设置 m_relative_file 为完整的文件路径，确保能正确计算头文件路径
        conf.m_relative_file = filename;
        
        std::cout << "DEBUG: process_class: " << info.name << ", bra_func size = " << bra_func.size() << std::endl;
        for (auto &_func : bra_func)
        {
            std::cout << "DEBUG: process_class: " << info.name << ", _func.first = " << _func.first << ", _func.second.ana().get_data().size() = " << _func.second.ana().get_data().size() << std::endl;
        }
        reflect::format_tpl fmt;
        fmt.to_rfl(cfg, bra, bra_func);

        ::reflect::get_config().save();
    }

    void travel_src(const std::string &filename)
    {
        try
        {
            std::cout << "\n========================================" << std::endl;
            std::cout << "Starting travel_src for file: " << filename << std::endl;
            std::cout << "========================================" << std::endl;

            // 解析并处理文件
            std::cout << "Creating Parser object" << std::endl;
            reflect::Parser parser;

            // 查找文件路径
            std::string file_to_parse = find_file_path(filename);

            std::cout << "Parsing file: " << file_to_parse << std::endl;
            if (!parser.parse_file(file_to_parse))
            {
                std::cout << "Failed to parse file" << std::endl;
                return;
            }

            std::cout << "Extracting classes" << std::endl;
            std::vector<reflect::ClassInfo> classes;
            parser.extract_classes(classes);

            // 打印提取到的类信息
            if (classes.empty())
            {
                std::cout << "No classes found in " << filename << std::endl;
            }
            else
            {
                std::cout << "Found " << classes.size() << " classes in " << filename << std::endl;
                for (const auto &cls : classes)
                {
                    std::cout << "  - " << cls.raw_name << " with " << cls.fields.size() << " fields and " << cls.methods.size() << " methods" << std::endl;
                    // 打印基类信息
                    if (!cls.base_classes.empty())
                    {
                        std::cout << "    Base classes: " << std::endl;
                        for (const auto &base : cls.base_classes)
                        {
                            std::cout << "      - " << base.name << std::endl;
                        }
                    }
                }
            }

            std::cout << "Processing classes" << std::endl;
            for (const auto &cls : classes)
            {
                std::cout << "Processing class: " << cls.raw_name << std::endl;
                process_class(cls, file_to_parse);
            }

            std::cout << "travel_src completed successfully" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error in travel_src: " << e.what() << std::endl;
        }
    }
}
