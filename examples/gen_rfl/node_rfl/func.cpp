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
    e__func___deinit,
    e__func___done,
    e__func___init,
    e__func__end,
};
enum func_func_enum
{
    e__func___deinit__3,
    e__func___deinit__2,
    e__func___done__4,
    e__func___init__1,
    e__func___init__0,
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

int invoke__func___deinit__3(const func* c, const reflect::Arguments *, ...);
int invoke__func___deinit__2(const func* c, const reflect::Arguments *, ...);
int invoke__func___done__4(const func* c, const reflect::Arguments *, ...);
int invoke__func___init__1(const func* c, const reflect::Arguments *, ...);
int invoke__func___init__0(const func* c, const reflect::Arguments *, ...);
static reflect::meta<func> g_func_func[] = 
{
    {
        .m_variant = "_deinit",
        .m_type = "@",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func___deinit__3, // 3
        .m_func = invoke__func___deinit__3,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "_deinit",
        .m_type = "int@",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func___deinit__2, // 2
        .m_func = invoke__func___deinit__2,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "_done",
        .m_type = "@",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func___done__4, // 4
        .m_func = invoke__func___done__4,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "_init",
        .m_type = "@",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func___init__1, // 1
        .m_func = invoke__func___init__1,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "_init",
        .m_type = "int@",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__func___init__0, // 0
        .m_func = invoke__func___init__0,
        .m_setter = set_value_invalid,
    },
};

reflect::meta<func>& invoke__func___deinit(const func *c, const std::list<std::string> &tag);
reflect::meta<func>& invoke__func___done(const func *c, const std::list<std::string> &tag);
reflect::meta<func>& invoke__func___init(const func *c, const std::list<std::string> &tag);
static reflect::meta<func> g_func_meta[] = {
{
    .m_variant = "_deinit",
    .m_type = "",
    .m_flags = 0x4801,
    .m_t_flags = 0x0,
    .m_field = e__func___deinit, // 1
    .m_invoke = invoke__func___deinit,
    .m_setter = set_value_invalid,
},
{
    .m_variant = "_done",
    .m_type = "",
    .m_flags = 0x4801,
    .m_t_flags = 0x0,
    .m_field = e__func___done, // 2
    .m_invoke = invoke__func___done,
    .m_setter = set_value_invalid,
},
{
    .m_variant = "_init",
    .m_type = "",
    .m_flags = 0x4801,
    .m_t_flags = 0x0,
    .m_field = e__func___init, // 0
    .m_invoke = invoke__func___init,
    .m_setter = set_value_invalid,
},
};
reflect::Value __get_value(const func* cls, const std::string& _tag)
{
    return reflect::Value(nullptr, reflect::e_nullptr);
}
inline ::reflect::meta<func> &rfl__0__0(const func *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x74696e6965645f == value) // _deinit
    {
        if (!tag) // complete
        {
            return g_func_meta[e__func___deinit];
        }
        return g_default_meta;
    }
    return g_default_meta;
}
inline ::reflect::meta<func> &rfl__0__2(const func *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x74696e695f == value) // _init
    {
        if (!tag) // complete
        {
            return g_func_meta[e__func___init];
        }
        return g_default_meta;
    }
    return g_default_meta;
}
inline ::reflect::meta<func> &rfl__0__6(const func *cls, uint64_t value, ::reflect::branch_string &tag)
{
    if (0x656e6f645f == value) // _done
    {
        if (!tag) // complete
        {
            return g_func_meta[e__func___done];
        }
        return g_default_meta;
    }
    return g_default_meta;
}
int invoke__func___deinit__3(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_arguments.size() == 0)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        cls->_deinit();
        va_end(__arguments_list);
        return 0;
    }
    return -1;
}
int invoke__func___deinit__2(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_arguments.size() == 1)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        auto& _r = *(va_arg(__arguments_list, int *));
        _r = cls->_deinit();
        va_end(__arguments_list);
        return 0;
    }
    return -1;
}
::reflect::meta<func>& invoke__func___deinit(const func *c, const std::list<std::string> &bra)
{
    if (bra.size() == 0)
    {
        {
            static std::list<std::string> l = {  };
            if (bra == l)
            {
                return g_func_func[e__func___deinit__3];
            }
        }
        return g_default_meta;
    }
    if (bra.size() == 1)
    {
        {
            static std::list<std::string> l = { "int@" };
            if (bra == l)
            {
                return g_func_func[e__func___deinit__2];
            }
        }
        return g_default_meta;
    }
    return g_default_meta;
}
int invoke__func___done__4(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_arguments.size() == 0)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        cls->_done();
        va_end(__arguments_list);
        return 0;
    }
    return -1;
}
::reflect::meta<func>& invoke__func___done(const func *c, const std::list<std::string> &bra)
{
    if (bra.size() == 0)
    {
        {
            static std::list<std::string> l = {  };
            if (bra == l)
            {
                return g_func_func[e__func___done__4];
            }
        }
        return g_default_meta;
    }
    return g_default_meta;
}
int invoke__func___init__1(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_arguments.size() == 0)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        cls->_init();
        va_end(__arguments_list);
        return 0;
    }
    return -1;
}
int invoke__func___init__0(const func *c, const reflect::Arguments* argu, ...)
{
    auto *cls = (func *)(c); 
    if (cls && argu->m_arguments.size() == 1)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argu);
        auto& _r = *(va_arg(__arguments_list, int *));
        _r = cls->_init();
        va_end(__arguments_list);
        return 0;
    }
    return -1;
}
::reflect::meta<func>& invoke__func___init(const func *c, const std::list<std::string> &bra)
{
    if (bra.size() == 0)
    {
        {
            static std::list<std::string> l = {  };
            if (bra == l)
            {
                return g_func_func[e__func___init__1];
            }
        }
        return g_default_meta;
    }
    if (bra.size() == 1)
    {
        {
            static std::list<std::string> l = { "int@" };
            if (bra == l)
            {
                return g_func_func[e__func___init__0];
            }
        }
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
    label__0__0:
        return rfl__0__0(cls, value, tag);
    label__0__2:
        return rfl__0__2(cls, value, tag);
    label__0__6:
        return rfl__0__6(cls, value, tag);
    label__0__1:
    label__0__3:
    label__0__4:
    label__0__5:
        return g_default_meta;
    }
    ::reflect::meta<func> &get_meta(const func *cls, ::reflect::branch_string& tag, const std::list<std::string>& args_tag)
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

