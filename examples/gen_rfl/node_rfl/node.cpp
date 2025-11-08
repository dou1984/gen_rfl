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
#include "node.h"
#include "../../node.h"

using namespace reflect;

enum node_meta_enum
{
    e__node__base,
    e__node__deinit,
    e__node__init,
    e__node__lllllllllllllllllllllllllll0,
    e__node__lllllllllllllllllllllllllll1,
    e__node__lllllllllllllllllllllllllll2,
    e__node__lllllllllllllllllllllllllll3,
    e__node__lllllllllllllllllllllllllll4,
    e__node__lllllllllllllllllllllllllll5,
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
    e__node__func__end,
};
static int set_value_invalid(node *cls, uint32_t, ...)
{
    return 0;
}
static meta<node> g_default_meta = {
    .m_variant = "",
    .m_type = "",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const node *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};
static meta<node> g_node = {
    .m_variant = "node",
    .m_type = "",
    .m_flags = 0,
    .m_t_flags = 0,
    .m_field = UINT32_MAX,
    .m_getter = [](const node *c) -> void* { return nullptr; },
    .m_setter = set_value_invalid,
};

int invoke__node__deinit__7(const node* c, uint64_t argc, ...);
int invoke__node__deinit__6(const node* c, uint64_t argc, ...);
int invoke__node__init__5(const node* c, uint64_t argc, ...);
int invoke__node__init__3(const node* c, uint64_t argc, ...);
int invoke__node__init__1(const node* c, uint64_t argc, ...);
int invoke__node__init__4(const node* c, uint64_t argc, ...);
int invoke__node__init__2(const node* c, uint64_t argc, ...);
int invoke__node__init__0(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll0__9(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll0__8(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll1__11(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll1__10(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll2__13(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll2__12(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll3__15(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll3__14(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll4__17(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll4__16(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll5__19(const node* c, uint64_t argc, ...);
int invoke__node__lllllllllllllllllllllllllll5__18(const node* c, uint64_t argc, ...);
int setter__node__base(node* c, uint32_t argc, ...);
int setter__node__oooo19(node* c, uint32_t argc, ...);
int setter__node__oooo20(node* c, uint32_t argc, ...);
int setter__node__oooooo21(node* c, uint32_t argc, ...);
int setter__node__oooooo22(node* c, uint32_t argc, ...);
int setter__node__oooooo23(node* c, uint32_t argc, ...);
int setter__node__oooooo24(node* c, uint32_t argc, ...);
int setter__node__oooooo25(node* c, uint32_t argc, ...);
int setter__node__oooooooo10(node* c, uint32_t argc, ...);
int setter__node__oooooooo11(node* c, uint32_t argc, ...);
int setter__node__ooooooooo9(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooo12(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooo18(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooo8(node* c, uint32_t argc, ...);
int setter__node__ooooooooooooooo17(node* c, uint32_t argc, ...);
int setter__node__ooooooooooooooo7(node* c, uint32_t argc, ...);
int setter__node__ooooooooooooooooooooo16(node* c, uint32_t argc, ...);
int setter__node__ooooooooooooooooooooooo6(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooooooooooooooo0(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooooooooooooooo1(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooooooooooooooo14(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooooooooooooooo2(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooooooooooooooo3(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooooooooooooooo4(node* c, uint32_t argc, ...);
int setter__node__oooooooooooooooooooooooooo5(node* c, uint32_t argc, ...);
int setter__node__ooooooooooooooooooooooooooo13(node* c, uint32_t argc, ...);
int setter__node__ooooooooooooooooooooooooooo15(node* c, uint32_t argc, ...);
static meta<node> g_node_func[] = 
{
    {
        .m_variant = "deinit",
        .m_type = "()",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__deinit__7, // 7
        .m_func = invoke__node__deinit__7,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "deinit",
        .m_type = "int()",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__deinit__6, // 6
        .m_func = invoke__node__deinit__6,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "init",
        .m_type = "()",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__init__5, // 5
        .m_func = invoke__node__init__5,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "init",
        .m_type = "(float,double,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__init__3, // 3
        .m_func = invoke__node__init__3,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "init",
        .m_type = "(int,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__init__1, // 1
        .m_func = invoke__node__init__1,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "init",
        .m_type = "int()",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__init__4, // 4
        .m_func = invoke__node__init__4,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "init",
        .m_type = "int(float,double,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__init__2, // 2
        .m_func = invoke__node__init__2,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "init",
        .m_type = "int(int,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__init__0, // 0
        .m_func = invoke__node__init__0,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll0",
        .m_type = "(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll0__9, // 9
        .m_func = invoke__node__lllllllllllllllllllllllllll0__9,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll0",
        .m_type = "int(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll0__8, // 8
        .m_func = invoke__node__lllllllllllllllllllllllllll0__8,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll1",
        .m_type = "(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll1__11, // 11
        .m_func = invoke__node__lllllllllllllllllllllllllll1__11,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll1",
        .m_type = "int(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll1__10, // 10
        .m_func = invoke__node__lllllllllllllllllllllllllll1__10,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll2",
        .m_type = "(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll2__13, // 13
        .m_func = invoke__node__lllllllllllllllllllllllllll2__13,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll2",
        .m_type = "int(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll2__12, // 12
        .m_func = invoke__node__lllllllllllllllllllllllllll2__12,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll3",
        .m_type = "(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll3__15, // 15
        .m_func = invoke__node__lllllllllllllllllllllllllll3__15,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll3",
        .m_type = "int(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll3__14, // 14
        .m_func = invoke__node__lllllllllllllllllllllllllll3__14,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll4",
        .m_type = "(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll4__17, // 17
        .m_func = invoke__node__lllllllllllllllllllllllllll4__17,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll4",
        .m_type = "int(const char *,const char *)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll4__16, // 16
        .m_func = invoke__node__lllllllllllllllllllllllllll4__16,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll5",
        .m_type = "(const std::string &,const std::string &)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll5__19, // 19
        .m_func = invoke__node__lllllllllllllllllllllllllll5__19,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll5",
        .m_type = "int(const std::string &,const std::string &)",
        .m_flags = 0x8801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll5__18, // 18
        .m_func = invoke__node__lllllllllllllllllllllllllll5__18,
        .m_setter = set_value_invalid,
    },
};

meta<node>& invoke__node__deinit(const node *c, const std::string &tag);
meta<node>& invoke__node__init(const node *c, const std::string &tag);
meta<node>& invoke__node__lllllllllllllllllllllllllll0(const node *c, const std::string &tag);
meta<node>& invoke__node__lllllllllllllllllllllllllll1(const node *c, const std::string &tag);
meta<node>& invoke__node__lllllllllllllllllllllllllll2(const node *c, const std::string &tag);
meta<node>& invoke__node__lllllllllllllllllllllllllll3(const node *c, const std::string &tag);
meta<node>& invoke__node__lllllllllllllllllllllllllll4(const node *c, const std::string &tag);
meta<node>& invoke__node__lllllllllllllllllllllllllll5(const node *c, const std::string &tag);
static meta<node> g_node_meta[] = {
    {
        .m_variant = "base",
        .m_type =  "base",
        .m_flags = 0x821,
        .m_t_flags = flag_type<base>(),
        .m_field = e__node__base, // 0
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)static_cast<const base *>(cls);
        },
        .m_setter = setter__node__base,
    },
    {
        .m_variant = "deinit",
        .m_type =  "",
        .m_flags = 0x4801,
        .m_t_flags = 0,
        .m_field = e__node__deinit, // 28
        .m_invoke = invoke__node__deinit,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "init",
        .m_type =  "",
        .m_flags = 0x4801,
        .m_t_flags = 0,
        .m_field = e__node__init, // 27
        .m_invoke = invoke__node__init,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll0",
        .m_type =  "",
        .m_flags = 0x4801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll0, // 29
        .m_invoke = invoke__node__lllllllllllllllllllllllllll0,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll1",
        .m_type =  "",
        .m_flags = 0x4801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll1, // 30
        .m_invoke = invoke__node__lllllllllllllllllllllllllll1,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll2",
        .m_type =  "",
        .m_flags = 0x4801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll2, // 31
        .m_invoke = invoke__node__lllllllllllllllllllllllllll2,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll3",
        .m_type =  "",
        .m_flags = 0x4801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll3, // 32
        .m_invoke = invoke__node__lllllllllllllllllllllllllll3,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll4",
        .m_type =  "",
        .m_flags = 0x4801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll4, // 33
        .m_invoke = invoke__node__lllllllllllllllllllllllllll4,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "lllllllllllllllllllllllllll5",
        .m_type =  "",
        .m_flags = 0x4801,
        .m_t_flags = 0,
        .m_field = e__node__lllllllllllllllllllllllllll5, // 34
        .m_invoke = invoke__node__lllllllllllllllllllllllllll5,
        .m_setter = set_value_invalid,
    },
    {
        .m_variant = "oooo19",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooo19, // 20
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooo19);
        },
        .m_setter = setter__node__oooo19,
    },
    {
        .m_variant = "oooo20",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooo20, // 21
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooo20);
        },
        .m_setter = setter__node__oooo20,
    },
    {
        .m_variant = "oooooo21",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooo21, // 22
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooo21);
        },
        .m_setter = setter__node__oooooo21,
    },
    {
        .m_variant = "oooooo22",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooo22, // 23
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooo22);
        },
        .m_setter = setter__node__oooooo22,
    },
    {
        .m_variant = "oooooo23",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooo23, // 24
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooo23);
        },
        .m_setter = setter__node__oooooo23,
    },
    {
        .m_variant = "oooooo24",
        .m_type =  "const char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<const char *>(),
        .m_field = e__node__oooooo24, // 25
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooo24);
        },
        .m_setter = setter__node__oooooo24,
    },
    {
        .m_variant = "oooooo25",
        .m_type =  "const char *",
        .m_flags = 0x901,
        .m_t_flags = flag_type<const char *>(),
        .m_field = e__node__oooooo25, // 26
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooo25);
        },
        .m_setter = setter__node__oooooo25,
    },
    {
        .m_variant = "oooooooo10",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooo10, // 11
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooo10);
        },
        .m_setter = setter__node__oooooooo10,
    },
    {
        .m_variant = "oooooooo11",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooo11, // 12
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooo11);
        },
        .m_setter = setter__node__oooooooo11,
    },
    {
        .m_variant = "ooooooooo9",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__ooooooooo9, // 10
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->ooooooooo9);
        },
        .m_setter = setter__node__ooooooooo9,
    },
    {
        .m_variant = "oooooooooooooo12",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooooooooo12, // 13
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooo12);
        },
        .m_setter = setter__node__oooooooooooooo12,
    },
    {
        .m_variant = "oooooooooooooo18",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooooooooo18, // 19
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooo18);
        },
        .m_setter = setter__node__oooooooooooooo18,
    },
    {
        .m_variant = "oooooooooooooo8",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooooooooo8, // 9
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooo8);
        },
        .m_setter = setter__node__oooooooooooooo8,
    },
    {
        .m_variant = "ooooooooooooooo17",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__ooooooooooooooo17, // 18
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->ooooooooooooooo17);
        },
        .m_setter = setter__node__ooooooooooooooo17,
    },
    {
        .m_variant = "ooooooooooooooo7",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__ooooooooooooooo7, // 8
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->ooooooooooooooo7);
        },
        .m_setter = setter__node__ooooooooooooooo7,
    },
    {
        .m_variant = "ooooooooooooooooooooo16",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__ooooooooooooooooooooo16, // 17
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->ooooooooooooooooooooo16);
        },
        .m_setter = setter__node__ooooooooooooooooooooo16,
    },
    {
        .m_variant = "ooooooooooooooooooooooo6",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__ooooooooooooooooooooooo6, // 7
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->ooooooooooooooooooooooo6);
        },
        .m_setter = setter__node__ooooooooooooooooooooooo6,
    },
    {
        .m_variant = "oooooooooooooooooooooooooo0",
        .m_type =  "const char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<const char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo0, // 1
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooooooooooooooo0);
        },
        .m_setter = setter__node__oooooooooooooooooooooooooo0,
    },
    {
        .m_variant = "oooooooooooooooooooooooooo1",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo1, // 2
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooooooooooooooo1);
        },
        .m_setter = setter__node__oooooooooooooooooooooooooo1,
    },
    {
        .m_variant = "oooooooooooooooooooooooooo14",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo14, // 15
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooooooooooooooo14);
        },
        .m_setter = setter__node__oooooooooooooooooooooooooo14,
    },
    {
        .m_variant = "oooooooooooooooooooooooooo2",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo2, // 3
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooooooooooooooo2);
        },
        .m_setter = setter__node__oooooooooooooooooooooooooo2,
    },
    {
        .m_variant = "oooooooooooooooooooooooooo3",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo3, // 4
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooooooooooooooo3);
        },
        .m_setter = setter__node__oooooooooooooooooooooooooo3,
    },
    {
        .m_variant = "oooooooooooooooooooooooooo4",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo4, // 5
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooooooooooooooo4);
        },
        .m_setter = setter__node__oooooooooooooooooooooooooo4,
    },
    {
        .m_variant = "oooooooooooooooooooooooooo5",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__oooooooooooooooooooooooooo5, // 6
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->oooooooooooooooooooooooooo5);
        },
        .m_setter = setter__node__oooooooooooooooooooooooooo5,
    },
    {
        .m_variant = "ooooooooooooooooooooooooooo13",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__ooooooooooooooooooooooooooo13, // 14
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->ooooooooooooooooooooooooooo13);
        },
        .m_setter = setter__node__ooooooooooooooooooooooooooo13,
    },
    {
        .m_variant = "ooooooooooooooooooooooooooo15",
        .m_type =  "char *",
        .m_flags = 0x801,
        .m_t_flags = flag_type<char *>(),
        .m_field = e__node__ooooooooooooooooooooooooooo15, // 16
        .m_getter = [](const node *cls) -> void * 
        {
            return (void *)std::addressof(cls->ooooooooooooooooooooooooooo15);
        },
        .m_setter = setter__node__ooooooooooooooooooooooooooo15,
    },
};
reflect::Value __get_value(const node* cls, const std::string& _tag)
{ 
    {
        branch_string tag(_tag);
        auto _meta = __details__::get_meta(static_cast<const base*>(cls), tag);
        if (__contains__(_meta.m_flags, flag_member))
        {
            return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);   
        }
    }
    return reflect::Value(nullptr, 0);
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

