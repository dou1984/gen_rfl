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

#include <string>
#include "tpl.h"

const std::string base_types_tpl = R"({{license}}
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
void* get_field_value({{class}} *cls, uint32_t field);{{/base_stl}}

)";
const std::string base_types_source_tpl = R"({{license}}
#include "base_types.h"

{{#base_types}}
const char *get_type({{class}} *)
{
    return "{{raw_class}}";
}{{/base_types}}{{#base_stl}}
void* get_field_value({{class}} *cls, uint32_t field)
{
    if (field < cls->size())
    {
        return &cls->at(field);
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