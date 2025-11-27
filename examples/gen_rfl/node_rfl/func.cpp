#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "func.h"
#include "../../node.h"
#include <gen_rfl/setter.h>
#include <gen_rfl/arguments.h>


enum func_meta_enum
{
    e__func__deinit,
    e__func__done,
    e__func__init,
    e__func__end,
};
enum func_func_enum
{
    e__func__deinit__3,
    e__func__deinit__2,
    e__func__done__4,
    e__func__init__1,
    e__func__init__0,
    e__func__func__end,
};
static int set_value_invalid(func *cls, uint32_t, ...)
{
    return 0;
}
static reflect::meta<func> g_default_meta = {
    .m_variant = "",
    .m_type = "",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const func *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};
static reflect::meta<func> g_func = {
    .m_variant = "func",
    .m_type = "",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const func *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};

int invoke__func__deinit__3(const func* c, const reflect::Arguments *, ...);
int invoke__func__deinit__2(const func* c, const reflect::Arguments *, ...);
int invoke__func__done__4(const func* c, const reflect::Arguments *, ...);
int invoke__func__init__1(const func* c, const reflect::Arguments *, ...);
int invoke__func__init__0(const func* c, const reflect::Arguments *, ...);
static reflect::meta<func> g_func_func[] = 
{
    {
        .m_variant = "deinit",
        .m_type = "()",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func__deinit__3, // 3
        .m_func = invoke__func__deinit__3,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "deinit",
        .m_type = "int()",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func__deinit__2, // 2
        .m_func = invoke__func__deinit__2,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "done",
        .m_type = "()",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func__done__4, // 4
        .m_func = invoke__func__done__4,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "init",
        .m_type = "()",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func__init__1, // 1
        .m_func = invoke__func__init__1,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "init",
        .m_type = "int()",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func__init__0, // 0
        .m_func = invoke__func__init__0,
        .m_setter = set_value_invalid,
    },
};

