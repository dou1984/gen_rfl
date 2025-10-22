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
#include "base.h"
#include "../../node.h"

using namespace reflect;

enum base_meta_enum
{
    e__base__a,
    e__base__b,
    e__base__c,
    e__base__d,
    e__base__e,
    e__base__f,
    e__base__g,
    e__base__h,
    e__base__i,
    e__base__j,
    e__base__k,
    e__base__l,
    e__base__m,
    e__base__n,
    e__base__o,
    e__base__ooooooooooooooooooooooooooooo0,
    e__base__end,
};
enum base_func_enum
{
    e__base__func__end,
};
static meta<base> g_default_meta = {
    .m_variant = "",
    .m_type = "",
    .m_flags = __flags(flag_none),
    .m_field = UINT32_MAX,
    .m_member = [](const base *c) -> void* { return nullptr; },
};
static meta<base> g_base = {
    .m_variant = "base",
    .m_type = "base",
    .m_flags = __flags(flag_none),
    .m_field = UINT32_MAX,
    .m_member = [](const base *c) -> void* { return nullptr; },
};

static meta<base> g_base_func[] = 
{
};

static meta<base> g_base_meta[] = {
    {
        .m_variant = "a",
        .m_type = "signed char",
        .m_flags = 0x80001,
        .m_field = e__base__a, // 1
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->a);
        },
    },
    {
        .m_variant = "b",
        .m_type = "short",
        .m_flags = 0x80001,
        .m_field = e__base__b, // 2
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->b);
        },
    },
    {
        .m_variant = "c",
        .m_type = "int",
        .m_flags = 0x80001,
        .m_field = e__base__c, // 3
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->c);
        },
    },
    {
        .m_variant = "d",
        .m_type = "long",
        .m_flags = 0x80001,
        .m_field = e__base__d, // 4
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->d);
        },
    },
    {
        .m_variant = "e",
        .m_type = "unsigned char",
        .m_flags = 0x80001,
        .m_field = e__base__e, // 5
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->e);
        },
    },
    {
        .m_variant = "f",
        .m_type = "unsigned short",
        .m_flags = 0x80001,
        .m_field = e__base__f, // 6
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->f);
        },
    },
    {
        .m_variant = "g",
        .m_type = "unsigned int",
        .m_flags = 0x80001,
        .m_field = e__base__g, // 7
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->g);
        },
    },
    {
        .m_variant = "h",
        .m_type = "unsigned long",
        .m_flags = 0x80001,
        .m_field = e__base__h, // 0
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->h);
        },
    },
    {
        .m_variant = "i",
        .m_type = "float",
        .m_flags = 0x80001,
        .m_field = e__base__i, // 8
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->i);
        },
    },
    {
        .m_variant = "j",
        .m_type = "double",
        .m_flags = 0x80001,
        .m_field = e__base__j, // 9
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->j);
        },
    },
    {
        .m_variant = "k",
        .m_type = "std::string",
        .m_flags = 0x80001,
        .m_field = e__base__k, // 10
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->k);
        },
    },
    {
        .m_variant = "l",
        .m_type = "char *",
        .m_flags = 0x80001,
        .m_field = e__base__l, // 11
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->l);
        },
    },
    {
        .m_variant = "m",
        .m_type = "const char *",
        .m_flags = 0x80001,
        .m_field = e__base__m, // 12
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->m);
        },
    },
    {
        .m_variant = "n",
        .m_type = "std::map<int, int>",
        .m_flags = 0x80001,
        .m_field = e__base__n, // 13
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->n);
        },
    },
    {
        .m_variant = "o",
        .m_type = "std::vector<int>",
        .m_flags = 0x80001,
        .m_field = e__base__o, // 14
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->o);
        },
    },
    {
        .m_variant = "ooooooooooooooooooooooooooooo0",
        .m_type = "const char *",
        .m_flags = 0x80001,
        .m_field = e__base__ooooooooooooooooooooooooooooo0, // 15
        .m_member = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->ooooooooooooooooooooooooooooo0);
        },
    },
};


