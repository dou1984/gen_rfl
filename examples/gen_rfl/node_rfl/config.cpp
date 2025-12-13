#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "../../node.h"
#include "options.h"
#include "config.h"
#include <gen_rfl/setter.h>
#include <gen_rfl/arguments.h>
#include <gen_rfl/item.h>


namespace reflect
{
    enum config_meta_enum
    {
        e__config__o0,
        e__config__o1,
        e__config__o2,
        e__config__o3,
        e__config__options,
        e__config__end,
    };
    enum config_func_enum
    {
        e__config__func__end,
    };
    static int set_value_invalid(config *cls, uint32_t, ...)
    {
        return 0;
    }
    static reflect::meta<config> g_default_meta = {
        .m_variant = "",
        .m_type = "",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const config *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    static reflect::meta<config> g_config = {
        .m_variant = "config",
        .m_type = "",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const config *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    
    static meta<config> g_config_func[] = 
    {
    };
    
    static reflect::meta<config> g_config_meta[] = {
    {
        .m_variant = "o0",
        .m_type = "long",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<long>(),
        .m_field = e__config__o0, // 1
        .m_getter = [](const config *cls) -> void * 
        { return (void *)std::addressof(cls->o0); },
        .m_setter = []() -> auto
        { return __setter__<config, __ref_member__<config, &config::o0>>; }(),
    },
    {
        .m_variant = "o1",
        .m_type = "long",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<long>(),
        .m_field = e__config__o1, // 2
        .m_getter = [](const config *cls) -> void * 
        { return (void *)std::addressof(cls->o1); },
        .m_setter = []() -> auto
        { return __setter__<config, __ref_member__<config, &config::o1>>; }(),
    },
    {
        .m_variant = "o2",
        .m_type = "long",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<long>(),
        .m_field = e__config__o2, // 3
        .m_getter = [](const config *cls) -> void * 
        { return (void *)std::addressof(cls->o2); },
        .m_setter = []() -> auto
        { return __setter__<config, __ref_member__<config, &config::o2>>; }(),
    },
    {
        .m_variant = "o3",
        .m_type = "long",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<long>(),
        .m_field = e__config__o3, // 4
        .m_getter = [](const config *cls) -> void * 
        { return (void *)std::addressof(cls->o3); },
        .m_setter = []() -> auto
        { return __setter__<config, __ref_member__<config, &config::o3>>; }(),
    },
    {
        .m_variant = "options",
        .m_type = "options",
        .m_flags = 0x821,
        .m_t_flags = ::reflect::flag_type<options>(),
        .m_field = e__config__options, // 0
        .m_getter = [](const config *cls) -> void * 
        { return (void *)static_cast<const options *>(cls); },
        .m_setter = []() -> auto
        { return __setter__<config, __ref_base__<config, options>>; }(),
    },
    };
    reflect::Value __get_value(const config* cls, const std::string& _tag)
    { 
        {
            branch_string tag(_tag);
            auto &_base = details::get_meta(static_cast<const options *>(cls), tag);
            if (__contains__(_base.m_flags, flag_member))
            {
                return reflect::Value(_base.m_getter(cls), _base.m_t_flags);   
            }
        }
        return reflect::Value(nullptr, reflect::e_nullptr);
    }

    inline meta<config> &rfl__0__0(const config *cls, uint64_t value, branch_string &tag)
    {
        if (0x736e6f6974706f == value) // options
        {
            if (!tag) // complete
            {
                return g_config_meta[e__config__options];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<config> &rfl__0__2(const config *cls, uint64_t value, branch_string &tag)
    {
        if (0x326f == value) // o2
        {
            if (!tag) // complete
            {
                return g_config_meta[e__config__o2];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<config> &rfl__0__6(const config *cls, uint64_t value, branch_string &tag)
    {
        if (0x316f == value) // o1
        {
            if (!tag) // complete
            {
                return g_config_meta[e__config__o1];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<config> &rfl__0__10(const config *cls, uint64_t value, branch_string &tag)
    {
        if (0x306f == value) // o0
        {
            if (!tag) // complete
            {
                return g_config_meta[e__config__o0];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<config> &rfl__0__11(const config *cls, uint64_t value, branch_string &tag)
    {
        if (0x336f == value) // o3
        {
            if (!tag) // complete
            {
                return g_config_meta[e__config__o3];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    const uint64_t get_fields_count(const config *cls)
    {
        return countof(g_config_meta);
    }
    namespace details
    {    
        meta<config> &get_meta(const config *cls, branch_string &tag)
        {
            constexpr void *__meta_label[] = {
                &&label__0__0,
                &&label__0__1,
                &&label__0__2,
                &&label__0__3,
                &&label__0__4,
                &&label__0__5,
                &&label__0__6,
                &&label__0__7,
                &&label__0__8,
                &&label__0__9,
                &&label__0__10,
                &&label__0__11,
                &&label__0__12,
            };
            constexpr auto count = countof(__meta_label);
            auto value = tag();
            auto index = value % count;        
            goto *__meta_label[index];
        label__0__0:
            return rfl__0__0(cls, value, tag);
        label__0__2:
            return rfl__0__2(cls, value, tag);
        label__0__6:
            return rfl__0__6(cls, value, tag);
        label__0__10:
            return rfl__0__10(cls, value, tag);
        label__0__11:
            return rfl__0__11(cls, value, tag);
        label__0__1:
        label__0__3:
        label__0__4:
        label__0__5:
        label__0__7:
        label__0__8:
        label__0__9:
        label__0__12:
            return g_default_meta;
        }
    
        meta<config> &get_func(const config *cls, branch_string& tag, const std::list<Item> &argu_item)
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
        int get_base_func(const config *cls, const std::string_view& _tag, const Arguments *_, ...)
        {
            va_list __arguments_list;
            va_start(__arguments_list, _);
            auto r = -1;
            do
            {
                {
                    branch_string tag(_tag);
                    auto &_invoke = details::get_func(static_cast<const options *>(cls), tag, _->m_arguments);
                    if (__contains__(_invoke.m_flags, flag_argument))
                    {
                        r = _invoke.m_func_v(const_cast<options *>(static_cast<const options *>(cls)), _, __arguments_list);
                        break;
                    } 
                }
            } while (false);
            va_end(__arguments_list);
            return r;
        }
    }
    Value get_value(const config *cls, const std::string &_tag)
    {
        branch_string tag(_tag); 
        auto& _meta = details::get_meta(cls, tag);
        if (__contains__(_meta.m_flags, flag_member))
        {
            return Value(_meta.m_getter(cls), _meta.m_t_flags);  
        }      
        return __get_value(cls, _tag);   
    }
    Value get_value(const config *cls, const char *tag)
    {
        return get_value(cls, std::string(tag));
    }
    Value get_field_value(const config *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_config_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return Value(_meta.m_getter(cls), _meta.m_t_flags);
            }
        }
        return reflect::Value(nullptr, reflect::e_nullptr);
    }
    const std::string &get_type(const config *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;
    }
    const std::string &get_type(const config *cls, const char *_tag) 
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;    
    }
    const std::string &get_type(config *cls)
    {
        static const std::string _class = "config";
        return _class;
    }
    const std::string &get_type(const config *cls)
    {
        static const std::string _class = "config";
        return _class;
    }
    const std::string &get_type(config **cls)
    {
        static const std::string _class = "config *";
        return _class;
    }
    const std::string &get_type(const config **cls)
    {
        static const std::string _class = "config *";
        return _class;
    }
    const std::string &get_typeid(const config *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_typeid;       
    }
    const std::string &get_typeid(const config *cls)
    {
        static const std::string _class = typeid(config).name();
        return _class;
    }
    uint64_t get_field(const config *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    uint64_t get_field(const config *cls, const char *_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    const std::string &get_field_type(const config *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_config_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return _meta.m_type;
            }
        }
        static std::string _ = "";
        return _;
    }
    const std::string &get_name(const config *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            return g_config_meta[field].m_variant;
        }
        return g_default_meta.m_variant;
    }
    meta<config> &get_meta(const config *cls)
    {
        return g_config;
    }
    int for_each(const config *cls, const std::function<void(const std::string &, const std::string &, const Value &)> &callback)
    {
        if (callback)
        {
            for (auto i = 0; i < get_fields_count(cls); i++)            
            {                
                auto& _meta = g_config_meta[i];
                if (!__contains__(_meta.m_flags, flag_function))
                {
                    if (__contains__(_meta.m_flags, flag_struct, flag_class))
                    {
                        do
                        {
                            if (_meta.m_variant == "options")
                            {
                                auto _base = static_cast<const options *>(cls);
                                for_each(_base, [&](auto &_variant, auto &key, auto &value)
                                {                                     
                                    callback(_meta.m_variant, key, value);                                   
                                });
                                break;             
                            }
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

