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
#include <gen_rfl/setter.h>
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
    e__base__ooooooooooooooooooooooooooool0,
    e__base__end,
};
enum base_func_enum
{
    e__base__func__end,
};
static int set_value_invalid(base *cls, uint32_t, ...)
{
    return 0;
}
static meta<base> g_default_meta = {
    .m_variant = "",
    .m_type = "",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const base *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};
static meta<base> g_base = {
    .m_variant = "base",
    .m_type = "",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const base *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};

int setter__base__a(base* c, uint32_t argc, ...);
int setter__base__b(base* c, uint32_t argc, ...);
int setter__base__c(base* c, uint32_t argc, ...);
int setter__base__d(base* c, uint32_t argc, ...);
int setter__base__e(base* c, uint32_t argc, ...);
int setter__base__f(base* c, uint32_t argc, ...);
int setter__base__g(base* c, uint32_t argc, ...);
int setter__base__h(base* c, uint32_t argc, ...);
int setter__base__i(base* c, uint32_t argc, ...);
int setter__base__j(base* c, uint32_t argc, ...);
int setter__base__k(base* c, uint32_t argc, ...);
int setter__base__l(base* c, uint32_t argc, ...);
int setter__base__m(base* c, uint32_t argc, ...);
int setter__base__n(base* c, uint32_t argc, ...);
int setter__base__o(base* c, uint32_t argc, ...);
int setter__base__ooooooooooooooooooooooooooool0(base* c, uint32_t argc, ...);
static meta<base> g_base_func[] = 
{
};

static meta<base> g_base_meta[] = {
    {
        .m_variant = "a",
        .m_type =  "signed char",
        .m_flags = 0x801,
        .m_t_flags = flag_type<signed char>(),
        .m_field = e__base__a, // 0
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->a);
        },
        .m_setter = setter__base__a,
    },
    {
        .m_variant = "b",
        .m_type =  "short",
        .m_flags = 0x801,
        .m_t_flags = flag_type<short>(),
        .m_field = e__base__b, // 1
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->b);
        },
        .m_setter = setter__base__b,
    },
    {
        .m_variant = "c",
        .m_type =  "int",
        .m_flags = 0x801,
        .m_t_flags = flag_type<int>(),
        .m_field = e__base__c, // 2
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->c);
        },
        .m_setter = setter__base__c,
    },
    {
        .m_variant = "d",
        .m_type =  "long",
        .m_flags = 0x801,
        .m_t_flags = flag_type<long>(),
        .m_field = e__base__d, // 3
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->d);
        },
        .m_setter = setter__base__d,
    },
    {
        .m_variant = "e",
        .m_type =  "unsigned char",
        .m_flags = 0x801,
        .m_t_flags = flag_type<unsigned char>(),
        .m_field = e__base__e, // 4
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->e);
        },
        .m_setter = setter__base__e,
    },
    {
        .m_variant = "f",
        .m_type =  "unsigned short",
        .m_flags = 0x801,
        .m_t_flags = flag_type<unsigned short>(),
        .m_field = e__base__f, // 5
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->f);
        },
        .m_setter = setter__base__f,
    },
    {
        .m_variant = "g",
        .m_type =  "unsigned int",
        .m_flags = 0x801,
        .m_t_flags = flag_type<unsigned int>(),
        .m_field = e__base__g, // 6
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->g);
        },
        .m_setter = setter__base__g,
    },
    {
        .m_variant = "h",
        .m_type =  "unsigned long",
        .m_flags = 0x801,
        .m_t_flags = flag_type<unsigned long>(),
        .m_field = e__base__h, // 7
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->h);
        },
        .m_setter = setter__base__h,
    },
    {
        .m_variant = "i",
        .m_type =  "float",
        .m_flags = 0x801,
        .m_t_flags = flag_type<float>(),
        .m_field = e__base__i, // 8
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->i);
        },
        .m_setter = setter__base__i,
    },
    {
        .m_variant = "j",
        .m_type =  "double",
        .m_flags = 0x801,
        .m_t_flags = flag_type<double>(),
        .m_field = e__base__j, // 9
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->j);
        },
        .m_setter = setter__base__j,
    },
    {
        .m_variant = "k",
        .m_type =  "std::string",
        .m_flags = 0x801,
        .m_t_flags = flag_type<std::string>(),
        .m_field = e__base__k, // 10
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->k);
        },
        .m_setter = setter__base__k,
    },
    {
        .m_variant = "l",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__base__l, // 11
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->l);
        },
        .m_setter = setter__base__l,
    },
    {
        .m_variant = "m",
        .m_type =  "const char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<const char *>(),
        .m_field = e__base__m, // 12
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->m);
        },
        .m_setter = setter__base__m,
    },
    {
        .m_variant = "n",
        .m_type =  "std::map<int, int>",
        .m_flags = 0x801,
        .m_t_flags = flag_type<std::map<int, int>>(),
        .m_field = e__base__n, // 13
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->n);
        },
        .m_setter = setter__base__n,
    },
    {
        .m_variant = "o",
        .m_type =  "std::vector<int>",
        .m_flags = 0x801,
        .m_t_flags = flag_type<std::vector<int>>(),
        .m_field = e__base__o, // 14
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->o);
        },
        .m_setter = setter__base__o,
    },
    {
        .m_variant = "ooooooooooooooooooooooooooool0",
        .m_type =  "const char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<const char *>(),
        .m_field = e__base__ooooooooooooooooooooooooooool0, // 15
        .m_getter = [](const base *cls) -> void * 
        {
            return (void *)std::addressof(cls->ooooooooooooooooooooooooooool0);
        },
        .m_setter = setter__base__ooooooooooooooooooooooooooool0,
    },
};
reflect::Value __get_value(const base* cls, const std::string& _tag)
{
    return reflect::Value(nullptr, 0);
}

