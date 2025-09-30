#include <string>
#include "tpl.h"

const std::string func_tpl = R"(
inline meta &rfl_{{layer}}_{{index}}(const {{class}} *cls, uint64_t value, branch_string &tag)
{{{#block}}
    if ({{value}} == value)
    {{{#complete}}
        return tag ? g_meta : g_{{class}}_meta[e_{{class}}_{{variant}}];{{/complete}}{{#incomplete}}        
        constexpr void *__meta_label[] = {{{#labels}}
            &&label_{{next_index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];{{#labels}}
    label_{{next_index}}:
        return rfl_{{next_layer}}_{{next_index}}(cls, _value, tag);{{/labels}}{{/incomplete}}{{#incomplete_one}}
        if (tag)
        {
            auto _value = tag();
            return rfl_{{next_layer}}_{{next_index}}(cls, _value, tag);
        }{{/incomplete_one}}
    }{{/block}}
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
