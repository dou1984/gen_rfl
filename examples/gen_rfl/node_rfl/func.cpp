#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "../../node.h"
#include "func.h"
#include <gen_rfl/setter.h>
#include <gen_rfl/arguments.h>
#include <gen_rfl/item.h>


namespace reflect
{
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
    
    int invoke__func___deinit__3(const func* c, const Arguments *, ...);
    int invoke__func___deinit__3_v(func* c, const Arguments *, va_list);
    int invoke__func___deinit__2(const func* c, const Arguments *, ...);
    int invoke__func___deinit__2_v(func* c, const Arguments *, va_list);
    int invoke__func___done__4(const func* c, const Arguments *, ...);
    int invoke__func___done__4_v(func* c, const Arguments *, va_list);
    int invoke__func___init__1(const func* c, const Arguments *, ...);
    int invoke__func___init__1_v(func* c, const Arguments *, va_list);
    int invoke__func___init__0(const func* c, const Arguments *, ...);
    int invoke__func___init__0_v(func* c, const Arguments *, va_list);
    static meta<func> g_func_func[] = 
    {
        {
            .m_variant = "_deinit",
            .m_type = "@",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__func___deinit__3, // 3
            .m_func = invoke__func___deinit__3,
            .m_func_v = invoke__func___deinit__3_v,        
        },
        {
            .m_variant = "_deinit",
            .m_type = "int@",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__func___deinit__2, // 2
            .m_func = invoke__func___deinit__2,
            .m_func_v = invoke__func___deinit__2_v,        
        },
        {
            .m_variant = "_done",
            .m_type = "@",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__func___done__4, // 4
            .m_func = invoke__func___done__4,
            .m_func_v = invoke__func___done__4_v,        
        },
        {
            .m_variant = "_init",
            .m_type = "@",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__func___init__1, // 1
            .m_func = invoke__func___init__1,
            .m_func_v = invoke__func___init__1_v,        
        },
        {
            .m_variant = "_init",
            .m_type = "int@",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__func___init__0, // 0
            .m_func = invoke__func___init__0,
            .m_func_v = invoke__func___init__0_v,        
        },
    };
    
    reflect::meta<func>& invoke__func___deinit(const func *c, const std::list<Item> &tag);
    reflect::meta<func>& invoke__func___done(const func *c, const std::list<Item> &tag);
    reflect::meta<func>& invoke__func___init(const func *c, const std::list<Item> &tag);
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

    inline meta<func> &rfl__0__0(const func *cls, uint64_t value, branch_string &tag)
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
    inline meta<func> &rfl__0__2(const func *cls, uint64_t value, branch_string &tag)
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
    inline meta<func> &rfl__0__6(const func *cls, uint64_t value, branch_string &tag)
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
    int invoke__func___deinit__3_v(func *cls, const Arguments* argu, va_list __arguments_list)
    {
        cls->_deinit();
        return 0;
    }
    int invoke__func___deinit__3(const func *c, const Arguments* argu, ...)
    {
        auto *cls = (func *)(c); 
        if (cls && argu->m_arguments.size() == 0)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__func___deinit__3_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__func___deinit__2_v(func *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        _r = cls->_deinit();
        return 0;
    }
    int invoke__func___deinit__2(const func *c, const Arguments* argu, ...)
    {
        auto *cls = (func *)(c); 
        if (cls && argu->m_arguments.size() == 1)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__func___deinit__2_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<func>& invoke__func___deinit(const func *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 1) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
            };
            goto *__meta_label[l];    
        label__0:
        {
            static std::list<Item> l = {  };
            if (bra == l)
            {
                return g_func_func[e__func___deinit__3];
            }        
        }
            return g_default_meta;    
        label__1:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() } };
            if (bra == l)
            {
                return g_func_func[e__func___deinit__2];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__func___done__4_v(func *cls, const Arguments* argu, va_list __arguments_list)
    {
        cls->_done();
        return 0;
    }
    int invoke__func___done__4(const func *c, const Arguments* argu, ...)
    {
        auto *cls = (func *)(c); 
        if (cls && argu->m_arguments.size() == 0)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__func___done__4_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<func>& invoke__func___done(const func *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 0) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
            };
            goto *__meta_label[l];    
        label__0:
        {
            static std::list<Item> l = {  };
            if (bra == l)
            {
                return g_func_func[e__func___done__4];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__func___init__1_v(func *cls, const Arguments* argu, va_list __arguments_list)
    {
        cls->_init();
        return 0;
    }
    int invoke__func___init__1(const func *c, const Arguments* argu, ...)
    {
        auto *cls = (func *)(c); 
        if (cls && argu->m_arguments.size() == 0)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__func___init__1_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__func___init__0_v(func *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        _r = cls->_init();
        return 0;
    }
    int invoke__func___init__0(const func *c, const Arguments* argu, ...)
    {
        auto *cls = (func *)(c); 
        if (cls && argu->m_arguments.size() == 1)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__func___init__0_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<func>& invoke__func___init(const func *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 1) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
            };
            goto *__meta_label[l];    
        label__0:
        {
            static std::list<Item> l = {  };
            if (bra == l)
            {
                return g_func_func[e__func___init__1];
            }        
        }
            return g_default_meta;    
        label__1:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() } };
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
    namespace details
    {    
        meta<func> &get_meta(const func *cls, branch_string &tag)
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
    
        meta<func> &get_func(const func *cls, branch_string& tag, const std::list<Item>& args_tag)
        {
            auto &_meta = details::get_meta(cls, tag);
            if (__contains__(_meta.m_flags, flag_function))
            {
                auto &_invoke = _meta.m_invoke(cls, args_tag);
                if (__contains__(_invoke.m_flags, flag_argument))
                {           
                    return _invoke;
                }
            }
            return g_default_meta;
        }
        int get_base_func(const func *cls, const std::string& _tag, const Arguments *_, ...)
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
    Value get_value(const func *cls, const std::string &_tag)
    {
        branch_string tag(_tag); 
        auto& _meta = details::get_meta(cls, tag);
        if (__contains__(_meta.m_flags, flag_member))
        {
            return Value(_meta.m_getter(cls), _meta.m_t_flags);  
        }      
        return __get_value(cls, _tag);   
    }
    Value get_value(const func *cls, const char *tag)
    {
        return get_value(cls, std::string(tag));
    }
    Value get_field_value(const func *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_func_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return Value(_meta.m_getter(cls), _meta.m_t_flags);
            }
        }
        return reflect::Value(nullptr, reflect::e_nullptr);
    }
    const std::string &get_type(const func *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;
    }
    const std::string &get_type(const func *cls, const char *_tag) 
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;    
    }
    const std::string &get_type(func *cls)
    {   
        static const std::string _class = "func";
        return _class;
    }
    const std::string &get_type(const func *cls)
    {
        static const std::string _class = "func";
        return _class;
    }
    const std::string &get_typeid(const func *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;
    }
    const std::string &get_typeid(const func *cls)
    {
        static const std::string _class = typeid("func").name();
        return _class;
    }
    uint64_t get_field(const func *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    uint64_t get_field(const func *cls, const char *_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
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
    meta<func> &get_meta(const func *cls)
    {
        return g_func;
    }
}

