// Copyright (c) 2023-2025 ZhaoYunshan
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

#include <cstdint>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include <regex>
#include "config.h"
#include "analyzer.h"
#include "sys.h"
#include "branch_string.h"

analyzer::config_t analyzer::m_config = {};

#ifndef MAX_PERFECT_INDEX
#define MAX_PERFECT_INDEX 1
#endif
analyzer::analyzer()
{
}

void analyzer::push_back_view(const std::string &variant, const info_t &detail)
{
    branch_string b(variant);
    assert(b);
    info_t info;
    info.m_value = b();
    info.m_variant = variant;
    info.m_raw_variant = detail.m_raw_variant;
    info.m_raw_type = detail.m_raw_type;
    info.m_input = detail.m_input;
    info.m_output = detail.m_output;
    info.m_flags = detail.m_flags;
    info.m_field = get_config().m_max_field++;
    m_data.emplace(variant, std::move(info));
}
void analyzer::copy_view(const std::string &variant, const info_t &detail)
{

    branch_string b(variant);
    assert(b);
    info_t info;
    info.m_value = b();
    info.m_variant = variant;
    info.m_raw_variant = detail.m_raw_variant;
    info.m_raw_type = detail.m_raw_type;
    info.m_input = detail.m_input;
    info.m_output = detail.m_output;
    info.m_flags = detail.m_flags;
    info.m_field = detail.m_field;
    m_data.emplace(variant, std::move(info));
}

bool analyzer::get_prefect_index(int index) const
{
    std::map<uint64_t, std::set<uint64_t>> _prefect;
    for (auto &v : m_data)
    {
        auto idx = v.second.m_value % index;
        _prefect[idx].emplace(v.second.m_value);
        if (_prefect[idx].size() > MAX_PERFECT_INDEX)
        {
            return false;
        }
    }
    return true;
}
uint64_t analyzer::calc_perfect_index() const
{
    std::set<uint64_t> m;
    for (auto &v : m_data)
    {
        m.emplace(v.second.m_value);
    }
    auto index = (m.size() / 3) | 1;

    while (!get_prefect_index(index))
    {
        index += 2;
    }
    return index;
}

int analyzer::generate_file_name(std::string &header, std::string &source, std::string &_header)
{
    auto &conf = ::get_config();

    auto fname = get_config().m_file;
    auto _class = get_config().m_class;

    assert(fname.size() > 0);
    assert(fname.back() != '/');
    if (fname.find(conf.cwd) == 0)
    {
        fname = fname.substr(conf.cwd.size());
    }
    // std::cout << "generate_file_name from " << fname << std::endl;
    get_config().m_relative_file = fname;

    std::regex suffix(R"(\.(h|hpp|c|cc|cxx|c++|cpp)$)");
    fname = std::regex_replace(fname, suffix, "_rfl");

    auto path = conf.tmp_dir + "/" + fname;
    MkDir(path);

    header = path + "/" + _class + ".h";
    source = path + "/" + _class + ".cpp";
    _header = fname + "/" + _class + ".h";

    return 0;
}
bool analyzer::is_generated(std::string &header, std::string &source)
{
    std::string __header;
    auto r = generate_file_name(header, source, __header);
    if (r != 0)
    {
        std::cerr << "generate_file_name error" << std::endl;
        return false;
    }

    auto &conf = ::get_config();
    conf.generated.emplace(__header);

    auto key_file = m_config.m_file + ":" + header;
    auto it = conf.generate_header.find(key_file);
    if (it == conf.generate_header.end())
    {
        auto modified_time = GetFileModified(m_config.m_file);
        conf.generate_header.emplace(key_file, modified_time);
        return false;
    }
    auto modified_time = GetFileModified(m_config.m_file);
    if (modified_time > it->second)
    {
        std::cerr << "file " << m_config.m_file << "header " << header << std::endl;
        conf.generate_header.emplace(key_file, modified_time);
        return false;
    }
    return true;
}
