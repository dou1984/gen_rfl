#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "../../node.h"
#include "base.h"
#include "config.h"
#include "func.h"
#include "node.h"
#include <gen_rfl/setter.h>
#include <gen_rfl/arguments.h>
#include <gen_rfl/item.h>


namespace reflect
{
    enum node_meta_enum
    {
        e__node__base,
        e__node__config,
        e__node__deinit,
        e__node__func,
        e__node__init,
        e__node__lllllllllllllllllllllllllll0,
        e__node__lllllllllllllllllllllllllll1,
        e__node__lllllllllllllllllllllllllll2,
        e__node__lllllllllllllllllllllllllll3,
        e__node__lllllllllllllllllllllllllll4,
        e__node__lllllllllllllllllllllllllll5,
        e__node__lllllllllllllllllllllllllll6,
        e__node__oooo19,
        e__node__oooo20,
        e__node__oooooo21,
        e__node__oooooo22,
        e__node__oooooo23,
        e__node__oooooo24,
        e__node__oooooo25,
        e__node__oooooooo10,
        e__node__oooooooo11,
        e__node__ooooooooo9,
        e__node__oooooooooooooo12,
        e__node__oooooooooooooo18,
        e__node__oooooooooooooo8,
        e__node__ooooooooooooooo17,
        e__node__ooooooooooooooo7,
        e__node__ooooooooooooooooooooo16,
        e__node__ooooooooooooooooooooooo6,
        e__node__oooooooooooooooooooooooooo0,
        e__node__oooooooooooooooooooooooooo1,
        e__node__oooooooooooooooooooooooooo14,
        e__node__oooooooooooooooooooooooooo2,
        e__node__oooooooooooooooooooooooooo3,
        e__node__oooooooooooooooooooooooooo4,
        e__node__oooooooooooooooooooooooooo5,
        e__node__ooooooooooooooooooooooooooo13,
        e__node__ooooooooooooooooooooooooooo15,
        e__node__end,
    };
    enum node_func_enum
    {
        e__node__deinit__7,
        e__node__deinit__6,
        e__node__init__5,
        e__node__init__3,
        e__node__init__1,
        e__node__init__4,
        e__node__init__2,
        e__node__init__0,
        e__node__lllllllllllllllllllllllllll0__9,
        e__node__lllllllllllllllllllllllllll0__8,
        e__node__lllllllllllllllllllllllllll1__11,
        e__node__lllllllllllllllllllllllllll1__10,
        e__node__lllllllllllllllllllllllllll2__13,
        e__node__lllllllllllllllllllllllllll2__12,
        e__node__lllllllllllllllllllllllllll3__15,
        e__node__lllllllllllllllllllllllllll3__14,
        e__node__lllllllllllllllllllllllllll4__17,
        e__node__lllllllllllllllllllllllllll4__16,
        e__node__lllllllllllllllllllllllllll5__19,
        e__node__lllllllllllllllllllllllllll5__18,
        e__node__lllllllllllllllllllllllllll6__23,
        e__node__lllllllllllllllllllllllllll6__21,
        e__node__lllllllllllllllllllllllllll6__22,
        e__node__lllllllllllllllllllllllllll6__20,
        e__node__func__end,
    };
    static int set_value_invalid(node *cls, uint32_t, ...)
    {
        return 0;
    }
    static reflect::meta<node> g_default_meta = {
        .m_variant = "",
        .m_type = "",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const node *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    static reflect::meta<node> g_node = {
        .m_variant = "node",
        .m_type = "",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const node *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    
    int invoke__node__deinit__7(const node* c, const Arguments *, ...);
    int invoke__node__deinit__7_v(node* c, const Arguments *, va_list);
    int invoke__node__deinit__6(const node* c, const Arguments *, ...);
    int invoke__node__deinit__6_v(node* c, const Arguments *, va_list);
    int invoke__node__init__5(const node* c, const Arguments *, ...);
    int invoke__node__init__5_v(node* c, const Arguments *, va_list);
    int invoke__node__init__3(const node* c, const Arguments *, ...);
    int invoke__node__init__3_v(node* c, const Arguments *, va_list);
    int invoke__node__init__1(const node* c, const Arguments *, ...);
    int invoke__node__init__1_v(node* c, const Arguments *, va_list);
    int invoke__node__init__4(const node* c, const Arguments *, ...);
    int invoke__node__init__4_v(node* c, const Arguments *, va_list);
    int invoke__node__init__2(const node* c, const Arguments *, ...);
    int invoke__node__init__2_v(node* c, const Arguments *, va_list);
    int invoke__node__init__0(const node* c, const Arguments *, ...);
    int invoke__node__init__0_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll0__9(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll0__9_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll0__8(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll0__8_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll1__11(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll1__11_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll1__10(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll1__10_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll2__13(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll2__13_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll2__12(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll2__12_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll3__15(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll3__15_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll3__14(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll3__14_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll4__17(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll4__17_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll4__16(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll4__16_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll5__19(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll5__19_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll5__18(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll5__18_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll6__23(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll6__23_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll6__21(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll6__21_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll6__22(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll6__22_v(node* c, const Arguments *, va_list);
    int invoke__node__lllllllllllllllllllllllllll6__20(const node* c, const Arguments *, ...);
    int invoke__node__lllllllllllllllllllllllllll6__20_v(node* c, const Arguments *, va_list);
    static meta<node> g_node_func[] = 
    {
        {
            .m_variant = "deinit",
            .m_type = "@",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__deinit__7, // 7
            .m_func = invoke__node__deinit__7,
            .m_func_v = invoke__node__deinit__7_v,        
        },
        {
            .m_variant = "deinit",
            .m_type = "int@",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__deinit__6, // 6
            .m_func = invoke__node__deinit__6,
            .m_func_v = invoke__node__deinit__6_v,        
        },
        {
            .m_variant = "init",
            .m_type = "@",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__init__5, // 5
            .m_func = invoke__node__init__5,
            .m_func_v = invoke__node__init__5_v,        
        },
        {
            .m_variant = "init",
            .m_type = "@float,double,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__init__3, // 3
            .m_func = invoke__node__init__3,
            .m_func_v = invoke__node__init__3_v,        
        },
        {
            .m_variant = "init",
            .m_type = "@int,long long,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__init__1, // 1
            .m_func = invoke__node__init__1,
            .m_func_v = invoke__node__init__1_v,        
        },
        {
            .m_variant = "init",
            .m_type = "int@",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__init__4, // 4
            .m_func = invoke__node__init__4,
            .m_func_v = invoke__node__init__4_v,        
        },
        {
            .m_variant = "init",
            .m_type = "int@float,double,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__init__2, // 2
            .m_func = invoke__node__init__2,
            .m_func_v = invoke__node__init__2_v,        
        },
        {
            .m_variant = "init",
            .m_type = "int@int,long long,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__init__0, // 0
            .m_func = invoke__node__init__0,
            .m_func_v = invoke__node__init__0_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll0",
            .m_type = "@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll0__9, // 9
            .m_func = invoke__node__lllllllllllllllllllllllllll0__9,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll0__9_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll0",
            .m_type = "int@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll0__8, // 8
            .m_func = invoke__node__lllllllllllllllllllllllllll0__8,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll0__8_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll1",
            .m_type = "@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll1__11, // 11
            .m_func = invoke__node__lllllllllllllllllllllllllll1__11,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll1__11_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll1",
            .m_type = "int@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll1__10, // 10
            .m_func = invoke__node__lllllllllllllllllllllllllll1__10,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll1__10_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll2",
            .m_type = "@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll2__13, // 13
            .m_func = invoke__node__lllllllllllllllllllllllllll2__13,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll2__13_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll2",
            .m_type = "int@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll2__12, // 12
            .m_func = invoke__node__lllllllllllllllllllllllllll2__12,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll2__12_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll3",
            .m_type = "@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll3__15, // 15
            .m_func = invoke__node__lllllllllllllllllllllllllll3__15,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll3__15_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll3",
            .m_type = "int@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll3__14, // 14
            .m_func = invoke__node__lllllllllllllllllllllllllll3__14,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll3__14_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll4",
            .m_type = "@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll4__17, // 17
            .m_func = invoke__node__lllllllllllllllllllllllllll4__17,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll4__17_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll4",
            .m_type = "int@char *,char *",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll4__16, // 16
            .m_func = invoke__node__lllllllllllllllllllllllllll4__16,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll4__16_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll5",
            .m_type = "@std::string,std::string",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll5__19, // 19
            .m_func = invoke__node__lllllllllllllllllllllllllll5__19,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll5__19_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll5",
            .m_type = "int@std::string,std::string",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll5__18, // 18
            .m_func = invoke__node__lllllllllllllllllllllllllll5__18,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll5__18_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll6",
            .m_type = "@std::string",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll6__23, // 23
            .m_func = invoke__node__lllllllllllllllllllllllllll6__23,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll6__23_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll6",
            .m_type = "@std::string,std::string",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll6__21, // 21
            .m_func = invoke__node__lllllllllllllllllllllllllll6__21,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll6__21_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll6",
            .m_type = "int@std::string",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll6__22, // 22
            .m_func = invoke__node__lllllllllllllllllllllllllll6__22,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll6__22_v,        
        },
        {
            .m_variant = "lllllllllllllllllllllllllll6",
            .m_type = "int@std::string,std::string",
            .m_flags = 0x8801,
            .m_t_flags = 0,
            .m_field = e__node__lllllllllllllllllllllllllll6__20, // 20
            .m_func = invoke__node__lllllllllllllllllllllllllll6__20,
            .m_func_v = invoke__node__lllllllllllllllllllllllllll6__20_v,        
        },
    };
    
    reflect::meta<node>& invoke__node__deinit(const node *c, const std::list<Item> &tag);
    reflect::meta<node>& invoke__node__init(const node *c, const std::list<Item> &tag);
    reflect::meta<node>& invoke__node__lllllllllllllllllllllllllll0(const node *c, const std::list<Item> &tag);
    reflect::meta<node>& invoke__node__lllllllllllllllllllllllllll1(const node *c, const std::list<Item> &tag);
    reflect::meta<node>& invoke__node__lllllllllllllllllllllllllll2(const node *c, const std::list<Item> &tag);
    reflect::meta<node>& invoke__node__lllllllllllllllllllllllllll3(const node *c, const std::list<Item> &tag);
    reflect::meta<node>& invoke__node__lllllllllllllllllllllllllll4(const node *c, const std::list<Item> &tag);
    reflect::meta<node>& invoke__node__lllllllllllllllllllllllllll5(const node *c, const std::list<Item> &tag);
    reflect::meta<node>& invoke__node__lllllllllllllllllllllllllll6(const node *c, const std::list<Item> &tag);
    static reflect::meta<node> g_node_meta[] = {
    {
        .m_variant = "base",
        .m_type = "base",
        .m_flags = 0x821,
        .m_t_flags = ::reflect::flag_type<base>(),
        .m_field = e__node__base, // 0
        .m_getter = [](const node *cls) -> void * 
        { return (void *)static_cast<const base *>(cls); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_base__<node, base>>; }(),
    },
    {
        .m_variant = "config",
        .m_type = "config",
        .m_flags = 0x821,
        .m_t_flags = ::reflect::flag_type<config>(),
        .m_field = e__node__config, // 1
        .m_getter = [](const node *cls) -> void * 
        { return (void *)static_cast<const config *>(cls); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_base__<node, config>>; }(),
    },
    {
        .m_variant = "deinit",
        .m_type = "",
        .m_flags = 0x4801,
        .m_t_flags = 0x0,
        .m_field = e__node__deinit, // 30
        .m_invoke = invoke__node__deinit,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "func",
        .m_type = "func",
        .m_flags = 0x821,
        .m_t_flags = ::reflect::flag_type<func>(),
        .m_field = e__node__func, // 2
        .m_getter = [](const node *cls) -> void * 
        { return (void *)static_cast<const func *>(cls); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_base__<node, func>>; }(),
    },
    {
        .m_variant = "init",
        .m_type = "",
        .m_flags = 0x4801,
        .m_t_flags = 0x0,
        .m_field = e__node__init, // 29
        .m_invoke = invoke__node__init,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll0",
        .m_type = "",
        .m_flags = 0x4801,
        .m_t_flags = 0x0,
        .m_field = e__node__lllllllllllllllllllllllllll0, // 31
        .m_invoke = invoke__node__lllllllllllllllllllllllllll0,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll1",
        .m_type = "",
        .m_flags = 0x4801,
        .m_t_flags = 0x0,
        .m_field = e__node__lllllllllllllllllllllllllll1, // 32
        .m_invoke = invoke__node__lllllllllllllllllllllllllll1,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll2",
        .m_type = "",
        .m_flags = 0x4801,
        .m_t_flags = 0x0,
        .m_field = e__node__lllllllllllllllllllllllllll2, // 33
        .m_invoke = invoke__node__lllllllllllllllllllllllllll2,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll3",
        .m_type = "",
        .m_flags = 0x4801,
        .m_t_flags = 0x0,
        .m_field = e__node__lllllllllllllllllllllllllll3, // 34
        .m_invoke = invoke__node__lllllllllllllllllllllllllll3,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll4",
        .m_type = "",
        .m_flags = 0x4801,
        .m_t_flags = 0x0,
        .m_field = e__node__lllllllllllllllllllllllllll4, // 35
        .m_invoke = invoke__node__lllllllllllllllllllllllllll4,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll5",
        .m_type = "",
        .m_flags = 0x4801,
        .m_t_flags = 0x0,
        .m_field = e__node__lllllllllllllllllllllllllll5, // 36
        .m_invoke = invoke__node__lllllllllllllllllllllllllll5,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll6",
        .m_type = "",
        .m_flags = 0x4801,
        .m_t_flags = 0x0,
        .m_field = e__node__lllllllllllllllllllllllllll6, // 37
        .m_invoke = invoke__node__lllllllllllllllllllllllllll6,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "oooo19",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooo19, // 22
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooo19); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooo19>>; }(),
    },
    {
        .m_variant = "oooo20",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooo20, // 23
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooo20); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooo20>>; }(),
    },
    {
        .m_variant = "oooooo21",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooo21, // 24
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooo21); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooo21>>; }(),
    },
    {
        .m_variant = "oooooo22",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooo22, // 25
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooo22); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooo22>>; }(),
    },
    {
        .m_variant = "oooooo23",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooo23, // 26
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooo23); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooo23>>; }(),
    },
    {
        .m_variant = "oooooo24",
        .m_type = "const char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<const char *>(),
        .m_field = e__node__oooooo24, // 27
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooo24); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooo24>>; }(),
    },
    {
        .m_variant = "oooooo25",
        .m_type = "const char *",
        .m_flags = 0x901,
        .m_t_flags = ::reflect::flag_type<const char *>(),
        .m_field = e__node__oooooo25, // 28
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooo25); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_static__<node, &node::oooooo25>>; }(),
    },
    {
        .m_variant = "oooooooo10",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooo10, // 13
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooo10); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooo10>>; }(),
    },
    {
        .m_variant = "oooooooo11",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooo11, // 14
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooo11); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooo11>>; }(),
    },
    {
        .m_variant = "ooooooooo9",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__ooooooooo9, // 12
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->ooooooooo9); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::ooooooooo9>>; }(),
    },
    {
        .m_variant = "oooooooooooooo12",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooooooooo12, // 15
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooo12); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooo12>>; }(),
    },
    {
        .m_variant = "oooooooooooooo18",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooooooooo18, // 21
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooo18); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooo18>>; }(),
    },
    {
        .m_variant = "oooooooooooooo8",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooooooooo8, // 11
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooo8); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooo8>>; }(),
    },
    {
        .m_variant = "ooooooooooooooo17",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__ooooooooooooooo17, // 20
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->ooooooooooooooo17); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::ooooooooooooooo17>>; }(),
    },
    {
        .m_variant = "ooooooooooooooo7",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__ooooooooooooooo7, // 10
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->ooooooooooooooo7); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::ooooooooooooooo7>>; }(),
    },
    {
        .m_variant = "ooooooooooooooooooooo16",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__ooooooooooooooooooooo16, // 19
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->ooooooooooooooooooooo16); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::ooooooooooooooooooooo16>>; }(),
    },
    {
        .m_variant = "ooooooooooooooooooooooo6",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__ooooooooooooooooooooooo6, // 9
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->ooooooooooooooooooooooo6); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::ooooooooooooooooooooooo6>>; }(),
    },
    {
        .m_variant = "oooooooooooooooooooooooooo0",
        .m_type = "const char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<const char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo0, // 3
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooooooooooooooo0); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooooooooooooooo0>>; }(),
    },
    {
        .m_variant = "oooooooooooooooooooooooooo1",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo1, // 4
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooooooooooooooo1); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooooooooooooooo1>>; }(),
    },
    {
        .m_variant = "oooooooooooooooooooooooooo14",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo14, // 17
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooooooooooooooo14); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooooooooooooooo14>>; }(),
    },
    {
        .m_variant = "oooooooooooooooooooooooooo2",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo2, // 5
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooooooooooooooo2); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooooooooooooooo2>>; }(),
    },
    {
        .m_variant = "oooooooooooooooooooooooooo3",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo3, // 6
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooooooooooooooo3); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooooooooooooooo3>>; }(),
    },
    {
        .m_variant = "oooooooooooooooooooooooooo4",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo4, // 7
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooooooooooooooo4); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooooooooooooooo4>>; }(),
    },
    {
        .m_variant = "oooooooooooooooooooooooooo5",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo5, // 8
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->oooooooooooooooooooooooooo5); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::oooooooooooooooooooooooooo5>>; }(),
    },
    {
        .m_variant = "ooooooooooooooooooooooooooo13",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__ooooooooooooooooooooooooooo13, // 16
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->ooooooooooooooooooooooooooo13); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::ooooooooooooooooooooooooooo13>>; }(),
    },
    {
        .m_variant = "ooooooooooooooooooooooooooo15",
        .m_type = "char *",
        .m_flags = 0x801,
        .m_t_flags = ::reflect::flag_type<char *>(),
        .m_field = e__node__ooooooooooooooooooooooooooo15, // 18
        .m_getter = [](const node *cls) -> void * 
        { return (void *)std::addressof(cls->ooooooooooooooooooooooooooo15); },
        .m_setter = []() -> auto
        { return __setter__<node, __ref_member__<node, &node::ooooooooooooooooooooooooooo15>>; }(),
    },
    };
    reflect::Value __get_value(const node* cls, const std::string& _tag)
    { 
        {
            branch_string tag(_tag);
            auto &_meta = details::get_meta(static_cast<const base *>(cls), tag);
            if (__contains__(_meta.m_flags, flag_member))
            {
                return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);   
            }
        } 
        {
            branch_string tag(_tag);
            auto &_meta = details::get_meta(static_cast<const config *>(cls), tag);
            if (__contains__(_meta.m_flags, flag_member))
            {
                return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);   
            }
        } 
        {
            branch_string tag(_tag);
            auto &_meta = details::get_meta(static_cast<const func *>(cls), tag);
            if (__contains__(_meta.m_flags, flag_member))
            {
                return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);   
            }
        }
        return reflect::Value(nullptr, reflect::e_nullptr);
    }

    inline meta<node> &rfl__0__1(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x74696e69 == value) // init
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__init];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__2(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x33326f6f6f6f6f6f == value) // oooooo23
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooo23];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__0(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x32316f6f6f6f6f6f == value) // oooooo12
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooo12];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__2__0(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x36316f6f6f6f6f == value) // ooooo16
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__ooooooooooooooooooooo16];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__1(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x306f6f == value) // oo0
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooooooooooooooo0];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__2(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x346f6f == value) // oo4
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooooooooooooooo4];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__6(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x316f6f == value) // oo1
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooooooooooooooo1];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__7(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x356f6f == value) // oo5
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooooooooooooooo5];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__8(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x35316f6f6f == value) // ooo15
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__ooooooooooooooooooooooooooo15];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__9(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x34316f6f == value) // oo14
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooooooooooooooo14];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__11(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x326f6f == value) // oo2
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooooooooooooooo2];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__15(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x33316f6f6f == value) // ooo13
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__ooooooooooooooooooooooooooo13];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__16(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x336f6f == value) // oo3
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooooooooooooooo3];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__2__2(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x6f6f6f6f6f6f6f6f == value) // oooooooo
        { // incomplete_bg_1    
            constexpr void *__meta_label[] = {
                &&label__3__0,
                &&label__3__1,
                &&label__3__2,
                &&label__3__3,
                &&label__3__4,
                &&label__3__5,
                &&label__3__6,
                &&label__3__7,
                &&label__3__8,
                &&label__3__9,
                &&label__3__10,
                &&label__3__11,
                &&label__3__12,
                &&label__3__13,
                &&label__3__14,
                &&label__3__15,
                &&label__3__16,
                &&label__3__17,
                &&label__3__18,
            };
            constexpr auto count = countof(__meta_label);
            auto _value = tag();
            auto index = _value % count;
            goto *__meta_label[index];
        label__3__1:
            return rfl__3__1(cls, _value, tag);
        label__3__2:
            return rfl__3__2(cls, _value, tag);
        label__3__6:
            return rfl__3__6(cls, _value, tag);
        label__3__7:
            return rfl__3__7(cls, _value, tag);
        label__3__8:
            return rfl__3__8(cls, _value, tag);
        label__3__9:
            return rfl__3__9(cls, _value, tag);
        label__3__11:
            return rfl__3__11(cls, _value, tag);
        label__3__15:
            return rfl__3__15(cls, _value, tag);
        label__3__16:
            return rfl__3__16(cls, _value, tag);
        label__3__0:
        label__3__3:
        label__3__4:
        label__3__5:
        label__3__10:
        label__3__12:
        label__3__13:
        label__3__14:
        label__3__17:
        label__3__18:
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__2__5(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x366f6f6f6f6f6f6f == value) // ooooooo6
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__ooooooooooooooooooooooo6];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__4(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x6f6f6f6f6f6f6f6f == value) // oooooooo
        { // incomplete_bg_1    
            constexpr void *__meta_label[] = {
                &&label__2__0,
                &&label__2__1,
                &&label__2__2,
                &&label__2__3,
                &&label__2__4,
                &&label__2__5,
                &&label__2__6,
            };
            constexpr auto count = countof(__meta_label);
            auto _value = tag();
            auto index = _value % count;
            goto *__meta_label[index];
        label__2__0:
            return rfl__2__0(cls, _value, tag);
        label__2__2:
            return rfl__2__2(cls, _value, tag);
        label__2__5:
            return rfl__2__5(cls, _value, tag);
        label__2__1:
        label__2__3:
        label__2__4:
        label__2__6:
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__6(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x38316f6f6f6f6f6f == value) // oooooo18
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooo18];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__8(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x386f6f6f6f6f6f == value) // oooooo8
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooooooooo8];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__2__7(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x37 == value) // 7
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__ooooooooooooooo17];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__10(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x316f6f6f6f6f6f6f == value) // ooooooo1
        {
            if (tag) // incomplete_eq_1
            {
                auto _value = tag();
                return rfl__2__7(cls, _value, tag);
            }
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__12(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x3031 == value) // 10
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooo10];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__13(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x3131 == value) // 11
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooooo11];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__15(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x396f == value) // o9
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__ooooooooo9];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__16(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x376f6f6f6f6f6f6f == value) // ooooooo7
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__ooooooooooooooo7];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__3(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x6f6f6f6f6f6f6f6f == value) // oooooooo
        { // incomplete_bg_1    
            constexpr void *__meta_label[] = {
                &&label__1__0,
                &&label__1__1,
                &&label__1__2,
                &&label__1__3,
                &&label__1__4,
                &&label__1__5,
                &&label__1__6,
                &&label__1__7,
                &&label__1__8,
                &&label__1__9,
                &&label__1__10,
                &&label__1__11,
                &&label__1__12,
                &&label__1__13,
                &&label__1__14,
                &&label__1__15,
                &&label__1__16,
            };
            constexpr auto count = countof(__meta_label);
            auto _value = tag();
            auto index = _value % count;
            goto *__meta_label[index];
        label__1__0:
            return rfl__1__0(cls, _value, tag);
        label__1__4:
            return rfl__1__4(cls, _value, tag);
        label__1__6:
            return rfl__1__6(cls, _value, tag);
        label__1__8:
            return rfl__1__8(cls, _value, tag);
        label__1__10:
            return rfl__1__10(cls, _value, tag);
        label__1__12:
            return rfl__1__12(cls, _value, tag);
        label__1__13:
            return rfl__1__13(cls, _value, tag);
        label__1__15:
            return rfl__1__15(cls, _value, tag);
        label__1__16:
            return rfl__1__16(cls, _value, tag);
        label__1__1:
        label__1__2:
        label__1__3:
        label__1__5:
        label__1__7:
        label__1__9:
        label__1__11:
        label__1__14:
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__5(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x31326f6f6f6f6f6f == value) // oooooo21
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooo21];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__19(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x316c6c6c == value) // lll1
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__lllllllllllllllllllllllllll1];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__20(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x326c6c6c == value) // lll2
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__lllllllllllllllllllllllllll2];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__21(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x336c6c6c == value) // lll3
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__lllllllllllllllllllllllllll3];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__22(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x346c6c6c == value) // lll4
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__lllllllllllllllllllllllllll4];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__23(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x356c6c6c == value) // lll5
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__lllllllllllllllllllllllllll5];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__24(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x366c6c6c == value) // lll6
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__lllllllllllllllllllllllllll6];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__3__25(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x306c6c6c == value) // lll0
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__lllllllllllllllllllllllllll0];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__2__8(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x6c6c6c6c6c6c6c6c == value) // llllllll
        { // incomplete_bg_1    
            constexpr void *__meta_label[] = {
                &&label__3__19,
                &&label__3__20,
                &&label__3__21,
                &&label__3__22,
                &&label__3__23,
                &&label__3__24,
                &&label__3__25,
            };
            constexpr auto count = countof(__meta_label);
            auto _value = tag();
            auto index = _value % count;
            goto *__meta_label[index];
        label__3__19:
            return rfl__3__19(cls, _value, tag);
        label__3__20:
            return rfl__3__20(cls, _value, tag);
        label__3__21:
            return rfl__3__21(cls, _value, tag);
        label__3__22:
            return rfl__3__22(cls, _value, tag);
        label__3__23:
            return rfl__3__23(cls, _value, tag);
        label__3__24:
            return rfl__3__24(cls, _value, tag);
        label__3__25:
            return rfl__3__25(cls, _value, tag);
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__1__17(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x6c6c6c6c6c6c6c6c == value) // llllllll
        {
            if (tag) // incomplete_eq_1
            {
                auto _value = tag();
                return rfl__2__8(cls, _value, tag);
            }
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__9(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x6c6c6c6c6c6c6c6c == value) // llllllll
        {
            if (tag) // incomplete_eq_1
            {
                auto _value = tag();
                return rfl__1__17(cls, _value, tag);
            }
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__10(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x39316f6f6f6f == value) // oooo19
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooo19];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__11(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x65736162 == value) // base
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__base];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__13(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x34326f6f6f6f6f6f == value) // oooooo24
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooo24];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__15(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x6769666e6f63 == value) // config
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__config];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__16(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x32326f6f6f6f6f6f == value) // oooooo22
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooo22];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__17(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x74696e696564 == value) // deinit
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__deinit];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__22(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x30326f6f6f6f == value) // oooo20
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooo20];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__23(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x636e7566 == value) // func
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__func];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    inline meta<node> &rfl__0__24(const node *cls, uint64_t value, branch_string &tag)
    {
        if (0x35326f6f6f6f6f6f == value) // oooooo25
        {
            if (!tag) // complete
            {
                return g_node_meta[e__node__oooooo25];
            }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__node__deinit__7_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        cls->deinit();
        return 0;
    }
    int invoke__node__deinit__7(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 0)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__deinit__7_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__deinit__6_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        _r = cls->deinit();
        return 0;
    }
    int invoke__node__deinit__6(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 1)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__deinit__6_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<node>& invoke__node__deinit(const node *c, const std::list<Item> &bra)
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
                return g_node_func[e__node__deinit__7];
            }        
        }
            return g_default_meta;    
        label__1:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() } };
            if (bra == l)
            {
                return g_node_func[e__node__deinit__6];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__node__init__1_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, int *));
        auto& _a_1 = *(va_arg(__arguments_list, long long *));
        auto& _a_2 = *(va_arg(__arguments_list, char * *));
        cls->init(_a_0, _a_1, _a_2);
        return 0;
    }
    int invoke__node__init__1(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 3)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__init__1_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__init__5_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        cls->init();
        return 0;
    }
    int invoke__node__init__5(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 0)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__init__5_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__init__3_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, double *));
        auto& _a_1 = *(va_arg(__arguments_list, double *));
        auto& _a_2 = *(va_arg(__arguments_list, char * *));
        cls->init(_a_0, _a_1, _a_2);
        return 0;
    }
    int invoke__node__init__3(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 3)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__init__3_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__init__0_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, int *));
        auto& _a_1 = *(va_arg(__arguments_list, long long *));
        auto& _a_2 = *(va_arg(__arguments_list, char * *));
        _r = cls->init(_a_0, _a_1, _a_2);
        return 0;
    }
    int invoke__node__init__0(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 4)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__init__0_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__init__2_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, double *));
        auto& _a_1 = *(va_arg(__arguments_list, double *));
        auto& _a_2 = *(va_arg(__arguments_list, char * *));
        _r = cls->init(_a_0, _a_1, _a_2);
        return 0;
    }
    int invoke__node__init__2(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 4)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__init__2_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__init__4_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        _r = cls->init();
        return 0;
    }
    int invoke__node__init__4(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 1)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__init__4_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<node>& invoke__node__init(const node *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 4) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
                &&label__2,
                &&label__3,
                &&label__4,
            };
            goto *__meta_label[l];    
        label__0:
        {
            static std::list<Item> l = {  };
            if (bra == l)
            {
                return g_node_func[e__node__init__5];
            }        
        }
            return g_default_meta;    
        label__1:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() } };
            if (bra == l)
            {
                return g_node_func[e__node__init__4];
            }        
        }
            return g_default_meta;    
        label__2:
            return g_default_meta;    
        label__3:
        {
            static std::list<Item> l = { { "int", ::reflect::flag_type<int>() }, { "long long", ::reflect::flag_type<long long>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__init__1];
            }        
        }
        {
            static std::list<Item> l = { { "float", ::reflect::flag_type<float>() }, { "double", ::reflect::flag_type<double>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__init__3];
            }        
        }
            return g_default_meta;    
        label__4:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "int", ::reflect::flag_type<int>() }, { "long long", ::reflect::flag_type<long long>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__init__0];
            }        
        }
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "float", ::reflect::flag_type<float>() }, { "double", ::reflect::flag_type<double>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__init__2];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__node__lllllllllllllllllllllllllll0__9_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        cls->lllllllllllllllllllllllllll0(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll0__9(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 2)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll0__9_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__lllllllllllllllllllllllllll0__8_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        _r = cls->lllllllllllllllllllllllllll0(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll0__8(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 3)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll0__8_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<node>& invoke__node__lllllllllllllllllllllllllll0(const node *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 3) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
                &&label__2,
                &&label__3,
            };
            goto *__meta_label[l];    
        label__0:
            return g_default_meta;    
        label__1:
            return g_default_meta;    
        label__2:
        {
            static std::list<Item> l = { { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll0__9];
            }        
        }
            return g_default_meta;    
        label__3:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll0__8];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__node__lllllllllllllllllllllllllll1__11_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        cls->lllllllllllllllllllllllllll1(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll1__11(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 2)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll1__11_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__lllllllllllllllllllllllllll1__10_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        _r = cls->lllllllllllllllllllllllllll1(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll1__10(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 3)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll1__10_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<node>& invoke__node__lllllllllllllllllllllllllll1(const node *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 3) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
                &&label__2,
                &&label__3,
            };
            goto *__meta_label[l];    
        label__0:
            return g_default_meta;    
        label__1:
            return g_default_meta;    
        label__2:
        {
            static std::list<Item> l = { { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll1__11];
            }        
        }
            return g_default_meta;    
        label__3:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll1__10];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__node__lllllllllllllllllllllllllll2__13_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        cls->lllllllllllllllllllllllllll2(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll2__13(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 2)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll2__13_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__lllllllllllllllllllllllllll2__12_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        _r = cls->lllllllllllllllllllllllllll2(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll2__12(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 3)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll2__12_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<node>& invoke__node__lllllllllllllllllllllllllll2(const node *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 3) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
                &&label__2,
                &&label__3,
            };
            goto *__meta_label[l];    
        label__0:
            return g_default_meta;    
        label__1:
            return g_default_meta;    
        label__2:
        {
            static std::list<Item> l = { { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll2__13];
            }        
        }
            return g_default_meta;    
        label__3:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll2__12];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__node__lllllllllllllllllllllllllll3__15_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        cls->lllllllllllllllllllllllllll3(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll3__15(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 2)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll3__15_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__lllllllllllllllllllllllllll3__14_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        _r = cls->lllllllllllllllllllllllllll3(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll3__14(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 3)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll3__14_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<node>& invoke__node__lllllllllllllllllllllllllll3(const node *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 3) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
                &&label__2,
                &&label__3,
            };
            goto *__meta_label[l];    
        label__0:
            return g_default_meta;    
        label__1:
            return g_default_meta;    
        label__2:
        {
            static std::list<Item> l = { { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll3__15];
            }        
        }
            return g_default_meta;    
        label__3:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll3__14];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__node__lllllllllllllllllllllllllll4__17_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        cls->lllllllllllllllllllllllllll4(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll4__17(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 2)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll4__17_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__lllllllllllllllllllllllllll4__16_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, char * *));
        auto& _a_1 = *(va_arg(__arguments_list, char * *));
        _r = cls->lllllllllllllllllllllllllll4(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll4__16(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 3)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll4__16_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<node>& invoke__node__lllllllllllllllllllllllllll4(const node *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 3) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
                &&label__2,
                &&label__3,
            };
            goto *__meta_label[l];    
        label__0:
            return g_default_meta;    
        label__1:
            return g_default_meta;    
        label__2:
        {
            static std::list<Item> l = { { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll4__17];
            }        
        }
            return g_default_meta;    
        label__3:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "char *", ::reflect::flag_type<char *>() }, { "char *", ::reflect::flag_type<char *>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll4__16];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__node__lllllllllllllllllllllllllll5__19_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, std::string *));
        auto& _a_1 = *(va_arg(__arguments_list, std::string *));
        cls->lllllllllllllllllllllllllll5(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll5__19(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 2)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll5__19_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__lllllllllllllllllllllllllll5__18_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, std::string *));
        auto& _a_1 = *(va_arg(__arguments_list, std::string *));
        _r = cls->lllllllllllllllllllllllllll5(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll5__18(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 3)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll5__18_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<node>& invoke__node__lllllllllllllllllllllllllll5(const node *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 3) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
                &&label__2,
                &&label__3,
            };
            goto *__meta_label[l];    
        label__0:
            return g_default_meta;    
        label__1:
            return g_default_meta;    
        label__2:
        {
            static std::list<Item> l = { { "std::string", ::reflect::flag_type<std::string>() }, { "std::string", ::reflect::flag_type<std::string>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll5__19];
            }        
        }
            return g_default_meta;    
        label__3:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "std::string", ::reflect::flag_type<std::string>() }, { "std::string", ::reflect::flag_type<std::string>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll5__18];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    int invoke__node__lllllllllllllllllllllllllll6__23_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, std::string *));
        cls->lllllllllllllllllllllllllll6(_a_0);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll6__23(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 1)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll6__23_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__lllllllllllllllllllllllllll6__21_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _a_0 = *(va_arg(__arguments_list, std::string *));
        auto& _a_1 = *(va_arg(__arguments_list, std::string *));
        cls->lllllllllllllllllllllllllll6(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll6__21(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 2)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll6__21_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__lllllllllllllllllllllllllll6__22_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, std::string *));
        _r = cls->lllllllllllllllllllllllllll6(_a_0);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll6__22(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 2)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll6__22_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    int invoke__node__lllllllllllllllllllllllllll6__20_v(node *cls, const Arguments* argu, va_list __arguments_list)
    {
        auto& _r = *(va_arg(__arguments_list, int *));
        auto& _a_0 = *(va_arg(__arguments_list, std::string *));
        auto& _a_1 = *(va_arg(__arguments_list, std::string *));
        _r = cls->lllllllllllllllllllllllllll6(_a_0, _a_1);
        return 0;
    }
    int invoke__node__lllllllllllllllllllllllllll6__20(const node *c, const Arguments* argu, ...)
    {
        auto *cls = (node *)(c); 
        if (cls && argu->m_arguments.size() == 3)
        {
            va_list __arguments_list;
            va_start(__arguments_list, argu);
            invoke__node__lllllllllllllllllllllllllll6__20_v(cls, argu, __arguments_list);
            va_end(__arguments_list);
            return 0;
        }
        return -1;
    }
    meta<node>& invoke__node__lllllllllllllllllllllllllll6(const node *c, const std::list<Item> &bra)
    {   
        auto l = bra.size();
        if (l <= 3) 
        {
            constexpr void *__meta_label[] = {
                &&label__0,
                &&label__1,
                &&label__2,
                &&label__3,
            };
            goto *__meta_label[l];    
        label__0:
            return g_default_meta;    
        label__1:
        {
            static std::list<Item> l = { { "std::string", ::reflect::flag_type<std::string>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll6__23];
            }        
        }
            return g_default_meta;    
        label__2:
        {
            static std::list<Item> l = { { "std::string", ::reflect::flag_type<std::string>() }, { "std::string", ::reflect::flag_type<std::string>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll6__21];
            }        
        }
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "std::string", ::reflect::flag_type<std::string>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll6__22];
            }        
        }
            return g_default_meta;    
        label__3:
        {
            static std::list<Item> l = { { "int@", ::reflect::flag_type<int>() }, { "std::string", ::reflect::flag_type<std::string>() }, { "std::string", ::reflect::flag_type<std::string>() } };
            if (bra == l)
            {
                return g_node_func[e__node__lllllllllllllllllllllllllll6__20];
            }        
        }
            return g_default_meta;
        }
        return g_default_meta;
    }
    const uint64_t get_fields_count(const node *cls)
    {
        return countof(g_node_meta);
    }
    namespace details
    {    
        meta<node> &get_meta(const node *cls, branch_string &tag)
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
                &&label__0__21,
                &&label__0__22,
                &&label__0__23,
                &&label__0__24,
            };
            constexpr auto count = countof(__meta_label);
            auto value = tag();
            auto index = value % count;        
            goto *__meta_label[index];
        label__0__1:
            return rfl__0__1(cls, value, tag);
        label__0__2:
            return rfl__0__2(cls, value, tag);
        label__0__3:
            return rfl__0__3(cls, value, tag);
        label__0__5:
            return rfl__0__5(cls, value, tag);
        label__0__9:
            return rfl__0__9(cls, value, tag);
        label__0__10:
            return rfl__0__10(cls, value, tag);
        label__0__11:
            return rfl__0__11(cls, value, tag);
        label__0__13:
            return rfl__0__13(cls, value, tag);
        label__0__15:
            return rfl__0__15(cls, value, tag);
        label__0__16:
            return rfl__0__16(cls, value, tag);
        label__0__17:
            return rfl__0__17(cls, value, tag);
        label__0__22:
            return rfl__0__22(cls, value, tag);
        label__0__23:
            return rfl__0__23(cls, value, tag);
        label__0__24:
            return rfl__0__24(cls, value, tag);
        label__0__0:
        label__0__4:
        label__0__6:
        label__0__7:
        label__0__8:
        label__0__12:
        label__0__14:
        label__0__18:
        label__0__19:
        label__0__20:
        label__0__21:
            return g_default_meta;
        }
    
        meta<node> &get_func(const node *cls, branch_string& tag, const std::list<Item>& args_tag)
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
        int get_base_func(const node *cls, const std::string& _tag, const Arguments *_, ...)
        {
            va_list __arguments_list;
            va_start(__arguments_list, _);
            auto r = -1;
            do
            {
                {
                    branch_string tag(_tag);
                    auto &_invoke = details::get_func(static_cast<const base *>(cls), tag, _->m_arguments);
                    if (__contains__(_invoke.m_flags, flag_argument))
                    {
                        r = _invoke.m_func_v(const_cast<base *>(static_cast<const base *>(cls)), _, __arguments_list);
                        break;
                    } 
                }
                {
                    branch_string tag(_tag);
                    auto &_invoke = details::get_func(static_cast<const config *>(cls), tag, _->m_arguments);
                    if (__contains__(_invoke.m_flags, flag_argument))
                    {
                        r = _invoke.m_func_v(const_cast<config *>(static_cast<const config *>(cls)), _, __arguments_list);
                        break;
                    } 
                }
                {
                    branch_string tag(_tag);
                    auto &_invoke = details::get_func(static_cast<const func *>(cls), tag, _->m_arguments);
                    if (__contains__(_invoke.m_flags, flag_argument))
                    {
                        r = _invoke.m_func_v(const_cast<func *>(static_cast<const func *>(cls)), _, __arguments_list);
                        break;
                    } 
                }
            } while (false);
            va_end(__arguments_list);
            return r;
        }
    }
    Value get_value(const node *cls, const std::string &_tag)
    {
        branch_string tag(_tag); 
        auto& _meta = details::get_meta(cls, tag);
        if (__contains__(_meta.m_flags, flag_member))
        {
            return Value(_meta.m_getter(cls), _meta.m_t_flags);  
        }      
        return __get_value(cls, _tag);   
    }
    Value get_value(const node *cls, const char *tag)
    {
        return get_value(cls, std::string(tag));
    }
    Value get_field_value(const node *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_node_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return Value(_meta.m_getter(cls), _meta.m_t_flags);
            }
        }
        return reflect::Value(nullptr, reflect::e_nullptr);
    }
    const std::string &get_type(const node *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;
    }
    const std::string &get_type(const node *cls, const char *_tag) 
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;    
    }
    const std::string &get_type(node *cls)
    {   
        static const std::string _class = "node";
        return _class;
    }
    const std::string &get_type(const node *cls)
    {
        static const std::string _class = "node";
        return _class;
    }
    const std::string &get_typeid(const node *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_type;
    }
    const std::string &get_typeid(const node *cls)
    {
        static const std::string _class = typeid("node").name();
        return _class;
    }
    uint64_t get_field(const node *cls, const std::string &_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    uint64_t get_field(const node *cls, const char *_tag)
    {
        branch_string tag(_tag);
        return details::get_meta(cls, tag).m_field;  
    }
    const std::string &get_field_type(const node *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            auto& _meta = g_node_meta[field]; 
            if (_meta.m_t_flags != 0)
            {
                return _meta.m_type;
            }
        }
        static std::string _ = "";
        return _;
    }
    const std::string &get_name(const node *cls, uint32_t field)
    {
        if (field < get_fields_count(cls))
        {
            return g_node_meta[field].m_variant;
        }
        return g_default_meta.m_variant;
    }
    meta<node> &get_meta(const node *cls)
    {
        return g_node;
    }
}

