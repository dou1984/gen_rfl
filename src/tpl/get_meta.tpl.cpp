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

const std::string get_meta_tpl = R"(
const uint64_t get_fields_max(const {{class}} *cls)
{
    return countof(g_{{class}}_meta);
}
namespace __details__
{
    meta& get_meta(const {{class}} *cls, branch_string &tag)
    {{{#meta_multi}}
        constexpr void *__meta_label[] = {{{#labels}}
            &&label_{{index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto value = tag();
        auto index = value % count;        
        goto *__meta_label[index];{{#labels}}
    label_{{index}}:
        return rfl_{{layer}}_{{index}}(cls, value, tag);{{/labels}}{{/meta_multi}}{{#meta_one}}
        auto value = tag();
        return rfl_{{layer}}_{{index}}(cls, value, tag);{{/meta_one}}
    }
    meta& get_meta({{class}} *cls, branch_string &tag, const std::string &args_tag)
    {
        meta& _meta = get_meta(cls, tag);
        return _meta.m_invoke(cls, args_tag);    
    }
}
void* get_value(const {{class}} *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    auto _meta = __details__::get_meta(cls, tag);
    if (__has_flag(_meta.m_flags, flag_static))
    {
        return _meta.m_ptr;        
    }
    return offset(cls, _meta);    
}
void* get_value(const {{class}} *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
void* get_value(const {{class}} *cls, const std::string &_tag, const char *expected_type)
{
    branch_string tag(_tag);
    auto _meta = __details__::get_meta(cls, tag);
    if (strcmp(expected_type, _meta.m_type) != 0)
    {
        return nullptr;
    }
    if (__has_flag(_meta.m_flags, flag_static))
    {
        return _meta.m_ptr;
    }
    return offset(cls, _meta);
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
void* get_field_value(const {{class}} *cls, uint64_t field)
{
    if (field < get_fields_max(cls))
    {
        auto& _meta = g_{{class}}_meta[field];
        if (__has_flag(_meta.m_flags, flag_static))
        {
            return _meta.m_ptr;            
        }
        return offset(cls, _meta);        
    }
    return nullptr;
}
const char* get_name(const {{class}} *cls, uint64_t field)
{
    if (field < get_fields_max(cls))
    {
        return g_{{class}}_meta[field].m_variant;
    }
    return g_nullptr_meta.m_variant;
}
meta &get_meta(const {{class}} *cls)
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