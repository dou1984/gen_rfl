int invoke__{{class}}__{{variant}}{{__field}}(const {{class}} *c, const reflect::Arguments* argu, ...)
{
    auto *cls = ({{class}} *)(c);{{#has_argv}} 
    if (cls && argu->m_count == {{argc}})
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);{{#ret}}
        auto& _r = *(va_arg(__arguments_list, {{compatible_output}} *));{{/ret}}{{#argv}}
        auto& _a_{{index}} = *(va_arg(__arguments_list, {{compatible_input}} *));{{/argv}}
        va_end(__arguments_list);
        {{#ret}}_r = {{/ret}}cls->{{variant}}({{#argv}}_a_{{index}}{{comma}}{{/argv}});
        return 0;
    }{{/has_argv}}
    return -1;
}