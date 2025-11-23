::reflect::meta<{{class}}>& invoke__{{class}}__{{variant}}(const {{class}} *c, const std::string &bra)
{
    ::reflect::branch_string tag(bra);
    if (tag)
    {{{#invoke_bg_1}}
        constexpr void *__meta_label[] = {{{#labels}}
            &&label_{{next_index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];{{#labels_bg_0}}
    label_{{next_index}}:
        return invoke__{{variant}}__{{next_layer}}__{{next_index}}(c, _value, tag);{{/labels_bg_0}}{{#labels_eq_0}}
    label_{{next_index}}:{{/labels_eq_0}}
        return g_default_meta;{{/invoke_bg_1}}{{#invoke_eq_1}}
        auto _value = tag();
        return invoke__{{variant}}__{{next_layer}}__{{next_index}}(c, _value, tag);{{/invoke_eq_1}}
    }
    return g_default_meta;
}