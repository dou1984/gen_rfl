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

const std::string get_meta_tpl = R"(
const uint64_t get_fields_max(const {{class}} *cls)
{
    return countof(g_{{class}}_meta);
}
namespace __details__
{    
    meta<{{class}}>& get_meta(const {{class}} *cls, branch_string &tag)
    {{{#meta_bg_1}}
        constexpr void *__meta_label[] = {{{#labels}}
            &&label__{{layer}}__{{index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto value = tag();
        auto index = value % count;        
        goto *__meta_label[index];{{#labels_bg_0}}
    label__{{layer}}__{{index}}:
        return rfl__{{layer}}__{{index}}(cls, value, tag);{{/labels_bg_0}}{{#labels_eq_0}}
    label__{{layer}}__{{index}}:{{/labels_eq_0}}
        return g_default_meta;{{/meta_bg_1}}{{#meta_eq_1}}
        auto value = tag();
        return rfl__{{layer}}__{{index}}(cls, value, tag);{{/meta_eq_1}}
    }
    meta<{{class}}>& get_meta(const {{class}} *cls, branch_string &tag, const std::string &args_tag)
    {
        return get_meta(cls, tag).m_invoke(cls, args_tag);    
    }    
}
void *get_value(const {{class}} *cls, const std::string &_tag)
{
    branch_string tag(_tag); 
    return __details__::get_meta(cls, tag).m_member(cls);
}
void *get_value(const {{class}} *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
void *get_value(const {{class}} *cls, const std::string &_tag, const char *expected_type)
{
    branch_string tag(_tag);
    auto _meta = __details__::get_meta(cls, tag);
    return (strcmp(expected_type, _meta.m_type) == 0) ? _meta.m_member(cls) : nullptr;
}
void *get_field_value(const {{class}} *cls, uint32_t field)
{
    if (field < get_fields_max(cls))
    {
        auto& _meta = g_{{class}}_meta[field];        
        return _meta.m_member(cls);
    }
    return nullptr;
}
const char* get_type(const {{class}} *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;
}
const char* get_type(const {{class}} *cls, const char *_tag) 
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;    
}
const char *get_type(const {{class}} *cls)
{
    static const char _class[] = "{{class}}";
    return _class;
}
uint64_t get_field(const {{class}} *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
uint64_t get_field(const {{class}} *cls, const char *_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
const char* get_name(const {{class}} *cls, uint32_t field)
{
    if (field < get_fields_max(cls))
    {
        return g_{{class}}_meta[field].m_variant;
    }
    return g_default_meta.m_variant;
}
meta<{{class}}> &get_meta(const {{class}} *cls)
{
    return g_{{class}};
}
{{#namesp}}
}{{/namesp}}
)";

namespace tpl
{
    const std::string &get_meta()
    {
        return get_meta_tpl;
    }
}