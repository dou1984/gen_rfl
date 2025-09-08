#include <string>
#include "tpl.h"

const std::string meta_tpl = R"(
#include <stdint.h>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "{{header}}"

using namespace reflect;
using {{class}}_func = meta &(*)(const {{class}} *, {{string}} &, uint64_t);

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
static meta g_{{class}}_meta[] = {
{{#fields}}
    {
        .m_variant = "{{variant}}",
        .m_type = "{{type}}",
        .m_raw_type = "{{raw_type}}",
        .m_flags = {{flags}},
        .m_field = e_{{class}}_{{variant}},
        {{#is_field}}.m_offset = _offsetof(&{{class}}::{{variant}}),{{/is_field}}{{#is_derived}}.m_offset = _offsetof<{{class}}, {{variant}}>(),{{/is_derived}}        
    },{{/fields}}
};

inline meta &__meta({{class}}_func *arr, int count, const {{class}} *cls, branch_string& b)
{  
    if (b)
    {
        auto value = b();
        auto index = value % count;
        return (arr[index])(cls, b, value);
    }
    return g_meta;
}
)";

namespace tpl
{
    const std::string &meta()
    {
        return meta_tpl;
    }
}