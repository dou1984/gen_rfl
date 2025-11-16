// Copyright (c) 2023-2025 Zhao Yun Shan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include <string>
#include "tpl.h"

const std::string invoke_tpl = R"(
::reflect::meta<{{class}}>& invoke__{{class}}__{{variant}}(const {{class}} *c, const std::string &bra)
{
    branch_string tag(bra);
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
)";

const std::string invoke_field_tpl = R"(
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
)";

const std::string invoke_layer_tpl = R"(
inline ::reflect::meta<{{class}}> &invoke__{{variant}}__{{layer}}__{{index}}(const {{class}} *c, uint64_t value, branch_string &tag)
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