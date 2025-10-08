// Copyright (c) 2023-2025 ZhaoYunshan
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
using {{class}}_func = meta &(*)(const {{class}} *, uint64_t, branch_string &);
enum {{class}}_meta_enum
{{{#fields}}
    e__{{class}}__{{variant}}{{__field}},{{/fields}}
    e__{{class}}__end,
};
static meta g_nullptr_meta = {
    .m_variant = "",
    .m_type = "",
    .m_flags = __flags(flag_none),
    .m_field = UINT64_MAX,
    .m_offset = UINT64_MAX,
};
static meta g_{{class}} = {
    .m_variant = "{{class}}",
    .m_type = "{{class}}",
    .m_flags = __flags(flag_none),
    .m_field = UINT64_MAX,
    .m_offset = UINT64_MAX,    
};
{{#fields}}{{#invoke_field}}
int invoke_{{class}}_{{variant}}{{__field}}(void *c, uint64_t argc, ...);{{/invoke_field}}{{#is_invoke}}
meta& invoke_{{class}}_{{variant}}(void *c, const std::string &tag);{{/is_invoke}}{{/fields}}
static meta g_{{class}}_meta[] = {
{{#fields}}
    {
        .m_variant = "{{variant}}",
        .m_type = "{{type}}",
        .m_flags = {{flags}},
        .m_field = e__{{class}}__{{variant}}{{__field}}, // {{field}}{{#is_field}}       
        .m_offset = to_offset(&{{class}}::{{variant}}),{{/is_field}}{{#is_derived}}
        .m_offset = to_offset<{{class}}, {{variant}}>(),{{/is_derived}}{{#is_static}}
        .m_ptr = (&{{class}}::{{variant}}),{{/is_static}}{{#is_invoke}}
        .m_invoke = invoke_{{class}}_{{variant}},{{/is_invoke}}{{#invoke_field}}
        .m_func = invoke_{{class}}_{{variant}}{{__field}},{{/invoke_field}}
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