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

    for (auto i = 0; i < get_fields_max(&n); ++i)
    {
        std::cout << get_name(&n, i) << "=" << get_value(&n, get_name(&n, i)) << std::endl;
    }

    fastest::common c;

    for (auto i = 0; i < get_fields_max(&c); ++i)
    {
        std::cout << get_name(&c, i) << "=" << get_value(&c, get_name(&c, i)) << std::endl;
    }

    auto &_base = get_value<base>(&n, "base");
    auto r = get_value<const char *>(&_base, "ooooooooooooooooooooooooooooo0");

    std::cout << r << std::endl;
    set_value(&n, "oooooooooooooooooooooooooo0", (char *)0);

    std::string method = "init";
    const char *hello = "hello world";

    int ret = 0;
    auto s = invoke_r(&n, method, ret, 1, hello);
    s = invoke_r(&n, method, ret, 2, hello);

    func f;
    s = invoke(&f, "done");

    // std::string l0 = "l0";
    // std::string l1 = "l1";
    // s = invoke(&n, "lllllllllllllllllllllllllll5", l0, l1); // error
    return 0;
}