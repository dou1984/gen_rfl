#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "../../node.h"
#include "priv_opts.h"
#include <gen_rfl/setter.h>
#include <gen_rfl/arguments.h>
#include <gen_rfl/item.h>


namespace reflect
{
    enum priv_opts_meta_enum
    {
        e__priv_opts__opts,
        e__priv_opts__end,
    };
    enum priv_opts_func_enum
    {
        e__priv_opts__func__end,
    };
    static int set_value_invalid(priv_opts *cls, uint32_t, ...)
    {
        return 0;
    }
    static reflect::meta<priv_opts> g_default_meta = {
        .m_variant = "",
        .m_type = "",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const priv_opts *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    static reflect::meta<priv_opts> g_priv_opts = {
        .m_variant = "priv_opts",
        .m_type = "",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const priv_opts *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    
    static meta<priv_opts> g_priv_opts_func[] = 
    {
    };
    
    static reflect::meta<priv_opts> g_priv_opts_meta[] = {
    {
        .m_variant = "opts",
        .m_type = "int",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<int>(),
        .m_field = e__priv_opts__opts, // 0
        .m_getter = [](const priv_opts *cls) -> void * 
        { return (void *)std::addressof(cls->opts); },
        .m_setter = []() -> auto
        { return __setter__<priv_opts, __ref_member__<priv_opts, &priv_opts::opts>>; }(),
    },
    };
    reflect::Value __get_value(const priv_opts* cls, const std::string& _tag)
    {
        return reflect::Value(nullptr, reflect::e_nullptr);
    }

    inline meta<priv_opts> &rfl__0__0(const priv_opts *cls, uint64_t value, branch_string &tag)
    {
        if (0x7374706f == value) // opts
        {
            if (!tag) // complete
            {
                return g_priv_opts_meta[e__priv_opts__opts];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    const uint64_t get_fields_count(const priv_opts *cls)
    {
        return countof(g_priv_opts_meta);
    }
    namespace details
    {    
        meta<priv_opts> &get_meta(const priv_opts *cls, branch_string &tag)
        {
            auto value = tag();
            return rfl__0__0(cls, value, tag);
        }
    
        meta<priv_opts> &get_func(const priv_opts *cls, branch_string& tag, const std::list<Item> &argu_item)
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
        int get_base_func(const priv_opts *cls, const std::string_view& _tag, const Arguments *_, ...)
        {
            va_list __arguments_list;
            va_start(__arguments_list, _);
            auto r = -1;
            do
            {
            } while (false);
            va_end(__arguments_list);
            return r;
        }
    }
    Value get_value(const priv_opts *cls, const std::string &_tag)
    {
        branch_string tag(_tag); 
        auto& _meta = details::get_meta(cls, tag);
        if (__contains__(_meta.m_flags, flag_member))
        {
            return Value(_meta.m_getter(cls), _meta.m_t_flags);  
        }      
        return __get_value(cls, _tag);   
    }
    Value get_value(const priv_opts *cls, const char *tag)
    {
        return get_value(cls, std::string(tag));
    }
    Value get_field_value(const priv_opts *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_priv_opts_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return Value(_meta.m_getter(cls), _meta.m_t_flags);
            }
        }
        return reflect::Value(nullptr, reflect::e_nullptr);
    }
    const std::string &get_type(const priv_opts *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;
    }
    const std::string &get_type(const priv_opts *cls, const char *_tag) 
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;    
    }
    const std::string &get_type(priv_opts *cls)
    {
        static const std::string _class = "priv_opts";
        return _class;
    }
    const std::string &get_type(const priv_opts *cls)
    {
        static const std::string _class = "priv_opts";
        return _class;
    }
    const std::string &get_type(priv_opts **cls)
    {
        static const std::string _class = "priv_opts *";
        return _class;
    }
    const std::string &get_type(const priv_opts **cls)
    {
        static const std::string _class = "priv_opts *";
        return _class;
    }
    const std::string &get_typeid(const priv_opts *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_typeid;       
    }
    const std::string &get_typeid(const priv_opts *cls)
    {
        static const std::string _class = typeid(priv_opts).name();
        return _class;
    }
    uint64_t get_field(const priv_opts *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    uint64_t get_field(const priv_opts *cls, const char *_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    const std::string &get_field_type(const priv_opts *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_priv_opts_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return _meta.m_type;
            }
        }
        static std::string _ = "";
        return _;
    }
    const std::string &get_name(const priv_opts *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            return g_priv_opts_meta[field].m_variant;
        }
        return g_default_meta.m_variant;
    }
    meta<priv_opts> &get_meta(const priv_opts *cls)
    {
        return g_priv_opts;
    }
    int for_each(const priv_opts *cls, const std::function<void(const std::string &, const std::string &, const Value &)> &callback)
    {
        if (callback)
        {
            for (auto i = 0; i < get_fields_count(cls); i++)            
            {                
                auto& _meta = g_priv_opts_meta[i];
                if (!__contains__(_meta.m_flags, flag_function))
                {
                    if (__contains__(_meta.m_flags, flag_struct, flag_class))
                    {
                        do
                        {
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

