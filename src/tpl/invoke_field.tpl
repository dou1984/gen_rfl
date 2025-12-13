    int invoke__{{class}}__{{variant}}{{__field}}_v({{class}} *cls, const Arguments* argu, va_list& __arguments_list)
    {{{#has_argv}}{{#return}}
        auto& _r = *(va_arg(__arguments_list, {{compatible_output}} *));{{/return}}{{#argv}}
        auto& _a_{{index}} = *(va_arg(__arguments_list, {{compatible_input}} *));{{/argv}}
        {{#return}}_r = {{/return}}cls->{{variant}}({{#argv}}_a_{{index}}{{comma}}{{/argv}});{{/has_argv}}
        return 0;
    }
    int invoke__{{class}}__{{variant}}{{__field}}(const {{class}} *c, const Arguments* argu, ...)
    {
        auto *cls = ({{class}} *)(c);{{#has_argv}} 
        if (cls && argu->m_arguments.size() == {{argc}})
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__{{class}}__{{variant}}{{__field}}_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }{{/has_argv}}
        return -1;
    }
