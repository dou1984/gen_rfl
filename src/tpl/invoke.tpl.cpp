#include <string>
#include "tpl.h"

const std::string invoke_tpl = R"(
meta& invoke_{{class}}_{{variant}}(void *c, const std::string &bra)
{
    auto cls = static_cast<{{class}} *>(c);
    branch_string tag(bra);
    if (tag)
    {{{#invoke_multi}}
        constexpr void *__meta_label[] = {{{#labels}}
            &&label_{{next_index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];{{#labels}}
    label_{{next_index}}:
        return invoke_{{variant}}_{{next_layer}}_{{next_index}}(cls, _value, tag);{{/labels}}{{/invoke_multi}}{{#invoke_one}}
        auto _value = tag();
        return invoke_{{variant}}_{{next_layer}}_{{next_index}}(cls, _value, tag);{{/invoke_one}}
    }
    return g_nullptr_meta;
}
)";

const std::string invoke_field_tpl = R"(
int invoke_{{class}}_{{variant}}{{__field}}(void *c, uint64_t argc, ...)
{
    {{class}} *cls = static_cast<{{class}} *>(c);{{#has_argv}}
    if (argc == {{argc}})
    {
        va_list __argu_list;
        va_start(__argu_list, argc);{{#argv}}
        auto _a_{{index}} = va_arg(__argu_list, {{compatible_input}});{{/argv}}
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
}
)";

const std::string invoke_layer_tpl = R"(
inline meta &invoke_{{variant}}_{{layer}}_{{index}}(const {{class}} *cls, uint64_t value, branch_string &tag)
{{{#block}}
    if ({{value}} == value) // {{comment}}
    {{{#complete}}
        if (!tag)
        {
            return g_{{class}}_meta[e__{{class}}__{{variant}}{{__field}}];
        }
        return g_nullptr_meta;{{/complete}}{{#incomplete}}     
        constexpr void *__meta_label[] = {{{#labels}}
            &&label_{{next_index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];{{#labels}}
    label_{{next_index}}:
        return invoke_{{variant}}_{{next_layer}}_{{next_index}}(cls, _value, tag);{{/labels}}{{/incomplete}}{{#incomplete_one}}
        if (tag)
        {
            auto _value = tag();
            return invoke_{{variant}}_{{next_layer}}_{{next_index}}(cls, _value, tag);
        }{{/incomplete_one}}
    }{{/block}}
    return g_nullptr_meta;
}
)";

namespace tpl
{
    const std::string &invoke_field()
    {
        return invoke_field_tpl;
    }
    const std::string &invoke()
    {
        return invoke_tpl;
    }
    const std::string &invoke_layer()
    {
        return invoke_layer_tpl;
    }
}