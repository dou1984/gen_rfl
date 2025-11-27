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

#include "branch.h"
#include "reflect.h"
#include <iostream>
#include <cassert>

namespace reflect
{
    branch_vec branch_builder(uint32_t layer, analyzer &ana)
    {
        branch_vec _branch_vec;
        uint64_t perfect_index = ana.calc_perfect_index();
        _branch_vec.resize(perfect_index);

        auto &max_index = ana.get_config()->m_max_index;
        if (layer >= max_index.size())
        {
            max_index.resize(layer + 1);
        }

        for (auto i = 0; i < _branch_vec.size(); i++)
        {
            _branch_vec[i].m_layer = layer;
            _branch_vec[i].m_index = max_index[layer]++;
        }

        for (auto &it : ana.get_data())
        {
            auto info = it.second;
            auto value = info->m_value;
            auto index = value % perfect_index;
            auto &__info = _branch_vec[index][value];
            __info.m_layer = layer;
            __info.m_index = _branch_vec[index].m_index;
            __info.m_field = info->m_field;
            __info.m_variants.emplace(info->m_variant, info);

            if (it.first.size() > sizeof(uint64_t))
            {
                auto variant = it.first.substr(sizeof(uint64_t));
                __info.m_analyzer_child.init(ana.get_config()).copy_view(variant, info);
            }
        }

        for (auto &info : _branch_vec)
        {
            for (auto &x : info)
            {
                if (x.second.m_analyzer_child.get_data().size() > 0)
                {
                    x.second.m_branch_child = branch_builder(layer + 1, x.second.m_analyzer_child);
                }
            }
        }

        return _branch_vec;
    }

    std::shared_ptr<analyzer::info_t> branch_info::first_variant() const
    {
        assert(equil_variant(m_variants.begin()->second->m_raw_variant));
        return m_variants.begin()->second;
    }
    bool branch_info::equil_variant(const std::string &variant) const
    {
        for (auto &_variant : m_variants)
        {
            if (_variant.second->m_raw_variant != variant)
            {
                return false;
            }
        }
        return true;
    }

}