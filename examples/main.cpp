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
#include <iostream>
#include "node.h"
#include "base/common.h"
#include "gen_rfl/rfl.h"

int set_base()
{
    base b = {0};

    set_value(&b, "a", 10);
    set_value(&b, "b", 10);
    set_value(&b, "c", 10);
    set_value(&b, "d", 10);
    set_value(&b, "e", 10);
    set_value(&b, "f", 10);
    set_value(&b, "g", 10);
    set_value(&b, "h", 10);
    set_value(&b, "i", 10);
    set_value(&b, "j", 10);
    set_value(&b, "k", 10);
    assert(b.a == 10);
    assert(b.b == 10);
    assert(b.c == 10);
    assert(b.d == 10);
    assert(b.e == 10);
    assert(b.f == 10);
    assert(b.g == 10);
    assert(b.i == 10);
    assert(b.j == 10);
    assert(b.k == "10");

    set_value(&b, "a", "-100");
    assert(b.a == -100);
    set_value(&b, "k", "hello");
    assert(b.k == "hello");
    set_value(&b, "ooooooooooooooooooooooooooool0", "999");
    assert(strcmp(b.ooooooooooooooooooooooooooool0, "999") == 0);
    auto r = set_value(&b, "e", "-1000");
    assert(r == -1);
    set_value(&b, "e", "100");
    assert(b.e == 100);

    set_value(&b, "o", std::vector<int>{0, 1, 2, 3});
    return 0;
}

int get_node()
{
    node n = {0};
    n.a = 1;
    n.oooooooooooooooooooooooooo0 = "new string";
    n.ooooooooooooooooooooooooooool0 = "000";

    char test[] = "hello world";
    n.oooo19 = test;

    assert(get_value(&n, "oooo19").to_string() == test);

    assert(get_value(&n, "ooooooooooooooooooooooooooo13").to_string() == "");

    assert(strcmp(get_value(&n, "ooooooooooooooooooooooooooool0").as_cstr(), "000") == 0);

    base b = {0};
    b.a = 1;
    b.b = 2;
    b.c = 3;
    b.d = 4;

    {
        auto pn = &b;
        for (auto i = 0; i < get_fields_count(pn); i++)
        {
            std::cout << get_field_type(pn, i) << " " << get_name(pn, i) << " " << get_field_value(pn, i).to_string() << std::endl;
        }
    }
    set_value(&n, "base", b);

    assert(n.a == 1);
    assert(n.b == 2);
    assert(n.c == 3);
    assert(n.d == 4);

    {
        auto pn = &n;
        for (auto i = 0; i < get_fields_count(pn); i++)
        {
            std::cout << get_field_type(pn, i) << " " << get_name(pn, i) << " " << get_field_value(pn, i).to_string() << std::endl;
        }
    }

    std::cout << get_value(&n, "a").to_string() << get_value(&n, "b").to_string() << get_value(&n, "c").to_string() << get_value(&n, "d").to_string() << std::endl;
    return 0;
}
int invoke_node()
{
    int ret = 0;
    node n;
    std::string method = "init";
    const char *hello = "hello world";
    auto s = invoke_r(&n, method, ret, 1, hello);
    s = invoke_r(&n, method, ret, 2, hello);
    s = invoke(&n, method, 3, hello);

    func f;
    s = invoke(&f, "done");

    std::string l0 = "l0";
    std::string l1 = "l1";
    int r = 0;
    s = invoke_r(&n, "lllllllllllllllllllllllllll5", r, l0, l1);
    assert(r == 200);

    std::string c0;
    std::string c1;
    s = invoke_r(&n, "lllllllllllllllllllllllllll6", r, c0, c1);
    assert(r == 301);

    return 0;
}

int invoke_node2()
{
    node n;

    const char *ptr = "hello";
    int i = 1;
    long j = 1;
    auto s = invoke(&n, "init", i, j, ptr);

    int i0 = 10;
    int i1 = 20;
    int r0 = 0;
    s = invoke_r(&n, "add", r0, i0, i1);
    return 0;
}

int main()
{
    set_base();

    get_node();

    invoke_node();

    invoke_node2();
    return 0;
}