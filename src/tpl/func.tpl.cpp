#include <string>
#include "tpl.h"

const std::string func_tpl = R"(
inline meta &rfl_{{layer}}_{{index}}(const {{class}} *cls, uint64_t value, branch_string &tag)
{{{#block}}
    if ({{value}} == value) // {{comment}}
    {{{#complete}}
        if (!tag) // complete
        {
            return g_{{class}}_meta[e__{{class}}__{{variant}}{{__field}}];
        }
        return g_nullptr_meta;{{/complete}}{{#incomplete}} // incomplete    
        constexpr void *__meta_label[] = {{{#labels}}
            &&label_{{next_index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];{{#labels}}
    label_{{next_index}}:
        return rfl_{{next_layer}}_{{next_index}}(cls, _value, tag);{{/labels}}{{/incomplete}}{{#incomplete_one}}
        if (tag) // incomplete one
        {
            auto _value = tag();
            return rfl_{{next_layer}}_{{next_index}}(cls, _value, tag);
        }
        return g_nullptr_meta;{{/incomplete_one}}{{#invoke}}      
        if (!tag) // invoke
        {
            return g_{{class}}_meta[e__{{class}}__{{variant}}];
        }{{/invoke}}
    }{{/block}}
    return g_nullptr_meta;
}
)";

namespace tpl
{
    const std::string &func()
    {
        return func_tpl;
    }

}
