#include "branch.h"
#include "reflect.h"
#include <iostream>
#include <cassert>

using namespace reflect;
branch branch_builder(uint32_t layer, analyzer &ana)
{
    branch branch_vec;
    uint64_t perfect_index = ana.calc_perfect_index();
    branch_vec.resize(perfect_index);

    auto &max_index = analyzer::get_config().m_max_index;
    if (layer >= max_index.size())
    {
        max_index.resize(layer + 1);
    }

    for (auto i = 0; i < branch_vec.size(); i++)
    {
        branch_vec[i].m_layer = layer;
        branch_vec[i].m_index = max_index[layer]++;
    }

    for (auto &it : ana.get_data())
    {
        auto &info = it.second;
        auto value = info.m_value;
        auto index = value % perfect_index;
        auto &__info = branch_vec[index][value];
        __info.m_layer = layer;
        __info.m_index = branch_vec[index].m_index;
        __info.m_field = info.m_field;
        __info.m_variants.emplace(info.m_variant, &info);

        if (it.first.size() > sizeof(uint64_t))
        {
            auto variant = it.first.substr(sizeof(uint64_t));
            __info.m_analyzer_child.copy_view(variant, info);
        }
        else if (__has_flag(info.m_flags, flag_argument) && !__has_flag(info.m_flags, flag_next))
        {
            auto variant = info.m_raw_type;
            analyzer::info_t args_info = {
                .m_variant = info.m_variant,
                .m_raw_variant = info.m_raw_variant,
                .m_type = info.m_type,
                .m_raw_type = info.m_raw_type,
                .m_input = info.m_input,
                .m_flags = info.m_flags | __flag(flag_next),
                .m_field = info.m_field,
            };
            __info.m_analyzer_child.copy_view(variant, args_info);
        }
    }

    for (auto &info : branch_vec)
    {
        for (auto &x : info)
        {
            if (x.second.m_analyzer_child.get_data().size() > 0)
            {
                x.second.m_branch_child = branch_builder(layer + 1, x.second.m_analyzer_child);
            }
        }
    }

    return branch_vec;
}

analyzer::info_t *branch_info::first_variant() const
{
    assert(count_variant(flag_function) == 1 || count_variant(flag_argument) == 1);
    return m_variants.begin()->second;
}
int branch_info::count_variant(int flag) const
{
    int count = 0;
    for (auto &variant : m_variants)
    {
        if (__has_flag(variant.second->m_flags, flag))
        {
            count++;
        }
    }
    return count;
}