const uint64_t get_fields_count(const {{class}} *cls)
{
    return countof(g_{{class}}_meta);
}
namespace __details__
{    
    ::reflect::meta<{{class}}>& get_meta(const {{class}} *cls, ::reflect::branch_string &tag)
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
    ::reflect::meta<{{class}}> &get_meta(const {{class}} *cls, ::reflect::branch_string& tag, const std::list<std::string>& args_tag)
    {
        auto &_meta = __details__::get_meta(cls, tag);
        if (::reflect::__contains__(_meta.m_flags, ::reflect::flag_function))
        {
            auto &_invoke = _meta.m_invoke(cls, args_tag);
            if (::reflect::__contains__(_invoke.m_flags, ::reflect::flag_argument))
            {
                return _invoke;
            }
        }
        return g_default_meta;
    }
}
::reflect::Value get_value(const {{class}} *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag); 
    auto& _meta = __details__::get_meta(cls, tag);
    if (::reflect::__contains__(_meta.m_flags, ::reflect::flag_member))
    {
        return ::reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);  
    }      
    return __get_value(cls, _tag);   
}
::reflect::Value get_value(const {{class}} *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
::reflect::Value get_field_value(const {{class}} *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        auto& _meta = g_{{class}}_meta[field]; 
        if (_meta.m_t_flags != 0)
        {
            return ::reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);
        }
    }
    return reflect::Value(nullptr, reflect::e_nullptr);
}
const std::string &get_type(const {{class}} *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;
}
const std::string &get_type(const {{class}} *cls, const char *_tag) 
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;    
}
const std::string &get_type(const {{class}} *cls)
{
    static const std::string _class = "{{class}}";
    return _class;
}
uint64_t get_field(const {{class}} *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
uint64_t get_field(const {{class}} *cls, const char *_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
const std::string &get_field_type(const {{class}} *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        auto& _meta = g_{{class}}_meta[field]; 
        if (_meta.m_t_flags != 0)
        {
            return _meta.m_type;
        }
    }
    static std::string _ = "";
    return _;
}
const std::string &get_name(const {{class}} *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        return g_{{class}}_meta[field].m_variant;
    }
    return g_default_meta.m_variant;
}
::reflect::meta<{{class}}> &get_meta(const {{class}} *cls)
{
    return g_{{class}};
}
{{#namesp}}
}{{/namesp}}
