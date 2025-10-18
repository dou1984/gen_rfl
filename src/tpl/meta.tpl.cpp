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

const std::string meta_tpl = R"({{lincense}}
#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "{{class}}.h"
#include "{{header}}"

using namespace reflect;
{{#namesp}}
namespace {{namespace}}
{{{/namesp}}
using {{class}}_func = meta<{{class}}> &(*)({{class}} *, uint64_t, branch_string &);
enum {{class}}_meta_enum
{{{#fields}}
    e__{{class}}__{{variant}}{{__field}},{{/fields}}
    e__{{class}}__end,
};
enum {{class}}_func_enum
{{{#invoke_fields}}
    e__{{class}}__{{variant}}{{__field}},{{/invoke_fields}}
    e__{{class}}__func__end,
};
static meta<{{class}}> g_default_meta = {
    .m_variant = "",
    .m_type = "",
    .m_flags = __flags(flag_none),
    .m_field = UINT32_MAX,
    .m_member = [](const {{class}} *c) -> const void* { return nullptr; },
};
static meta<{{class}}> g_{{class}} = {
    .m_variant = "{{class}}",
    .m_type = "{{class}}",
    .m_flags = __flags(flag_none),
    .m_field = UINT32_MAX,
    .m_member = [](const {{class}} *c) -> const void* { return nullptr; },
};
{{#invoke_fields}}
int invoke_{{class}}_{{variant}}{{__field}}(const {{class}}* c, uint64_t argc, ...);{{/invoke_fields}}
static meta<{{class}}> g_{{class}}_func[] = 
{{{#invoke_fields}}
    {
        .m_variant = "{{variant}}",
        .m_type = "{{type}}",
        .m_flags = {{flags}},
        .m_field = e__{{class}}__{{variant}}{{__field}}, // {{field}}{{#invoke_field}}
        .m_func = invoke_{{class}}_{{variant}}{{__field}},{{/invoke_field}}
    },{{/invoke_fields}}
};
{{#invoke_func}}
meta<{{class}}>& invoke_{{class}}_{{variant}}(const {{class}} *c, const std::string &tag);{{/invoke_func}}
static meta<{{class}}> g_{{class}}_meta[] = {{{#fields}}
    {
        .m_variant = "{{variant}}",
        .m_type = "{{type}}",
        .m_flags = {{flags}},
        .m_field = e__{{class}}__{{variant}}{{__field}}, // {{field}}{{#is_invoke}}
        .m_invoke = invoke_{{class}}_{{variant}},{{/is_invoke}}{{#is_member}}
        .m_member = [](const {{class}} *c) -> const void * 
        {        
            auto cls = static_cast<const {{class}} *>(c);{{#is_field}}
            return std::addressof(cls->{{variant}});{{/is_field}}{{#is_static}}
            return std::addressof(cls->{{variant}});{{/is_static}}{{#is_derived}}
            return ({{variant}} *)(cls);{{/is_derived}}
        },{{/is_member}}
    },{{/fields}}
};

)";

namespace tpl
{
    const std::string &meta()
    {
        return meta_tpl;
    }
}