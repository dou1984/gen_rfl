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

int main()
{
    struct node n;
    n.a = 1;
    n.ooooooooooooooooooooooooooooo0 = "new string";

    char test[] = "hello world";
    n.oooo19 = test;

    std::cout << get_type(&n, "oooo19") << "=" << get_value<char *>(&n, "oooo19") << std::endl;

    std::cout << "ooooooooooooooooooooooooooo13" << get_value<char *>(&n, "ooooooooooooooooooooooooooo13") << std::endl;
  
    auto _base = get_value<base>(&n, "base");
    auto r = get_value<const char *>(_base, "ooooooooooooooooooooooooooooo0");

    std::cout << r << std::endl;
    set_value(&n, "oooooooooooooooooooooooooo0", (char *)0);

    std::string method = "init";
    const char *hello = "hello world";

    int ret = 0;
    auto s = invoke_r(&n, method, ret, 1, hello);
    s = invoke_r(&n, method, ret, 2, hello);
    s = invoke(&n, method, 3, hello);

    func f;
    s = invoke(&f, "done");

    // std::string l0 = "l0";
    // std::string l1 = "l1";
    // s = invoke(&n, "lllllllllllllllllllllllllll5", l0, l1); // error
    return 0;
}