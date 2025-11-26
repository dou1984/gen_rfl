{{license}}
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
#include <gen_rfl/value.h>
{{#base_types}}
const std::string &get_type({{class}} *);{{/base_types}}{{#base_stl}}
::reflect::Value get_field_value({{class}} *cls, uint32_t field);{{/base_stl}}