#include <string>
#include "tpl.h"

const std::string base_types_tpl = R"(
#pragma once
#include <stdint.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <array>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
{{#base_types}}
const char *get_type({{class}} *);{{/base_types}}{{#base_stl}}
void* get_field_value({{class}} *cls, uint64_t field);{{/base_stl}}

)";
const std::string base_types_source_tpl = R"(
#include "base_types.h"

{{#base_types}}
const char *get_type({{class}} *)
{
    return "{{raw_class}}";
}{{/base_types}}{{#base_stl}}
void* get_field_value({{class}} *cls, uint64_t field)
{
    if (field < cls->size())
    {
        return cls->at(field);
    }
    return nullptr;
}{{/base_stl}}

)";
namespace tpl
{
    const std::string &base_types()
    {
        return base_types_tpl;
    }
    const std::string &base_types_source()
    {
        return base_types_source_tpl;
    }
}