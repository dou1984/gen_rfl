inline ::reflect::meta<{{class}}> &rfl__{{layer}}__{{index}}(const {{class}} *cls, uint64_t value, ::reflect::branch_string &tag)
{{{#block}}
    if ({{value}} == value) // {{comment}}
    {{{#complete}}
        if (!tag) // complete
        {
            return g_{{class}}_meta[e__{{class}}__{{variant}}{{__field}}];
        }
        return g_default_meta;{{/complete}}{{#incomplete_bg_1}} // incomplete_bg_1    
        constexpr void *__meta_label[] = {{{#labels}}
            &&label__{{next_layer}}__{{next_index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;
        goto *__meta_label[index];{{#labels_bg_0}}
    label__{{next_layer}}__{{next_index}}:
        return rfl__{{next_layer}}__{{next_index}}(cls, _value, tag);{{/labels_bg_0}}{{#labels_eq_0}}
    label__{{next_layer}}__{{next_index}}:{{/labels_eq_0}}
        return g_default_meta;{{/incomplete_bg_1}}{{#incomplete_eq_1}}
        if (tag) // incomplete_eq_1
        {
            auto _value = tag();
            return rfl__{{next_layer}}__{{next_index}}(cls, _value, tag);
        }{{/incomplete_eq_1}}{{#invoke}}      
        if (!tag) // invoke
        {
            return g_{{class}}_meta[e__{{class}}__{{variant}}];
        }{{/invoke}}
    }{{/block}}
    return g_default_meta;
}
