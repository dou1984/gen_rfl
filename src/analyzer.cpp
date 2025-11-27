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

#ifndef MAX_PERFECT_INDEX
#define MAX_PERFECT_INDEX 1
#endif

namespace reflect
{
    analyzer::analyzer()
    {
    }

    analyzer &analyzer::init(const std::shared_ptr<config_t> &_config)
    {
        m_config = _config;
        return *this;
    }
    void analyzer::push_back_view(const std::string &variant, std::shared_ptr<info_t> &detail)
    {
        ::reflect::branch_string b(variant);
        assert(b);
        auto info = std::make_shared<info_t>();
        info->m_value = b();
        info->m_variant = variant;
        info->m_raw_variant = detail->m_raw_variant;
        info->m_raw_type = detail->m_raw_type;
        info->m_input = detail->m_input;
        info->m_output = detail->m_output;
        info->m_flags = detail->m_flags;
        info->m_t_flags = detail->m_t_flags;
        info->m_field = get_config()->m_max_field++;
        m_data.emplace(variant, info);
    }
    void analyzer::copy_view(const std::string &variant, std::shared_ptr<info_t> &detail)
    {

        ::reflect::branch_string b(variant);
        assert(b);
        auto info = std::make_shared<info_t>();
        info->m_value = b();
        info->m_variant = variant;
        info->m_raw_variant = detail->m_raw_variant;
        info->m_raw_type = detail->m_raw_type;
        info->m_input = detail->m_input;
        info->m_output = detail->m_output;
        info->m_flags = detail->m_flags;
        info->m_t_flags = detail->m_t_flags;
        info->m_field = detail->m_field;
        m_data.emplace(variant, info);
    }

    bool analyzer::get_prefect_index(int index) const
    {
        std::map<uint64_t, std::set<uint64_t>> _prefect;
        for (auto &v : m_data)
        {
            auto idx = v.second->m_value % index;
            _prefect[idx].emplace(v.second->m_value);
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
            m.emplace(v.second->m_value);
        }
        auto index = (m.size() / 5) | 1;

        while (!get_prefect_index(index))
        {
            index += 2;
        }
        return index;
    }
}