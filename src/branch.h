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
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string_view>
#include <cassert>
#include <memory>
#include "analyzer.h"
#include "branch_string.h"

namespace reflect
{
    struct branch_info;
    struct branch_map : std::map<uint64_t, branch_info>
    {
        uint32_t m_layer = 0;
        uint32_t m_index = 0;
    };
    struct branch_vec : std::vector<branch_map>
    {
    };
    struct branch_info
    {
        uint32_t m_layer = 0;
        uint32_t m_index = 0;
        uint32_t m_field = 0;
        std::multimap<std::string, std::shared_ptr<analyzer::info_t>> m_variants;

        // children
        analyzer m_analyzer_child;
        branch_vec m_branch_child;

        std::shared_ptr<analyzer::info_t> first_variant() const;
        bool equil_variant(const std::string &variant) const;
    };

    branch_vec branch_builder(uint32_t, analyzer &);

}