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

const std::string func_tpl = R"(
inline meta &rfl_{{layer}}_{{index}}(const {{class}} *cls, uint64_t value, branch_string &tag)
{{{#block}}
    if ({{value}} == value) // {{comment}}
    {{{#complete}}
        if (!tag) // complete
        {
            return g_{{class}}_meta[e__{{class}}__{{variant}}{{__field}}];
        }
        return g_default_meta;{{/complete}}{{#incomplete_bg_1}} // incomplete_bg_1    
        constexpr void *__meta_label[] = {{{#labels}}
            &&label_{{next_index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;
        goto *__meta_label[index];{{#labels_bg_0}}
    label_{{next_index}}:
        return rfl_{{next_layer}}_{{next_index}}(cls, _value, tag);{{/labels_bg_0}}{{#labels_eq_0}}
    label_{{next_index}}:{{/labels_eq_0}}
        return g_default_meta;{{/incomplete_bg_1}}{{#incomplete_eq_1}}
        if (tag) // incomplete_eq_1
        {
            auto _value = tag();
            return rfl_{{next_layer}}_{{next_index}}(cls, _value, tag);
        }
        return g_default_meta;{{/incomplete_eq_1}}{{#invoke}}      
        if (!tag) // invoke
        {
            return g_{{class}}_meta[e__{{class}}__{{variant}}];
        }{{/invoke}}
    }{{/block}}
    return g_default_meta;
}
)";

namespace tpl
{
    const std::string &func()
    {
        return func_tpl;
    }

}
