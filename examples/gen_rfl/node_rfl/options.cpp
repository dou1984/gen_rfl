#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "../../node.h"
#include "priv_opts.h"
#include "options.h"
#include <gen_rfl/setter.h>
#include <gen_rfl/arguments.h>
#include <gen_rfl/item.h>


namespace reflect
{
    enum options_meta_enum
    {
        e__options__is_running,
        e__options__is_stop,
        e__options__is_suspend,
        e__options__priv_opts,
        e__options__status,
        e__options__end,
    };
    enum options_func_enum
    {
        e__options__func__end,
    };
    static int set_value_invalid(options *cls, uint32_t, ...)
    {
        return 0;
    }
    static reflect::meta<options> g_default_meta = {
        .m_variant = "",
        .m_type = "",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const options *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    static reflect::meta<options> g_options = {
        .m_variant = "options",
        .m_type = "",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const options *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    
    static meta<options> g_options_func[] = 
    {
    };
    
    static reflect::meta<options> g_options_meta[] = {
    {
        .m_variant = "is_running",
        .m_type = "bool",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<bool>(),
        .m_field = e__options__is_running, // 2
        .m_getter = [](const options *cls) -> void * 
        { return (void *)std::addressof(cls->is_running); },
        .m_setter = []() -> auto
        { return __setter__<options, __ref_member__<options, &options::is_running>>; }(),
    },
    {
        .m_variant = "is_stop",
        .m_type = "bool",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<bool>(),
        .m_field = e__options__is_stop, // 3
        .m_getter = [](const options *cls) -> void * 
        { return (void *)std::addressof(cls->is_stop); },
        .m_setter = []() -> auto
        { return __setter__<options, __ref_member__<options, &options::is_stop>>; }(),
    },
    {
        .m_variant = "is_suspend",
        .m_type = "bool",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<bool>(),
        .m_field = e__options__is_suspend, // 4
        .m_getter = [](const options *cls) -> void * 
        { return (void *)std::addressof(cls->is_suspend); },
        .m_setter = []() -> auto
        { return __setter__<options, __ref_member__<options, &options::is_suspend>>; }(),
    },
    {
        .m_variant = "priv_opts",
        .m_type = "priv_opts",
        .m_flags = 0x821,
        .m_t_flags = ::reflect::flag_type<priv_opts>(),
        .m_field = e__options__priv_opts, // 0
        .m_getter = [](const options *cls) -> void * 
        { return (void *)static_cast<const priv_opts *>(cls); },
        .m_setter = []() -> auto
        { return __setter__<options, __ref_base__<options, priv_opts>>; }(),
    },
    {
        .m_variant = "status",
        .m_type = "bool",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<bool>(),
        .m_field = e__options__status, // 1
        .m_getter = [](const options *cls) -> void * 
        { return (void *)std::addressof(cls->status); },
        .m_setter = []() -> auto
        { return __setter__<options, __ref_member__<options, &options::status>>; }(),
    },
    };
    reflect::Value __get_value(const options* cls, const std::string& _tag)
    { 
        {
            branch_string tag(_tag);
            auto &_base = details::get_meta(static_cast<const priv_opts *>(cls), tag);
            if (__contains__(_base.m_flags, flag_member))
            {
                return reflect::Value(_base.m_getter(cls), _base.m_t_flags);   
            }
        }
        return reflect::Value(nullptr, reflect::e_nullptr);
    }

    inline meta<options> &rfl__0__1(const options *cls, uint64_t value, branch_string &tag)
    {
        if (0x737574617473 == value) // status
        {
            if (!tag) // complete
            {
                return g_options_meta[e__options__status];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<options> &rfl__1__0(const options *cls, uint64_t value, branch_string &tag)
    {
        if (0x646e == value) // nd
        {
            if (!tag) // complete
            {
                return g_options_meta[e__options__is_suspend];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<options> &rfl__0__5(const options *cls, uint64_t value, branch_string &tag)
    {
        if (0x65707375735f7369 == value) // is_suspe
        {
            if (tag) // incomplete_eq_1
            {
                auto _value = tag();
                return rfl__1__0(cls, _value, tag);
            }
        }
        return g_default_meta;
    }
    inline meta<options> &rfl__0__6(const options *cls, uint64_t value, branch_string &tag)
    {
        if (0x706f74735f7369 == value) // is_stop
        {
            if (!tag) // complete
            {
                return g_options_meta[e__options__is_stop];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<options> &rfl__1__1(const options *cls, uint64_t value, branch_string &tag)
    {
        if (0x676e == value) // ng
        {
            if (!tag) // complete
            {
                return g_options_meta[e__options__is_running];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<options> &rfl__0__7(const options *cls, uint64_t value, branch_string &tag)
    {
        if (0x696e6e75725f7369 == value) // is_runni
        {
            if (tag) // incomplete_eq_1
            {
                auto _value = tag();
                return rfl__1__1(cls, _value, tag);
            }
        }
        return g_default_meta;
    }
    inline meta<options> &rfl__1__2(const options *cls, uint64_t value, branch_string &tag)
    {
        if (0x73 == value) // s
        {
            if (!tag) // complete
            {
                return g_options_meta[e__options__priv_opts];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<options> &rfl__0__14(const options *cls, uint64_t value, branch_string &tag)
    {
        if (0x74706f5f76697270 == value) // priv_opt
        {
            if (tag) // incomplete_eq_1
            {
                auto _value = tag();
                return rfl__1__2(cls, _value, tag);
            }
        }
        return g_default_meta;
    }
    const uint64_t get_fields_count(const options *cls)
    {
        return countof(g_options_meta);
    }
    namespace details
    {    
        meta<options> &get_meta(const options *cls, branch_string &tag)
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
                &&label__0__13,
                &&label__0__14,
                &&label__0__15,
                &&label__0__16,
                &&label__0__17,
                &&label__0__18,
            };
            constexpr auto count = countof(__meta_label);
            auto value = tag();
            auto index = value % count;        
            goto *__meta_label[index];
        label__0__1:
            return rfl__0__1(cls, value, tag);
        label__0__5:
            return rfl__0__5(cls, value, tag);
        label__0__6:
            return rfl__0__6(cls, value, tag);
        label__0__7:
            return rfl__0__7(cls, value, tag);
        label__0__14:
            return rfl__0__14(cls, value, tag);
        label__0__0:
        label__0__2:
        label__0__3:
        label__0__4:
        label__0__8:
        label__0__9:
        label__0__10:
        label__0__11:
        label__0__12:
        label__0__13:
        label__0__15:
        label__0__16:
        label__0__17:
        label__0__18:
            return g_default_meta;
        }
    
        meta<options> &get_func(const options *cls, branch_string& tag, const std::list<Item> &argu_item)
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
        int get_base_func(const options *cls, const std::string_view& _tag, const Arguments *_, ...)
        {
            va_list __arguments_list;
            va_start(__arguments_list, _);
            auto r = -1;
            do
            {
                {
                    branch_string tag(_tag);
                    auto &_invoke = details::get_func(static_cast<const priv_opts *>(cls), tag, _->m_arguments);
                    if (__contains__(_invoke.m_flags, flag_argument))
                    {
                        r = _invoke.m_func_v(const_cast<priv_opts *>(static_cast<const priv_opts *>(cls)), _, __arguments_list);
                        break;
                    } 
                }
            } while (false);
            va_end(__arguments_list);
            return r;
        }
    }
    Value get_value(const options *cls, const std::string &_tag)
    {
        branch_string tag(_tag); 
        auto& _meta = details::get_meta(cls, tag);
        if (__contains__(_meta.m_flags, flag_member))
        {
            return Value(_meta.m_getter(cls), _meta.m_t_flags);  
        }      
        return __get_value(cls, _tag);   
    }
    Value get_value(const options *cls, const char *tag)
    {
        return get_value(cls, std::string(tag));
    }
    Value get_field_value(const options *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_options_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return Value(_meta.m_getter(cls), _meta.m_t_flags);
            }
        }
        return reflect::Value(nullptr, reflect::e_nullptr);
    }
    const std::string &get_type(const options *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;
    }
    const std::string &get_type(const options *cls, const char *_tag) 
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;    
    }
    const std::string &get_type(options *cls)
    {
        static const std::string _class = "options";
        return _class;
    }
    const std::string &get_type(const options *cls)
    {
        static const std::string _class = "options";
        return _class;
    }
    const std::string &get_type(options **cls)
    {
        static const std::string _class = "options *";
        return _class;
    }
    const std::string &get_type(const options **cls)
    {
        static const std::string _class = "options *";
        return _class;
    }
    const std::string &get_typeid(const options *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_typeid;       
    }
    const std::string &get_typeid(const options *cls)
    {
        static const std::string _class = typeid(options).name();
        return _class;
    }
    uint64_t get_field(const options *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    uint64_t get_field(const options *cls, const char *_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    const std::string &get_field_type(const options *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_options_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return _meta.m_type;
            }
        }
        static std::string _ = "";
        return _;
    }
    const std::string &get_name(const options *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            return g_options_meta[field].m_variant;
        }
        return g_default_meta.m_variant;
    }
    meta<options> &get_meta(const options *cls)
    {
        return g_options;
    }
    int for_each(const options *cls, const std::function<void(const std::string &, const std::string &, const Value &)> &callback)
    {
        if (callback)
        {
            for (auto i = 0; i < get_fields_count(cls); i++)            
            {                
                auto& _meta = g_options_meta[i];
                if (!__contains__(_meta.m_flags, flag_function))
                {
                    if (__contains__(_meta.m_flags, flag_struct, flag_class))
                    {
                        do
                        {
                            if (_meta.m_variant == "priv_opts")
                            {
                                auto _base = static_cast<const priv_opts *>(cls);
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

