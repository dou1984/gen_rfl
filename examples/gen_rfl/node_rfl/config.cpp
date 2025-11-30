#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "config.h"
#include "../../node.h"
#include <gen_rfl/setter.h>
#include <gen_rfl/arguments.h>


enum config_meta_enum
{
    e__config__o0,
    e__config__o1,
    e__config__o2,
    e__config__o3,
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

static reflect::meta<config> g_config_func[] = 
{
};

static reflect::meta<config> g_config_meta[] = {
{
    .m_variant = "o0",
    .m_type = "long",
    .m_flags = 0x801,
    .m_t_flags = ::reflect::flag_type<long>(),
    .m_field = e__config__o0, // 0
    .m_getter = [](const config *cls) -> void * 
    { return (void *)std::addressof(cls->o0); },
    .m_setter = []() -> auto
    { return ::reflect::__setter__<config, ::reflect::__ref_member__<config, &config::o0>>; }(),
},
{
    .m_variant = "o1",
    .m_type = "long",
    .m_flags = 0x801,
    .m_t_flags = ::reflect::flag_type<long>(),
    .m_field = e__config__o1, // 1
    .m_getter = [](const config *cls) -> void * 
    { return (void *)std::addressof(cls->o1); },
    .m_setter = []() -> auto
    { return ::reflect::__setter__<config, ::reflect::__ref_member__<config, &config::o1>>; }(),
},
{
    .m_variant = "o2",
    .m_type = "long",
    .m_flags = 0x801,
    .m_t_flags = ::reflect::flag_type<long>(),
    .m_field = e__config__o2, // 2
    .m_getter = [](const config *cls) -> void * 
    { return (void *)std::addressof(cls->o2); },
    .m_setter = []() -> auto
    { return ::reflect::__setter__<config, ::reflect::__ref_member__<config, &config::o2>>; }(),
},
{
    .m_variant = "o3",
    .m_type = "long",
    .m_flags = 0x801,
    .m_t_flags = ::reflect::flag_type<long>(),
    .m_field = e__config__o3, // 3
    .m_getter = [](const config *cls) -> void * 
    { return (void *)std::addressof(cls->o3); },
    .m_setter = []() -> auto
    { return ::reflect::__setter__<config, ::reflect::__ref_member__<config, &config::o3>>; }(),
},
};
reflect::Value __get_value(const config* cls, const std::string& _tag)
{
    return reflect::Value(nullptr, reflect::e_nullptr);
}
inline ::reflect::meta<config> &rfl__0__0(const config *cls, uint64_t value, ::reflect::branch_string &tag)
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
inline ::reflect::meta<config> &rfl__0__1(const config *cls, uint64_t value, ::reflect::branch_string &tag)
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
inline ::reflect::meta<config> &rfl__0__2(const config *cls, uint64_t value, ::reflect::branch_string &tag)
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
inline ::reflect::meta<config> &rfl__0__4(const config *cls, uint64_t value, ::reflect::branch_string &tag)
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
const uint64_t get_fields_count(const config *cls)
{
    return countof(g_config_meta);
}
namespace __details__
{    
    ::reflect::meta<config>& get_meta(const config *cls, ::reflect::branch_string &tag)
    {
        constexpr void *__meta_label[] = {
            &&label__0__0,
            &&label__0__1,
            &&label__0__2,
            &&label__0__3,
            &&label__0__4,
        };
        constexpr auto count = countof(__meta_label);
        auto value = tag();
        auto index = value % count;        
        goto *__meta_label[index];
    label__0__0:
        return rfl__0__0(cls, value, tag);
    label__0__1:
        return rfl__0__1(cls, value, tag);
    label__0__2:
        return rfl__0__2(cls, value, tag);
    label__0__4:
        return rfl__0__4(cls, value, tag);
    label__0__3:
        return g_default_meta;
    }
    ::reflect::meta<config> &get_meta(const config *cls, ::reflect::branch_string& tag, const std::list<std::string>& args_tag)
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
::reflect::Value get_value(const config *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag); 
    auto& _meta = __details__::get_meta(cls, tag);
    if (::reflect::__contains__(_meta.m_flags, ::reflect::flag_member))
    {
        return ::reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);  
    }      
    return __get_value(cls, _tag);   
}
::reflect::Value get_value(const config *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
::reflect::Value get_field_value(const config *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        auto& _meta = g_config_meta[field]; 
        if (_meta.m_t_flags != 0)
        {
            return ::reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);
        }
    }
    return reflect::Value(nullptr, reflect::e_nullptr);
}
const std::string &get_type(const config *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;
}
const std::string &get_type(const config *cls, const char *_tag) 
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;    
}
const std::string &get_type(const config *cls)
{
    static const std::string _class = "config";
    return _class;
}
uint64_t get_field(const config *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
uint64_t get_field(const config *cls, const char *_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
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
::reflect::meta<config> &get_meta(const config *cls)
{
    return g_config;
}

