#include "branch.h"
#include <iostream>

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
        auto &_info = branch_vec[index][value];
        _info.m_layer = layer;
        _info.m_index = branch_vec[index].m_index;

        _info.m_variants.emplace(info.m_variant, &info);
        if (info.m_variant.size() > sizeof(uint64_t))
        {
            auto variant = info.m_variant.substr(sizeof(uint64_t));
            _info.m_analyzer_child.copy_view(variant, info);
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