int setter__node__oooooo23(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooo23, _flag);
    return 0;
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

int setter__node__oooooooooooooo12(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooo12, _flag);
    return 0;
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

int setter__node__ooooooooooooooooooooo16(node* c, uint32_t _flag, ...)
{    
    SETTER(c->ooooooooooooooooooooo16, _flag);
    return 0;
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

int setter__node__oooooooooooooooooooooooooo0(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooooooooooooooo0, _flag);
    return 0;
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

int setter__node__oooooooooooooooooooooooooo4(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooooooooooooooo4, _flag);
    return 0;
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

int setter__node__oooooooooooooooooooooooooo1(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooooooooooooooo1, _flag);
    return 0;
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

int setter__node__oooooooooooooooooooooooooo5(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooooooooooooooo5, _flag);
    return 0;
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

int setter__node__ooooooooooooooooooooooooooo15(node* c, uint32_t _flag, ...)
{    
    SETTER(c->ooooooooooooooooooooooooooo15, _flag);
    return 0;
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

int setter__node__oooooooooooooooooooooooooo14(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooooooooooooooo14, _flag);
    return 0;
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

int setter__node__oooooooooooooooooooooooooo2(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooooooooooooooo2, _flag);
    return 0;
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

int setter__node__ooooooooooooooooooooooooooo13(node* c, uint32_t _flag, ...)
{    
    SETTER(c->ooooooooooooooooooooooooooo13, _flag);
    return 0;
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

int setter__node__oooooooooooooooooooooooooo3(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooooooooooooooo3, _flag);
    return 0;
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

int setter__node__ooooooooooooooooooooooo6(node* c, uint32_t _flag, ...)
{    
    SETTER(c->ooooooooooooooooooooooo6, _flag);
    return 0;
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

int setter__node__oooooooooooooo18(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooo18, _flag);
    return 0;
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

int setter__node__oooooooooooooo8(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooooooooo8, _flag);
    return 0;
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

int setter__node__ooooooooooooooo17(node* c, uint32_t _flag, ...)
{    
    SETTER(c->ooooooooooooooo17, _flag);
    return 0;
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

int setter__node__oooooooo10(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooo10, _flag);
    return 0;
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

int setter__node__oooooooo11(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooooo11, _flag);
    return 0;
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

int setter__node__ooooooooo9(node* c, uint32_t _flag, ...)
{    
    SETTER(c->ooooooooo9, _flag);
    return 0;
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

int setter__node__ooooooooooooooo7(node* c, uint32_t _flag, ...)
{    
    SETTER(c->ooooooooooooooo7, _flag);
    return 0;
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

int setter__node__oooooo21(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooo21, _flag);
    return 0;
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
    label__3__25:
        return rfl__3__25(cls, _value, tag);
    label__3__24:
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

int setter__node__oooo19(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooo19, _flag);
    return 0;
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

int setter__node__base(node* c, uint32_t _flag, ...)
{
    auto _ptr = static_cast<base*>(c);
    SETTER(*_ptr, _flag);
    return 0;
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

int setter__node__oooooo24(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooo24, _flag);
    return 0;
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

int setter__node__oooooo22(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooo22, _flag);
    return 0;
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

int setter__node__oooo20(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooo20, _flag);
    return 0;
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

int setter__node__oooooo25(node* c, uint32_t _flag, ...)
{    
    SETTER(c->oooooo25, _flag);
    return 0;
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

int invoke__node__deinit__7(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 0)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        va_end(__arguments_list);
        cls->deinit();
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__deinit__0__0(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2928 == value) // ()
    {
        if (!tag)
        {
            return g_node_func[e__node__deinit__7];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

int invoke__node__deinit__6(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 1)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        va_end(__arguments_list);
        _r = cls->deinit();
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__deinit__0__1(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2928746e69 == value) // int()
    {
        if (!tag)
        {
            return g_node_func[e__node__deinit__6];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

meta<node>& invoke__node__deinit(const node *c, const std::string &bra)
{
    branch_string tag(bra);
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

int invoke__node__init__2(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 4)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        auto _a_0 = va_arg(__arguments_list, double);
        auto _a_1 = va_arg(__arguments_list, double);
        auto _a_2 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        _r = cls->init(_a_0, _a_1, _a_2);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__init__3__0(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20726168 == value) // har *)
    {
        if (!tag)
        {
            return g_node_func[e__node__init__2];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__2__0(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f632c == value) // ,const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__3__0(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__1__0(const node *c, uint64_t value, branch_string &tag)
{
    if (0x656c62756f642c74 == value) // t,double
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__2__0(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__0__3(const node *c, uint64_t value, branch_string &tag)
{
    if (0x616f6c6628746e69 == value) // int(floa
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__1__0(c, _value, tag);
        }
    }
    return g_default_meta;
}

int invoke__node__init__1(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 2)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _a_0 = va_arg(__arguments_list, int);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        cls->init(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__init__2__1(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a == value) // *)
    {
        if (!tag)
        {
            return g_node_func[e__node__init__1];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__1__1(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2072616863207473 == value) // st char 
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__2__1(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__0__6(const node *c, uint64_t value, branch_string &tag)
{
    if (0x6e6f632c746e6928 == value) // (int,con
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__1__1(c, _value, tag);
        }
    }
    return g_default_meta;
}

int invoke__node__init__4(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 1)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        va_end(__arguments_list);
        _r = cls->init();
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__init__0__7(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2928746e69 == value) // int()
    {
        if (!tag)
        {
            return g_node_func[e__node__init__4];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

int invoke__node__init__5(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 0)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        va_end(__arguments_list);
        cls->init();
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__init__0__9(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2928 == value) // ()
    {
        if (!tag)
        {
            return g_node_func[e__node__init__5];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

int invoke__node__init__3(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 3)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _a_0 = va_arg(__arguments_list, double);
        auto _a_1 = va_arg(__arguments_list, double);
        auto _a_2 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        cls->init(_a_0, _a_1, _a_2);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__init__3__1(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20 == value) //  *)
    {
        if (!tag)
        {
            return g_node_func[e__node__init__3];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__2__2(const node *c, uint64_t value, branch_string &tag)
{
    if (0x726168632074736e == value) // nst char
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__3__1(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__1__2(const node *c, uint64_t value, branch_string &tag)
{
    if (0x6f632c656c62756f == value) // ouble,co
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__2__2(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__0__10(const node *c, uint64_t value, branch_string &tag)
{
    if (0x642c74616f6c6628 == value) // (float,d
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__1__2(c, _value, tag);
        }
    }
    return g_default_meta;
}

int invoke__node__init__0(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 3)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        auto _a_0 = va_arg(__arguments_list, int);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        _r = cls->init(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__init__2__3(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a207261 == value) // ar *)
    {
        if (!tag)
        {
            return g_node_func[e__node__init__0];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__1__3(const node *c, uint64_t value, branch_string &tag)
{
    if (0x68632074736e6f63 == value) // const ch
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__2__3(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__init__0__11(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2c746e6928746e69 == value) // int(int,
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__init__1__3(c, _value, tag);
        }
    }
    return g_default_meta;
}

meta<node>& invoke__node__init(const node *c, const std::string &bra)
{
    branch_string tag(bra);
    if (tag)
    {
        constexpr void *__meta_label[] = {
            &&label_3,
            &&label_4,
            &&label_5,
            &&label_6,
            &&label_7,
            &&label_8,
            &&label_9,
            &&label_10,
            &&label_11,
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];
    label_3:
        return invoke__init__0__3(c, _value, tag);
    label_6:
        return invoke__init__0__6(c, _value, tag);
    label_7:
        return invoke__init__0__7(c, _value, tag);
    label_9:
        return invoke__init__0__9(c, _value, tag);
    label_10:
        return invoke__init__0__10(c, _value, tag);
    label_11:
        return invoke__init__0__11(c, _value, tag);
    label_4:
    label_5:
    label_8:
        return g_default_meta;
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll0__8(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 3)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        _r = cls->lllllllllllllllllllllllllll0(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll0__3__2(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20726168 == value) // har *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll0__8];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll0__2__4(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f632c == value) // ,const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll0__3__2(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll0__1__4(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2a20726168632074 == value) // t char *
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll0__2__4(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll0__0__13(const node *c, uint64_t value, branch_string &tag)
{
    if (0x736e6f6328746e69 == value) // int(cons
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll0__1__4(c, _value, tag);
        }
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll0__9(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 2)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        cls->lllllllllllllllllllllllllll0(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll0__3__3(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20 == value) //  *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll0__9];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll0__2__5(const node *c, uint64_t value, branch_string &tag)
{
    if (0x726168632074736e == value) // nst char
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll0__3__3(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll0__1__5(const node *c, uint64_t value, branch_string &tag)
{
    if (0x6f632c2a20726168 == value) // har *,co
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll0__2__5(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll0__0__14(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f6328 == value) // (const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll0__1__5(c, _value, tag);
        }
    }
    return g_default_meta;
}

meta<node>& invoke__node__lllllllllllllllllllllllllll0(const node *c, const std::string &bra)
{
    branch_string tag(bra);
    if (tag)
    {
        constexpr void *__meta_label[] = {
            &&label_12,
            &&label_13,
            &&label_14,
            &&label_15,
            &&label_16,
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];
    label_13:
        return invoke__lllllllllllllllllllllllllll0__0__13(c, _value, tag);
    label_14:
        return invoke__lllllllllllllllllllllllllll0__0__14(c, _value, tag);
    label_12:
    label_15:
    label_16:
        return g_default_meta;
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll1__10(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 3)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        _r = cls->lllllllllllllllllllllllllll1(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll1__3__4(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20726168 == value) // har *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll1__10];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll1__2__6(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f632c == value) // ,const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll1__3__4(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll1__1__6(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2a20726168632074 == value) // t char *
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll1__2__6(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll1__0__18(const node *c, uint64_t value, branch_string &tag)
{
    if (0x736e6f6328746e69 == value) // int(cons
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll1__1__6(c, _value, tag);
        }
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll1__11(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 2)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        cls->lllllllllllllllllllllllllll1(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll1__3__5(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20 == value) //  *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll1__11];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll1__2__7(const node *c, uint64_t value, branch_string &tag)
{
    if (0x726168632074736e == value) // nst char
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll1__3__5(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll1__1__7(const node *c, uint64_t value, branch_string &tag)
{
    if (0x6f632c2a20726168 == value) // har *,co
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll1__2__7(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll1__0__19(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f6328 == value) // (const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll1__1__7(c, _value, tag);
        }
    }
    return g_default_meta;
}

meta<node>& invoke__node__lllllllllllllllllllllllllll1(const node *c, const std::string &bra)
{
    branch_string tag(bra);
    if (tag)
    {
        constexpr void *__meta_label[] = {
            &&label_17,
            &&label_18,
            &&label_19,
            &&label_20,
            &&label_21,
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];
    label_18:
        return invoke__lllllllllllllllllllllllllll1__0__18(c, _value, tag);
    label_19:
        return invoke__lllllllllllllllllllllllllll1__0__19(c, _value, tag);
    label_17:
    label_20:
    label_21:
        return g_default_meta;
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll2__12(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 3)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        _r = cls->lllllllllllllllllllllllllll2(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll2__3__6(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20726168 == value) // har *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll2__12];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll2__2__8(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f632c == value) // ,const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll2__3__6(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll2__1__8(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2a20726168632074 == value) // t char *
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll2__2__8(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll2__0__23(const node *c, uint64_t value, branch_string &tag)
{
    if (0x736e6f6328746e69 == value) // int(cons
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll2__1__8(c, _value, tag);
        }
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll2__13(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 2)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        cls->lllllllllllllllllllllllllll2(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll2__3__7(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20 == value) //  *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll2__13];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll2__2__9(const node *c, uint64_t value, branch_string &tag)
{
    if (0x726168632074736e == value) // nst char
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll2__3__7(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll2__1__9(const node *c, uint64_t value, branch_string &tag)
{
    if (0x6f632c2a20726168 == value) // har *,co
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll2__2__9(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll2__0__24(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f6328 == value) // (const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll2__1__9(c, _value, tag);
        }
    }
    return g_default_meta;
}

meta<node>& invoke__node__lllllllllllllllllllllllllll2(const node *c, const std::string &bra)
{
    branch_string tag(bra);
    if (tag)
    {
        constexpr void *__meta_label[] = {
            &&label_22,
            &&label_23,
            &&label_24,
            &&label_25,
            &&label_26,
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];
    label_23:
        return invoke__lllllllllllllllllllllllllll2__0__23(c, _value, tag);
    label_24:
        return invoke__lllllllllllllllllllllllllll2__0__24(c, _value, tag);
    label_22:
    label_25:
    label_26:
        return g_default_meta;
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll3__14(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 3)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        _r = cls->lllllllllllllllllllllllllll3(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll3__3__8(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20726168 == value) // har *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll3__14];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll3__2__10(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f632c == value) // ,const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll3__3__8(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll3__1__10(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2a20726168632074 == value) // t char *
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll3__2__10(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll3__0__28(const node *c, uint64_t value, branch_string &tag)
{
    if (0x736e6f6328746e69 == value) // int(cons
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll3__1__10(c, _value, tag);
        }
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll3__15(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 2)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        cls->lllllllllllllllllllllllllll3(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll3__3__9(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20 == value) //  *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll3__15];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll3__2__11(const node *c, uint64_t value, branch_string &tag)
{
    if (0x726168632074736e == value) // nst char
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll3__3__9(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll3__1__11(const node *c, uint64_t value, branch_string &tag)
{
    if (0x6f632c2a20726168 == value) // har *,co
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll3__2__11(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll3__0__29(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f6328 == value) // (const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll3__1__11(c, _value, tag);
        }
    }
    return g_default_meta;
}

meta<node>& invoke__node__lllllllllllllllllllllllllll3(const node *c, const std::string &bra)
{
    branch_string tag(bra);
    if (tag)
    {
        constexpr void *__meta_label[] = {
            &&label_27,
            &&label_28,
            &&label_29,
            &&label_30,
            &&label_31,
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];
    label_28:
        return invoke__lllllllllllllllllllllllllll3__0__28(c, _value, tag);
    label_29:
        return invoke__lllllllllllllllllllllllllll3__0__29(c, _value, tag);
    label_27:
    label_30:
    label_31:
        return g_default_meta;
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll4__16(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 3)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        _r = cls->lllllllllllllllllllllllllll4(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll4__3__10(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20726168 == value) // har *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll4__16];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll4__2__12(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f632c == value) // ,const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll4__3__10(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll4__1__12(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2a20726168632074 == value) // t char *
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll4__2__12(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll4__0__33(const node *c, uint64_t value, branch_string &tag)
{
    if (0x736e6f6328746e69 == value) // int(cons
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll4__1__12(c, _value, tag);
        }
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll4__17(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 2)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _a_0 = va_arg(__arguments_list, const char *);
        auto _a_1 = va_arg(__arguments_list, const char *);
        va_end(__arguments_list);
        cls->lllllllllllllllllllllllllll4(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll4__3__11(const node *c, uint64_t value, branch_string &tag)
{
    if (0x292a20 == value) //  *)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll4__17];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll4__2__13(const node *c, uint64_t value, branch_string &tag)
{
    if (0x726168632074736e == value) // nst char
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll4__3__11(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll4__1__13(const node *c, uint64_t value, branch_string &tag)
{
    if (0x6f632c2a20726168 == value) // har *,co
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll4__2__13(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll4__0__34(const node *c, uint64_t value, branch_string &tag)
{
    if (0x632074736e6f6328 == value) // (const c
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll4__1__13(c, _value, tag);
        }
    }
    return g_default_meta;
}

meta<node>& invoke__node__lllllllllllllllllllllllllll4(const node *c, const std::string &bra)
{
    branch_string tag(bra);
    if (tag)
    {
        constexpr void *__meta_label[] = {
            &&label_32,
            &&label_33,
            &&label_34,
            &&label_35,
            &&label_36,
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];
    label_33:
        return invoke__lllllllllllllllllllllllllll4__0__33(c, _value, tag);
    label_34:
        return invoke__lllllllllllllllllllllllllll4__0__34(c, _value, tag);
    label_32:
    label_35:
    label_36:
        return g_default_meta;
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll5__19(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 2)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto& _a_0 = *(va_arg(__arguments_list, const std::string *));
        auto& _a_1 = *(va_arg(__arguments_list, const std::string *));
        va_end(__arguments_list);
        cls->lllllllllllllllllllllllllll5(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__5__0(const node *c, uint64_t value, branch_string &tag)
{
    if (0x29 == value) // )
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll5__19];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__4__0(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2620676e69727473 == value) // string &
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__5__0(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__3__12(const node *c, uint64_t value, branch_string &tag)
{
    if (0x3a3a647473207473 == value) // st std::
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__4__0(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__2__14(const node *c, uint64_t value, branch_string &tag)
{
    if (0x6e6f632c2620676e == value) // ng &,con
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__3__12(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__1__14(const node *c, uint64_t value, branch_string &tag)
{
    if (0x697274733a3a6474 == value) // td::stri
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__2__14(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__0__37(const node *c, uint64_t value, branch_string &tag)
{
    if (0x732074736e6f6328 == value) // (const s
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__1__14(c, _value, tag);
        }
    }
    return g_default_meta;
}

int invoke__node__lllllllllllllllllllllllllll5__18(const node *c, uint64_t argc, ...)
{
    auto *cls = (node *)(c); 
    if (cls && argc == 3)
    {
        va_list __arguments_list;
        va_start(__arguments_list, argc);
        auto _r = va_arg(__arguments_list, int);
        auto& _a_0 = *(va_arg(__arguments_list, const std::string *));
        auto& _a_1 = *(va_arg(__arguments_list, const std::string *));
        va_end(__arguments_list);
        _r = cls->lllllllllllllllllllllllllll5(_a_0, _a_1);
        return 0;
    }
    return -1;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__5__1(const node *c, uint64_t value, branch_string &tag)
{
    if (0x29262067 == value) // g &)
    {
        if (!tag)
        {
            return g_node_func[e__node__lllllllllllllllllllllllllll5__18];
        }
        return g_default_meta;
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__4__1(const node *c, uint64_t value, branch_string &tag)
{
    if (0x6e697274733a3a64 == value) // d::strin
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__5__1(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__3__13(const node *c, uint64_t value, branch_string &tag)
{
    if (0x74732074736e6f63 == value) // const st
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__4__1(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__2__15(const node *c, uint64_t value, branch_string &tag)
{
    if (0x2c2620676e697274 == value) // tring &,
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__3__13(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__1__15(const node *c, uint64_t value, branch_string &tag)
{
    if (0x733a3a6474732074 == value) // t std::s
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__2__15(c, _value, tag);
        }
    }
    return g_default_meta;
}

inline meta<node> &invoke__lllllllllllllllllllllllllll5__0__39(const node *c, uint64_t value, branch_string &tag)
{
    if (0x736e6f6328746e69 == value) // int(cons
    {
        if (tag)
        {
            auto _value = tag();
            return invoke__lllllllllllllllllllllllllll5__1__15(c, _value, tag);
        }
    }
    return g_default_meta;
}

meta<node>& invoke__node__lllllllllllllllllllllllllll5(const node *c, const std::string &bra)
{
    branch_string tag(bra);
    if (tag)
    {
        constexpr void *__meta_label[] = {
            &&label_37,
            &&label_38,
            &&label_39,
        };
        constexpr auto count = countof(__meta_label);
        auto _value = tag();
        auto index = _value % count;        
        goto *__meta_label[index];
    label_37:
        return invoke__lllllllllllllllllllllllllll5__0__37(c, _value, tag);
    label_39:
        return invoke__lllllllllllllllllllllllllll5__0__39(c, _value, tag);
    label_38:
        return g_default_meta;
    }
    return g_default_meta;
}

const uint64_t get_fields_max(const node *cls)
{
    return countof(g_node_meta);
}
namespace __details__
{    
    meta<node>& get_meta(const node *cls, branch_string &tag)
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
    label__0__16:
        return rfl__0__16(cls, value, tag);
    label__0__17:
        return rfl__0__17(cls, value, tag);
    label__0__22:
        return rfl__0__22(cls, value, tag);
    label__0__24:
        return rfl__0__24(cls, value, tag);
    label__0__0:
    label__0__4:
    label__0__6:
    label__0__7:
    label__0__8:
    label__0__12:
    label__0__14:
    label__0__15:
    label__0__18:
    label__0__19:
    label__0__20:
    label__0__21:
    label__0__23:
        return g_default_meta;
    }
    meta<node>& get_meta(const node *cls, branch_string &tag, const std::string &args_tag)
    {
        return get_meta(cls, tag).m_invoke(cls, args_tag);    
    }    
}
reflect::Value get_value(const node *cls, const std::string &_tag)
{
    branch_string tag(_tag); 
    auto _meta = __details__::get_meta(cls, tag);
    if (__contains__(_meta.m_flags, flag_member))
    {
        return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);  
    }      
    return __get_value(cls, _tag);   
}
reflect::Value get_value(const node *cls, const char *tag)
{
    return get_value(cls, std::string(tag));
}
reflect::Value get_value(const node *cls, const std::string &_tag, const char *expected_type)
{
    branch_string tag(_tag);
    auto _meta = __details__::get_meta(cls, tag);
    if  (strcmp(expected_type, _meta.m_type) == 0) 
    {
        return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);    
    }
    return reflect::Value(nullptr, 0);
}
reflect::Value get_field_value(const node *cls, uint32_t field)
{
    if (field < get_fields_max(cls))
    {
        auto& _meta = g_node_meta[field];        
        return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);        
    }
    return reflect::Value(nullptr, 0);
}
const char* get_type(const node *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;
}
const char* get_type(const node *cls, const char *_tag) 
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_type;    
}
const char *get_type(const node *cls)
{
    static const char _class[] = "node";
    return _class;
}
uint64_t get_field(const node *cls, const std::string &_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
uint64_t get_field(const node *cls, const char *_tag)
{
    branch_string tag(_tag);
    return __details__::get_meta(cls, tag).m_field;  
}
const char* get_name(const node *cls, uint32_t field)
{
    if (field < get_fields_max(cls))
    {
        return g_node_meta[field].m_variant;
    }
    return g_default_meta.m_variant;
}
meta<node> &get_meta(const node *cls)
{
    return g_node;
}

