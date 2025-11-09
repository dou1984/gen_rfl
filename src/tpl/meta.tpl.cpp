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

const std::string meta_tpl = R"({{license}}
#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>{{#is_base}}
#include "{{variant}}.h"{{/is_base}}
#include "{{class}}.h"
#include "{{header}}"
#include <gen_rfl/setter.h>

using namespace reflect;
{{#namesp}}
namespace {{namespace}}
{{{/namesp}}
enum {{class}}_meta_enum
{{{#fields}}
    e__{{class}}__{{variant}},{{/fields}}
    e__{{class}}__end,
};
enum {{class}}_func_enum
{{{#invoke_fields}}
    e__{{class}}__{{variant}}{{__field}},{{/invoke_fields}}
    e__{{class}}__func__end,
};
static int set_value_invalid({{class}} *cls, uint32_t, ...)
{
    return 0;
}
static meta<{{class}}> g_default_meta = {
    .m_variant = "",
    .m_type = "",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const {{class}} *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};
static meta<{{class}}> g_{{class}} = {
    .m_variant = "{{class}}",
    .m_type = "{{type}}",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const {{class}} *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};
{{#invoke_fields}}
int invoke__{{class}}__{{variant}}{{__field}}(const {{class}}* c, uint64_t argc, ...);{{/invoke_fields}}
static meta<{{class}}> g_{{class}}_func[] = 
{{{#invoke_fields}}
    {
        .m_variant = "{{variant}}",
        .m_type = "{{type}}",
        .m_flags = {{flags}},
        .m_t_flags = 0,
        .m_field = e__{{class}}__{{variant}}{{__field}}, // {{field}}{{#invoke_field}}
        .m_func = invoke__{{class}}__{{variant}}{{__field}},{{/invoke_field}}
        .m_setter = set_value_invalid,
    },{{/invoke_fields}}
};
{{#invoke_func}}
meta<{{class}}>& invoke__{{class}}__{{variant}}(const {{class}} *c, const std::string &tag);{{/invoke_func}}
static meta<{{class}}> g_{{class}}_meta[] = {{{#fields}}
    {
        .m_variant = "{{variant}}",
        .m_type = "{{type}}",
        .m_flags = {{flags}},
        .m_t_flags = {{t_flags}},
        .m_field = e__{{class}}__{{variant}}, // {{field}}{{#is_invoke}}
        .m_invoke = invoke__{{class}}__{{variant}},
        .m_setter = set_value_invalid,{{/is_invoke}}{{#is_member}}
        .m_getter = [](const {{class}} *cls) -> void * 
        {{{#is_field}}
            return (void *)std::addressof(cls->{{variant}});{{/is_field}}{{#is_static}}
            return (void *)std::addressof(cls->{{variant}});{{/is_static}}{{#is_derived}}
            return (void *)static_cast<const {{variant}} *>(cls);{{/is_derived}}
        },{{#is_field}}
        .m_setter = []() -> auto
        { return __setter__<{{class}}, __ref_member__<{{class}}, &{{class}}::{{variant}}>>; }(),{{/is_field}}{{#is_static}}
        .m_setter = []() -> auto
        { return __setter__<{{class}}, __ref_static__<{{class}}, &{{class}}::{{variant}}>>; }(),{{/is_static}}{{#is_derived}}
        .m_setter = []() -> auto
        { return __setter__<{{class}}, __ref_base__<{{class}}, {{variant}}>>; }(),{{/is_derived}}{{/is_member}}
    },{{/fields}}
};
reflect::Value __get_value(const {{class}}* cls, const std::string& _tag)
{{{#is_base}} 
    {
        branch_string tag(_tag);
        auto _meta = __details__::get_meta(static_cast<const {{variant}} *>(cls), tag);
        if (__contains__(_meta.m_flags, flag_member))
        {
            return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);   
        }
    }{{/is_base}}
    return reflect::Value(nullptr, 0);
}
)";

namespace tpl
{
    const std::string &meta()
    {
        return meta_tpl;
    }
}