#include <string>
#include "tpl.h"

const std::string meta_tpl = R"(
{{lincense}}
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
{
    {{#fields}}
    e_{{class}}_{{variant}},{{/fields}}
    e_{{class}}_end,
};
static meta g_meta = {
    .m_variant = "",
    .m_type = "",
    .m_raw_type = "",
    .m_flags = __flags(flag_none),
    .m_field = UINT64_MAX,
    .m_offset = UINT64_MAX,
};
static meta g_{{class}} = {
    .m_variant = "{{class}}",
    .m_type = "{{class}}",
    .m_raw_type = "{{class}}",
    .m_flags = __flags(flag_none),
    .m_field = UINT64_MAX,
    .m_offset = UINT64_MAX,    
};
{{#is_invoke}}
static int g_{{class}}_{{variant}}(void *c, uint64_t argc, const std::string &func_args, ...)
{
    auto cls = static_cast<{{class}} *>(c);{{#has_argv}}
    if (argc == {{argc}})
    {     
        va_list __argu_list;
        va_start(__argu_list, func_args);{{#argv}}
        auto _t_{{index}} = va_arg(__argu_list, const char *);
        if (strcmp(_t_{{index}}, "{{input}}") != 0)
        {
            return -1;
        }{{/argv}}{{#argv}}
        auto _a_{{index}} = va_arg(__argu_list, {{input}});{{/argv}}  
        va_end(__argu_list);  
        cls->{{variant}}({{#argv}}_a_{{index}}{{comma}}{{/argv}});     
        return 0;  
    }{{/has_argv}}{{#no_argv}}
    if (argc == {{argc}})
    {
        cls->{{variant}}();
        return 0;
    }{{/no_argv}}
    return -1;
}{{/is_invoke}}
static meta g_{{class}}_meta[] = {
{{#fields}}
    {
        .m_variant = "{{variant}}",
        .m_type = "{{type}}",
        .m_raw_type = "{{raw_type}}",
        .m_flags = {{flags}},
        .m_field = e_{{class}}_{{variant}},{{#is_field}}
        .m_offset = to_offset(&{{class}}::{{variant}}),{{/is_field}}{{#is_derived}}
        .m_offset = to_offset<{{class}}, {{variant}}>(),{{/is_derived}}{{#is_static}}
        .m_ptr = (&{{class}}::{{variant}}),{{/is_static}}{{#is_func}}
        .m_func = g_{{class}}_{{variant}},{{/is_func}}
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