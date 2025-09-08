#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string_view>
#include "analyzer.h"
#include "branch_string.h"

struct branch_info;
struct branch_map : std::map<uint64_t, branch_info>
{
    uint32_t m_layer = 0;
    uint32_t m_index = 0;
};

using branch = std::vector<branch_map>;
struct branch_details
{
    uint64_t m_value = 0;
    uint64_t m_field = 0;
    std::string m_raw_variant;
};
struct branch_info
{
    uint32_t m_layer = 0;
    uint32_t m_index = 0;
    std::map<std::string, branch_details> m_variants;

    // children
    analyzer m_analyzer_child;
    branch m_branch_child;
};

branch branch_builder(uint32_t, analyzer &);