inline meta<base> &rfl__0__0(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x69 == value) // i
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__i];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__1(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x6a == value) // j
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__j];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__2(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x6b == value) // k
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__k];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__3(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x6c == value) // l
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__l];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__4(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x6d == value) // m
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__m];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__5(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x6e == value) // n
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__n];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__6(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x6f == value) // o
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__o];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__3__0(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x306f6f6f6f6f == value) // ooooo0
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__ooooooooooooooooooooooooooooo0];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__2__0(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x6f6f6f6f6f6f6f6f == value) // oooooooo
    {
        if (tag) // incomplete_eq_1
        {
            auto _value = tag();
            return rfl__3__0(cls, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<base> &rfl__1__0(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x6f6f6f6f6f6f6f6f == value) // oooooooo
    {
        if (tag) // incomplete_eq_1
        {
            auto _value = tag();
            return rfl__2__0(cls, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__9(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x6f6f6f6f6f6f6f6f == value) // oooooooo
    {
        if (tag) // incomplete_eq_1
        {
            auto _value = tag();
            return rfl__1__0(cls, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__13(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x61 == value) // a
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__a];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__14(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x62 == value) // b
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__b];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__15(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x63 == value) // c
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__c];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__16(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x64 == value) // d
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__d];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__17(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x65 == value) // e
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__e];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__18(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x66 == value) // f
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__f];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__19(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x67 == value) // g
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__g];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<base> &rfl__0__20(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x68 == value) // h
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__h];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

const uint64_t get_fields_max(const base *cls)
{
    return countof(g_base_meta);
}
namespace __details__
{    
    meta<base>& get_meta(const base *cls, branch_string &tag)
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
            &&label__0__19,
            &&label__0__20,
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
    label__0__3:
        return rfl__0__3(cls, value, tag);
    label__0__4:
        return rfl__0__4(cls, value, tag);
    label__0__5:
        return rfl__0__5(cls, value, tag);
    label__0__6:
        return rfl__0__6(cls, value, tag);
    label__0__9:
        return rfl__0__9(cls, value, tag);
    label__0__13:
        return rfl__0__13(cls, value, tag);
    label__0__14:
        return rfl__0__14(cls, value, tag);
    label__0__15:
        return rfl__0__15(cls, value, tag);
    label__0__16:
        return rfl__0__16(cls, value, tag);
    label__0__17:
        return rfl__0__17(cls, value, tag);
    label__0__18:
        return rfl__0__18(cls, value, tag);
    label__0__19:
        return rfl__0__19(cls, value, tag);
    label__0__20:
        return rfl__0__20(cls, value, tag);
    label__0__7:
    label__0__8:
    label__0__10:
    label__0__11:
    label__0__12:
        return g_default_meta;
    }
    meta<base>& get_meta(const base *cls, branch_string &tag, const std::string &args_tag)
    {
        return get_meta(cls, tag).m_invoke(cls, args_tag);    
    }    
}
void *get_value(const base *cls, const std::string &_tag)
{
    branch_string tag(_tag); 
    return __details__::get_meta(cls, tag).m_member(cls);
}
void *get_value(const base *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
void *get_value(const base *cls, const std::string &_tag, const char *expected_type)
{
    branch_string tag(_tag);
    auto _meta = __details__::get_meta(cls, tag);
    return (strcmp(expected_type, _meta.m_type) == 0) ? _meta.m_member(cls) : nullptr;
}
void *get_field_value(const base *cls, uint32_t field)
{
    if (field < get_fields_max(cls))
    {
        auto& _meta = g_base_meta[field];        
        return _meta.m_member(cls);
    }
    return nullptr;
}
const char* get_type(const base *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;
}
const char* get_type(const base *cls, const char *_tag) 
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;    
}
const char *get_type(const base *cls)
{
    static const char _class[] = "base";
    return _class;
}
uint64_t get_field(const base *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
uint64_t get_field(const base *cls, const char *_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
const char* get_name(const base *cls, uint32_t field)
{
    if (field < get_fields_max(cls))
    {
        return g_base_meta[field].m_variant;
    }
    return g_default_meta.m_variant;
}
meta<base> &get_meta(const base *cls)
{
    return g_base;
}

