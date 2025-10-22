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

#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "common.h"
#include "../../../base/common.h"

using namespace reflect;

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
static meta<common> g_default_meta = {
    .m_variant = "",
    .m_type = "",
    .m_flags = __flags(flag_none),
    .m_field = UINT32_MAX,
    .m_member = [](const common *c) -> void* { return nullptr; },
};
static meta<common> g_common = {
    .m_variant = "common",
    .m_type = "common",
    .m_flags = __flags(flag_none),
    .m_field = UINT32_MAX,
    .m_member = [](const common *c) -> void* { return nullptr; },
};

static meta<common> g_common_func[] = 
{
};

static meta<common> g_common_meta[] = {
    {
        .m_variant = "o0000000",
        .m_type = "const char *",
        .m_flags = 0x80001,
        .m_field = e__common__o0000000, // 0
        .m_member = [](const common *cls) -> void * 
        {
            return (void *)std::addressof(cls->o0000000);
        },
    },
    {
        .m_variant = "o0000001",
        .m_type = "const char *",
        .m_flags = 0x80001,
        .m_field = e__common__o0000001, // 1
        .m_member = [](const common *cls) -> void * 
        {
            return (void *)std::addressof(cls->o0000001);
        },
    },
    {
        .m_variant = "o0000002",
        .m_type = "const char *",
        .m_flags = 0x80001,
        .m_field = e__common__o0000002, // 2
        .m_member = [](const common *cls) -> void * 
        {
            return (void *)std::addressof(cls->o0000002);
        },
    },
    {
        .m_variant = "o0000003",
        .m_type = "const char *",
        .m_flags = 0x80001,
        .m_field = e__common__o0000003, // 3
        .m_member = [](const common *cls) -> void * 
        {
            return (void *)std::addressof(cls->o0000003);
        },
    },
};


inline meta<common> &rfl__0__0(const common *cls, uint64_t value, branch_string &tag)
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
}

inline meta<common> &rfl__0__2(const common *cls, uint64_t value, branch_string &tag)
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
}

inline meta<common> &rfl__0__3(const common *cls, uint64_t value, branch_string &tag)
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
}

inline meta<common> &rfl__0__4(const common *cls, uint64_t value, branch_string &tag)
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
}

const uint64_t get_fields_max(const common *cls)
{
    return countof(g_common_meta);
}
namespace __details__
{    
    meta<common>& get_meta(const common *cls, branch_string &tag)
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
    meta<common>& get_meta(const common *cls, branch_string &tag, const std::string &args_tag)
    {
        return get_meta(cls, tag).m_invoke(cls, args_tag);    
    }    
}
void *get_value(const common *cls, const std::string &_tag)
{
    branch_string tag(_tag); 
    return __details__::get_meta(cls, tag).m_member(cls);
}
void *get_value(const common *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
void *get_value(const common *cls, const std::string &_tag, const char *expected_type)
{
    branch_string tag(_tag);
    auto _meta = __details__::get_meta(cls, tag);
    return (strcmp(expected_type, _meta.m_type) == 0) ? _meta.m_member(cls) : nullptr;
}
void *get_field_value(const common *cls, uint32_t field)
{
    if (field < get_fields_max(cls))
    {
        auto& _meta = g_common_meta[field];        
        return _meta.m_member(cls);
    }
    return nullptr;
}
const char* get_type(const common *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;
}
const char* get_type(const common *cls, const char *_tag) 
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;    
}
const char *get_type(const common *cls)
{
    static const char _class[] = "common";
    return _class;
}
uint64_t get_field(const common *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
uint64_t get_field(const common *cls, const char *_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
const char* get_name(const common *cls, uint32_t field)
{
    if (field < get_fields_max(cls))
    {
        return g_common_meta[field].m_variant;
    }
    return g_default_meta.m_variant;
}
meta<common> &get_meta(const common *cls)
{
    return g_common;
}

}
