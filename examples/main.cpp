#include <iostream>
#include "node.h"
#include "base/common.h"
#include "gen_rfl/rfl.h"

int main()
{
    node n;
    n.a = 1;

    char test[] = "hello world";
    n.oooo19 = test;

    std::cout << get_type(&n, "oooo19") << "=" << get_value<char *>(&n, "oooo19") << std::endl;

    return 0;
}