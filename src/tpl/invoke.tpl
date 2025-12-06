    meta<{{class}}>& invoke__{{class}}__{{variant}}(const {{class}} *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= {{max_arguments_count}}) 
        {
            constexpr void *__meta_label[] = {{{#block}}
                &&label__{{arguments_count}},{{/block}}
            };
            goto *__meta_label[l];{{#block}}    
        label__{{arguments_count}}:{{#arguments_check}}
        {
            static std::list<Item> l = { {{arguments}} };
            if (bra == l)
            {
                return g_{{class}}_func[e__{{class}}__{{variant}}{{__field}}];
            }        
        }{{/arguments_check}}
            return g_default_meta;{{/block}}
        }
        return g_default_meta;
    }
