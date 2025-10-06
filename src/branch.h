#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string_view>
#include <cassert>
#include "analyzer.h"
#include "branch_string.h"

struct branch_info;
struct branch_map : std::map<uint64_t, branch_info>
{
    uint32_t m_layer = 0;
    uint32_t m_index = 0;
};

using branch = std::vector<branch_map>;
struct branch_info
{
    uint32_t m_layer = 0;
    uint32_t m_index = 0;
    uint32_t m_field = 0;
    std::multimap<std::string, analyzer::info_t *> m_variants;

    // children
    analyzer m_analyzer_child;
    branch m_branch_child;

    auto first() const
    {
        assert(m_variants.size() == 1);
        return m_variants.begin()->second;
    }
};

branch branch_builder(uint32_t, analyzer &);