int setter__base__i(base* c, uint32_t _flag, ...)
{    
    SETTER(c->i, _flag);
    return 0;
}

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

int setter__base__j(base* c, uint32_t _flag, ...)
{    
    SETTER(c->j, _flag);
    return 0;
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

int setter__base__k(base* c, uint32_t _flag, ...)
{    
    SETTER(c->k, _flag);
    return 0;
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

int setter__base__l(base* c, uint32_t _flag, ...)
{    
    SETTER(c->l, _flag);
    return 0;
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

int setter__base__m(base* c, uint32_t _flag, ...)
{    
    SETTER(c->m, _flag);
    return 0;
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

int setter__base__n(base* c, uint32_t _flag, ...)
{    
    SETTER(c->n, _flag);
    return 0;
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

int setter__base__o(base* c, uint32_t _flag, ...)
{    
    SETTER(c->o, _flag);
    return 0;
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

int setter__base__ooooooooooooooooooooooooooool0(base* c, uint32_t _flag, ...)
{    
    SETTER(c->ooooooooooooooooooooooooooool0, _flag);
    return 0;
}

inline meta<base> &rfl__3__0(const base *cls, uint64_t value, branch_string &tag)
{
    if (0x306c6f6f6f6f == value) // ooool0
    {
        if (!tag) // complete
        {
            return g_base_meta[e__base__ooooooooooooooooooooooooooool0];
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

int setter__base__a(base* c, uint32_t _flag, ...)
{    
    SETTER(c->a, _flag);
    return 0;
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

int setter__base__b(base* c, uint32_t _flag, ...)
{    
    SETTER(c->b, _flag);
    return 0;
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

int setter__base__c(base* c, uint32_t _flag, ...)
{    
    SETTER(c->c, _flag);
    return 0;
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

int setter__base__d(base* c, uint32_t _flag, ...)
{    
    SETTER(c->d, _flag);
    return 0;
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

int setter__base__e(base* c, uint32_t _flag, ...)
{    
    SETTER(c->e, _flag);
    return 0;
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

int setter__base__f(base* c, uint32_t _flag, ...)
{    
    SETTER(c->f, _flag);
    return 0;
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

int setter__base__g(base* c, uint32_t _flag, ...)
{    
    SETTER(c->g, _flag);
    return 0;
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

int setter__base__h(base* c, uint32_t _flag, ...)
{    
    SETTER(c->h, _flag);
    return 0;
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
reflect::Value get_value(const base *cls, const std::string &_tag)
{
    branch_string tag(_tag); 
    auto _meta = __details__::get_meta(cls, tag);
    if (__contains__(_meta.m_flags, flag_member))
    {
        return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);  
    }      
    return __get_value(cls, _tag);   
}
reflect::Value get_value(const base *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
reflect::Value get_value(const base *cls, const std::string &_tag, const char *expected_type)
{
    branch_string tag(_tag);
    auto _meta = __details__::get_meta(cls, tag);
    if  (strcmp(expected_type, _meta.m_type) == 0) 
    {
        return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);    
    }
    return reflect::Value(nullptr, 0);
}
reflect::Value get_field_value(const base *cls, uint32_t field)
{
    if (field < get_fields_max(cls))
    {
        auto& _meta = g_base_meta[field];        
        return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);        
    }
    return reflect::Value(nullptr, 0);
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

