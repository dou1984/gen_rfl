#include <string>
#include "tpl.h"

const std::string func_tpl = R"(
inline meta &rfl_L{{layer}}_I{{index}}(const {{class}} *cls, {{string}} &str, uint64_t value)
{
    {{#block}}if ({{value}} == value)
    { 
        {{#complete}}return g_{{class}}_meta[e_{{class}}_{{variant}}];{{/complete}}{{#incomplete}}return __meta(g_{{class}}_L{{next_layer}}_I{{index}}_P{{position}}, countof(g_{{class}}_L{{next_layer}}_I{{index}}_P{{position}}), cls, str);{{/incomplete}}
    }
    {{/block}}
    return g_meta;
}
)";

namespace tpl
{
    const std::string &func()
    {
        return func_tpl;
    }
}