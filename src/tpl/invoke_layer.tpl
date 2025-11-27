inline ::reflect::meta<{{class}}> &invoke__{{variant}}__{{layer}}__{{index}}(const {{class}} *c, uint64_t value, ::reflect::branch_string &tag)
{{{#block}}
    if ({{value}} == value) // {{comment}}
    {{{#complete}}
        if (!tag)
        {
            return g_{{class}}_func[e__{{class}}__{{variant}}{{__field}}];
        }
        return g_default_meta;{{/complete}}{{#incomplete_bg_1}}     
        constexpr void *__meta_label[] = {{{#labels}}
            &&label__{{next_layer}}__{{next_index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];{{#labels}}
    label_{{next_layer}}_{{next_index}}:
        return invoke__{{variant}}__{{next_layer}}__{{next_index}}(c, _value, tag);{{/labels}}{{/incomplete_bg_1}}{{#incomplete_eq_1}}
        if (tag)
        {
            auto _value = tag();
            return invoke__{{variant}}__{{next_layer}}__{{next_index}}(c, _value, tag);
        }{{/incomplete_eq_1}}
    }{{/block}}
    return g_default_meta;
}
