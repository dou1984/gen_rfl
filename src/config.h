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

struct Data
{
    std::map<std::string, std::chrono::system_clock::time_point> generate_header;
    std::set<std::string> generated;
    std::set<std::string> base_types;
};
struct Global
{
    std::string m_file;
    std::string m_relative_file;
    std::string m_class;
    std::string m_raw_class;
    std::string m_namespace;

    void clear()
    {
        m_file.clear();
        m_relative_file.clear();
        m_raw_class.clear();
        m_class.clear();
        m_namespace.clear();
    }
};

struct Conf : Data, Global
{
    std::string include_dir;
    std::string libs_dir;
    std::string src_dir;
    std::string tmp_dir;
    std::string real_tmp_dir_loc;
    std::string cwd;
    std::string cmake_pattern;
    std::string source_pattern;

    std::vector<std::string> llvm_args;
};

Conf &get_config();

int read_config_from_yaml(const std::string &json_file);

int write_default_to_yaml(const std::string &json_file);