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

#pragma once
#include <string>
#include <map>
#include <set>
#include <chrono>
#include <vector>
#include "config_src.h"

namespace reflect
{
    struct Data
    {
        std::map<std::string, std::chrono::system_clock::time_point> generate_header;
        std::set<std::string> generated;
        std::set<std::string> base_types;
        std::set<std::string> referenced_headers;
        // 保存原始头文件的绝对路径，用于在to_rfl()中计算正确的相对路径
        std::set<std::string> referenced_headers_absolute;
    };
    
    // 保存referenced_headers到文件
    void save_referenced_headers();
    
    // 从文件加载referenced_headers
    void load_referenced_headers();

    struct Conf : Data, SourceInfo
    {
        std::string include_dir;
        std::string libs_dir;
        std::string tpl_dir;
        std::string src_dir;
        std::string rfl_dir;
        std::string real_source_dir;
        std::string cwd;
        std::string cmake_pattern;
        std::string source_pattern;

        SourceFiles source_code;

        void save()
        {
            SourceInfo *_this = static_cast<SourceInfo *>(this);
            source_code.set(std::move(*_this));
        }
    };

    Conf &get_config();

    int read_config_from_yaml(const std::string &json_file);

    int write_default_to_yaml(const std::string &json_file);

    void insert_base_types(const std::string &type);
}