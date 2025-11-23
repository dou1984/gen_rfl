#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "common.h"
#include "../../../base/common.h"
#include <gen_rfl/setter.h>
#include <gen_rfl/arguments.h>


namespace fastest
{
enum common_meta_enum
{
    e__common__o0000000,
    e__common__o0000001,
    e__common__o0000002,
    e__common__o0000003,
    e__common__end,
};
enum common_func_enum
{
    e__common__func__end,
};
static int set_value_invalid(common *cls, uint32_t, ...)
{
    return 0;
}
static reflect::meta<common> g_default_meta = {
    .m_variant = "",
    .m_type = "",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const common *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};
static reflect::meta<common> g_common = {
    .m_variant = "common",
    .m_type = "",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const common *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};

static reflect::meta<common> g_common_func[] = 
{
};

static reflect::meta<common> g_common_meta[] = {
{
    .m_variant = "o0000000",
    .m_type = "const char *",
    .m_flags = 0x801,
    .m_t_flags = ::reflect::flag_type<const char *>(),
    .m_field = e__common__o0000000, // 0
    .m_getter = [](const common *cls) -> void * 
    {
        return (void *)std::addressof(cls->o0000000);
    },
    .m_setter = []() -> auto
    { return ::reflect::__setter__<common, ::reflect::__ref_member__<common, &common::o0000000>>; }(),
},
{
    .m_variant = "o0000001",
    .m_type = "const char *",
    .m_flags = 0x801,
    .m_t_flags = ::reflect::flag_type<const char *>(),
    .m_field = e__common__o0000001, // 1
    .m_getter = [](const common *cls) -> void * 
    {
        return (void *)std::addressof(cls->o0000001);
    },
    .m_setter = []() -> auto
    { return ::reflect::__setter__<common, ::reflect::__ref_member__<common, &common::o0000001>>; }(),
},
{
    .m_variant = "o0000002",
    .m_type = "const char *",
    .m_flags = 0x801,
    .m_t_flags = ::reflect::flag_type<const char *>(),
    .m_field = e__common__o0000002, // 2
    .m_getter = [](const common *cls) -> void * 
    {
        return (void *)std::addressof(cls->o0000002);
    },
    .m_setter = []() -> auto
    { return ::reflect::__setter__<common, ::reflect::__ref_member__<common, &common::o0000002>>; }(),
},
{
    .m_variant = "o0000003",
    .m_type = "const char *",
    .m_flags = 0x801,
    .m_t_flags = ::reflect::flag_type<const char *>(),
    .m_field = e__common__o0000003, // 3
    .m_getter = [](const common *cls) -> void * 
    {
        return (void *)std::addressof(cls->o0000003);
    },
    .m_setter = []() -> auto
    { return ::reflect::__setter__<common, ::reflect::__ref_member__<common, &common::o0000003>>; }(),
},
};
reflect::Value __get_value(const common* cls, const std::string& _tag)
{
    return reflect::Value(nullptr, reflect::e_nullptr);
}inline ::reflect::meta<common> &rfl__0__0(const common *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x333030303030306f == value) // o0000003
    {
        if (!tag) // complete
        {
            return g_common_meta[e__common__o0000003];
        }
        return g_default_meta;
    }
    return g_default_meta;
}inline ::reflect::meta<common> &rfl__0__2(const common *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x303030303030306f == value) // o0000000
    {
        if (!tag) // complete
        {
            return g_common_meta[e__common__o0000000];
        }
        return g_default_meta;
    }
    return g_default_meta;
}inline ::reflect::meta<common> &rfl__0__3(const common *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x313030303030306f == value) // o0000001
    {
        if (!tag) // complete
        {
            return g_common_meta[e__common__o0000001];
        }
        return g_default_meta;
    }
    return g_default_meta;
}inline ::reflect::meta<common> &rfl__0__4(const common *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x323030303030306f == value) // o0000002
    {
        if (!tag) // complete
        {
            return g_common_meta[e__common__o0000002];
        }
        return g_default_meta;
    }
    return g_default_meta;
}const uint64_t get_fields_count(const common *cls)
{
    return countof(g_common_meta);
}
namespace __details__
{    
    ::reflect::meta<common>& get_meta(const common *cls, ::reflect::branch_string &tag)
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
    label__0__2:
        return rfl__0__2(cls, value, tag);
    label__0__3:
        return rfl__0__3(cls, value, tag);
    label__0__4:
        return rfl__0__4(cls, value, tag);
    label__0__1:
        return g_default_meta;
    }
    ::reflect::meta<common>& get_meta(const common *cls, ::reflect::branch_string &tag, const std::string &args_tag)
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
::reflect::Value get_value(const common *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag); 
    auto& _meta = __details__::get_meta(cls, tag);
    if (::reflect::__contains__(_meta.m_flags, ::reflect::flag_member))
    {
        return ::reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);  
    }      
    return __get_value(cls, _tag);   
}
::reflect::Value get_value(const common *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
::reflect::Value get_field_value(const common *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        auto& _meta = g_common_meta[field]; 
        if (_meta.m_t_flags != 0)
        {
            return ::reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);
        }
    }
    return reflect::Value(nullptr, reflect::e_nullptr);
}
const std::string &get_type(const common *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;
}
const std::string &get_type(const common *cls, const char *_tag) 
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;    
}
const std::string &get_type(const common *cls)
{
    static const std::string _class = "common";
    return _class;
}
uint64_t get_field(const common *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
uint64_t get_field(const common *cls, const char *_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
const std::string &get_field_type(const common *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        auto& _meta = g_common_meta[field]; 
        if (_meta.m_t_flags != 0)
        {
            return _meta.m_type;
        }
    }
    static std::string _ = "";
    return _;
}
const std::string &get_name(const common *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        return g_common_meta[field].m_variant;
    }
    return g_default_meta.m_variant;
}
::reflect::meta<common> &get_meta(const common *cls)
{
    return g_common;
}

}