reflect::meta<func>& invoke__func__deinit(const func *c, const std::string &tag);
reflect::meta<func>& invoke__func__done(const func *c, const std::string &tag);
reflect::meta<func>& invoke__func__init(const func *c, const std::string &tag);
static reflect::meta<func> g_func_meta[] = {
{
    .m_variant = "deinit",
    .m_type = "",
    .m_flags = 0x4801,
    .m_t_flags = 0x0,
    .m_field = e__func__deinit, // 1
    .m_invoke = invoke__func__deinit,
    .m_setter = set_value_invalid,
},
{
    .m_variant = "done",
    .m_type = "",
    .m_flags = 0x4801,
    .m_t_flags = 0x0,
    .m_field = e__func__done, // 2
    .m_invoke = invoke__func__done,
    .m_setter = set_value_invalid,
},
{
    .m_variant = "init",
    .m_type = "",
    .m_flags = 0x4801,
    .m_t_flags = 0x0,
    .m_field = e__func__init, // 0
    .m_invoke = invoke__func__init,
    .m_setter = set_value_invalid,
},
};
reflect::Value __get_value(const func* cls, const std::string& _tag)
{
    return reflect::Value(nullptr, reflect::e_nullptr);
}inline ::reflect::meta<func> &rfl__0__3(const func *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x74696e69 == value) // init
    {
        if (!tag) // complete
        {
            return g_func_meta[e__func__init];
        }
        return g_default_meta;
    }
    return g_default_meta;
}inline ::reflect::meta<func> &rfl__0__4(const func *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x656e6f64 == value) // done
    {
        if (!tag) // complete
        {
            return g_func_meta[e__func__done];
        }
        return g_default_meta;
    }
    return g_default_meta;
}inline ::reflect::meta<func> &rfl__0__6(const func *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x74696e696564 == value) // deinit
    {
        if (!tag) // complete
        {
            return g_func_meta[e__func__deinit];
        }
        return g_default_meta;
    }
    return g_default_meta;
}int invoke__func__deinit__3(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_count == 0)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        va_end(__arguments_list);
        cls->deinit();
        return 0;
    }
    return -1;
}
inline ::reflect::meta<func> &invoke__deinit__0__0(const func *c, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x2928 == value) // ()
    {
        if (!tag)
        {
            return g_func_func[e__func__deinit__3];
        }
        return g_default_meta;
    }
    return g_default_meta;
}
int invoke__func__deinit__2(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_count == 1)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        auto& _r = *(va_arg(__arguments_list, int *));
        va_end(__arguments_list);
        _r = cls->deinit();
        return 0;
    }
    return -1;
}
inline ::reflect::meta<func> &invoke__deinit__0__1(const func *c, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x2928746e69 == value) // int()
    {
        if (!tag)
        {
            return g_func_func[e__func__deinit__2];
        }
        return g_default_meta;
    }
    return g_default_meta;
}
::reflect::meta<func>& invoke__func__deinit(const func *c, const std::string &bra)
{
    ::reflect::branch_string tag(bra);
    if (tag)
    {
        constexpr void *__meta_label[] = {
            &&label_0,
            &&label_1,
            &&label_2,
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];
    label_0:
        return invoke__deinit__0__0(c, _value, tag);
    label_1:
        return invoke__deinit__0__1(c, _value, tag);
    label_2:
        return g_default_meta;
    }
    return g_default_meta;
}
int invoke__func__done__4(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_count == 0)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        va_end(__arguments_list);
        cls->done();
        return 0;
    }
    return -1;
}
inline ::reflect::meta<func> &invoke__done__0__3(const func *c, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x2928 == value) // ()
    {
        if (!tag)
        {
            return g_func_func[e__func__done__4];
        }
        return g_default_meta;
    }
    return g_default_meta;
}
::reflect::meta<func>& invoke__func__done(const func *c, const std::string &bra)
{
    ::reflect::branch_string tag(bra);
    if (tag)
    {
        auto _value = tag();
        return invoke__done__0__3(c, _value, tag);
    }
    return g_default_meta;
}
int invoke__func__init__1(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_count == 0)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        va_end(__arguments_list);
        cls->init();
        return 0;
    }
    return -1;
}
inline ::reflect::meta<func> &invoke__init__0__4(const func *c, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x2928 == value) // ()
    {
        if (!tag)
        {
            return g_func_func[e__func__init__1];
        }
        return g_default_meta;
    }
    return g_default_meta;
}
int invoke__func__init__0(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_count == 1)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        auto& _r = *(va_arg(__arguments_list, int *));
        va_end(__arguments_list);
        _r = cls->init();
        return 0;
    }
    return -1;
}
inline ::reflect::meta<func> &invoke__init__0__5(const func *c, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x2928746e69 == value) // int()
    {
        if (!tag)
        {
            return g_func_func[e__func__init__0];
        }
        return g_default_meta;
    }
    return g_default_meta;
}
::reflect::meta<func>& invoke__func__init(const func *c, const std::string &bra)
{
    ::reflect::branch_string tag(bra);
    if (tag)
    {
        constexpr void *__meta_label[] = {
            &&label_4,
            &&label_5,
            &&label_6,
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];
    label_4:
        return invoke__init__0__4(c, _value, tag);
    label_5:
        return invoke__init__0__5(c, _value, tag);
    label_6:
        return g_default_meta;
    }
    return g_default_meta;
}
const uint64_t get_fields_count(const func *cls)
{
    return countof(g_func_meta);
}
namespace __details__
{    
    ::reflect::meta<func>& get_meta(const func *cls, ::reflect::branch_string &tag)
    {
        constexpr void *__meta_label[] = {
            &&label__0__0,
            &&label__0__1,
            &&label__0__2,
            &&label__0__3,
            &&label__0__4,
            &&label__0__5,
            &&label__0__6,
        };
        constexpr auto count = countof(__meta_label);
        auto value = tag();
        auto index = value % count;        
        goto *__meta_label[index];
    label__0__3:
        return rfl__0__3(cls, value, tag);
    label__0__4:
        return rfl__0__4(cls, value, tag);
    label__0__6:
        return rfl__0__6(cls, value, tag);
    label__0__0:
    label__0__1:
    label__0__2:
    label__0__5:
        return g_default_meta;
    }
    ::reflect::meta<func>& get_meta(const func *cls, ::reflect::branch_string &tag, const std::string &args_tag)
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
::reflect::Value get_value(const func *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag); 
    auto& _meta = __details__::get_meta(cls, tag);
    if (::reflect::__contains__(_meta.m_flags, ::reflect::flag_member))
    {
        return ::reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);  
    }      
    return __get_value(cls, _tag);   
}
::reflect::Value get_value(const func *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
::reflect::Value get_field_value(const func *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        auto& _meta = g_func_meta[field]; 
        if (_meta.m_t_flags != 0)
        {
            return ::reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);
        }
    }
    return reflect::Value(nullptr, reflect::e_nullptr);
}
const std::string &get_type(const func *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;
}
const std::string &get_type(const func *cls, const char *_tag) 
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;    
}
const std::string &get_type(const func *cls)
{
    static const std::string _class = "func";
    return _class;
}
uint64_t get_field(const func *cls, const std::string &_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
uint64_t get_field(const func *cls, const char *_tag)
{
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
const std::string &get_field_type(const func *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        auto& _meta = g_func_meta[field]; 
        if (_meta.m_t_flags != 0)
        {
            return _meta.m_type;
        }
    }
    static std::string _ = "";
    return _;
}
const std::string &get_name(const func *cls, uint32_t field)
{
    if (field < get_fields_count(cls))
    {
        return g_func_meta[field].m_variant;
    }
    return g_default_meta.m_variant;
}
::reflect::meta<func> &get_meta(const func *cls)
{
    return g_func;
}
