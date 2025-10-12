// Copyright (c) 2023-2025 ZhaoYunshan
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
meta& invoke_{{class}}_{{variant}}(void *c, const std::string &bra)
{
    auto cls = static_cast<{{class}} *>(c);
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
        return invoke_{{variant}}_{{next_layer}}_{{next_index}}(cls, _value, tag);{{/labels_bg_0}}{{#labels_eq_0}}
    label_{{next_index}}:
        return g_default_meta;{{/labels_eq_0}}{{/invoke_bg_1}}{{#invoke_eq_1}}
        auto _value = tag();
        return invoke_{{variant}}_{{next_layer}}_{{next_index}}(cls, _value, tag);{{/invoke_eq_1}}
    }
    return g_default_meta;
}
)";

const std::string invoke_field_tpl = R"(
int invoke_{{class}}_{{variant}}{{__field}}(void *c, uint64_t argc, ...)
{
    {{class}} *cls = static_cast<{{class}} *>(c);{{#has_argv}}
    if (argc == {{argc}})
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);{{#argv}}
        auto _a_{{index}} = va_arg(__arguments_list, {{compatible_input}});{{/argv}}{{#argv_ref}}
        auto& _a_{{index}} = *(va_arg(__arguments_list, {{compatible_input}}*));{{/argv_ref}}
        va_end(__arguments_list);
        cls->{{variant}}({{#argv}}_a_{{index}}{{comma}}{{/argv}}{{#argv_ref}}_a_{{index}}{{comma}}{{/argv_ref}});
        return 0;
    }
    if (argc == {{argc}} + 1)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);{{#ret}}
        auto _r = va_arg(__arguments_list, {{compatible_output}});{{/ret}}{{#ret_ref}}
        auto& _r = *(va_arg(__arguments_list, {{compatible_output}}*));{{/ret_ref}}{{#argv}}
        auto _a_{{index}} = va_arg(__arguments_list, {{compatible_input}});{{/argv}}{{#argv_ref}}
        auto& _a_{{index}} = *(va_arg(__arguments_list, {{compatible_input}}*));{{/argv_ref}}
        va_end(__arguments_list);
        {{#ret}}_r = {{/ret}}{{#ret_ref}}_r = {{/ret_ref}}cls->{{variant}}({{#argv}}_a_{{index}}{{comma}}{{/argv}}{{#argv_ref}}_a_{{index}}{{comma}}{{/argv_ref}});
        return 0;
    }{{/has_argv}}
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
        return g_default_meta;{{/complete}}{{#incomplete_bg_1}}     
        constexpr void *__meta_label[] = {{{#labels}}
            &&label_{{next_index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];{{#labels}}
    label_{{next_index}}:
        return invoke_{{variant}}_{{next_layer}}_{{next_index}}(cls, _value, tag);{{/labels}}{{/incomplete_bg_1}}{{#incomplete_eq_1}}
        if (tag)
        {
            auto _value = tag();
            return invoke_{{variant}}_{{next_layer}}_{{next_index}}(cls, _value, tag);
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