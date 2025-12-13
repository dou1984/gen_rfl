    const uint64_t get_fields_count(const {{class}} *cls)
    {
        return countof(g_{{class}}_meta);
    }
    namespace details
    {    
        meta<{{class}}> &get_meta(const {{class}} *cls, branch_string &tag)
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
    
        meta<{{class}}> &get_func(const {{class}} *cls, branch_string& tag, const std::list<Item> &argu_item)
        {
            auto& _meta = details::get_meta(cls, tag);
            if (__contains__(_meta.m_flags, flag_function))
            {
                auto &_invoke = _meta.m_invoke(cls, argu_item);
                if (__contains__(_invoke.m_flags, flag_argument))
                {           
                    return _invoke;
                }
            }
            return g_default_meta;
        }
        int get_base_func(const {{class}} *cls, const std::string_view& _tag, const Arguments *_, ...)
        {
            va_list __arguments_list;
            va_start(__arguments_list, _);
            auto r = -1;
            do
            {{{#is_base}}
                {
                    branch_string tag(_tag);
                    auto &_invoke = details::get_func(static_cast<const {{variant}} *>(cls), tag, _->m_arguments);
                    if (__contains__(_invoke.m_flags, flag_argument))
                    {
                        r = _invoke.m_func_v(const_cast<{{variant}} *>(static_cast<const {{variant}} *>(cls)), _, __arguments_list);
                        break;
                    } 
                }{{/is_base}}
            } while (false);
            va_end(__arguments_list);
            return r;
        }
    }
    Value get_value(const {{class}} *cls, const std::string &_tag)
    {
        branch_string tag(_tag); 
        auto& _meta = details::get_meta(cls, tag);
        if (__contains__(_meta.m_flags, flag_member))
        {
            return Value(_meta.m_getter(cls), _meta.m_t_flags);  
        }      
        return __get_value(cls, _tag);   
    }
    Value get_value(const {{class}} *cls, const char *tag)
    {
        return get_value(cls, std::string(tag));
    }
    Value get_field_value(const {{class}} *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_{{class}}_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return Value(_meta.m_getter(cls), _meta.m_t_flags);
            }
        }
        return reflect::Value(nullptr, reflect::e_nullptr);
    }
    const std::string &get_type(const {{class}} *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;
    }
    const std::string &get_type(const {{class}} *cls, const char *_tag) 
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;    
    }
    const std::string &get_type({{class}} *cls)
    {
        static const std::string _class = "{{class}}";
        return _class;
    }
    const std::string &get_type(const {{class}} *cls)
    {
        static const std::string _class = "{{class}}";
        return _class;
    }
    const std::string &get_type({{class}} **cls)
    {
        static const std::string _class = "{{class}} *";
        return _class;
    }
    const std::string &get_type(const {{class}} **cls)
    {
        static const std::string _class = "{{class}} *";
        return _class;
    }
    const std::string &get_typeid(const {{class}} *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_typeid;       
    }
    const std::string &get_typeid(const {{class}} *cls)
    {
        static const std::string _class = typeid({{class}}).name();
        return _class;
    }
    uint64_t get_field(const {{class}} *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    uint64_t get_field(const {{class}} *cls, const char *_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
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
    meta<{{class}}> &get_meta(const {{class}} *cls)
    {
        return g_{{class}};
    }
    int for_each(const {{class}} *cls, const std::function<void(const std::string &, const std::string &, const Value &)> &callback)
    {
        if (callback)
        {
            for (auto i = 0; i < get_fields_count(cls); i++)            
            {                
                auto& _meta = g_{{class}}_meta[i];
                if (!__contains__(_meta.m_flags, flag_function))
                {
                    if (__contains__(_meta.m_flags, flag_struct, flag_class))
                    {
                        do
                        {{{#is_base}}
                            if (_meta.m_variant == "{{variant}}")
                            {
                                auto _base = static_cast<const {{variant}} *>(cls);
                                for_each(_base, [&](auto &, auto &key, auto &value)
                                {                                
                                    callback(_meta.m_variant, key, value);
                                });                           
                            }{{/is_base}}
                        } while (0);
                    }
                    else
                    {
                        static std::string _ = "";
                        Value value(_meta.m_getter(cls), _meta.m_t_flags);
                        callback(_, _meta.m_variant, value);
                    }
                }                
            }
            return 0;
        }
        return -1;
    }
}

