#include <string>
#include "tpl.h"

const std::string get_meta_tpl = R"(
const uint64_t get_fields_max(const {{class}} *cls)
{
    return countof(g_{{class}}_meta);
}
namespace __details
{
    meta& get_meta(const {{class}} *cls, branch_string &tag)
    {     
        constexpr void *__meta_label[] = {{{#labels}}
            &&label_{{index}},{{/labels}}
        };
        constexpr auto count = countof(__meta_label);
        auto value = tag();
        auto index = value % count;        
        goto *__meta_label[index];{{#labels}}
    label_{{index}}:
        return rfl_{{layer}}_{{index}}(cls, value, tag);{{/labels}}
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
    auto _meta = __details::get_meta(cls, tag);
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
    auto _meta = __details::get_meta(cls, tag);
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
    return __details::get_meta(cls, tag).m_type;
}
const char* get_type(const {{class}} *cls, const char *_tag) 
{
    branch_string tag(_tag);
    return __details::get_meta(cls, tag).m_type;    
}
const char *get_type(const {{class}} *cls)
{
    static const char _class[] = "{{class}}";
    return _class;
}
uint64_t get_field(const {{class}} *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    return __details::get_meta(cls, tag).m_field;  
}
uint64_t get_field(const {{class}} *cls, const char *_tag)
{
    branch_string tag(_tag);
    return __details::get_meta(cls, tag).m_field;  
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