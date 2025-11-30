::reflect::meta<{{class}}>& invoke__{{class}}__{{variant}}(const {{class}} *c, const std::list<std::string> &bra)
{{{#block}}
    if (bra.size() == {{arguments_count}})
    {{{#arguments_check}}
        {
            static std::list<std::string> l = { {{arguments}} };
            if (bra == l)
            {
                return g_{{class}}_func[e__{{class}}__{{variant}}{{__field}}];
            }
        }{{/arguments_check}}
        return g_default_meta;
    }{{/block}}
    return g_default_meta;
}
