#include <iostream>
#include "node.h"
#include "base.reflect.h"
#include "node.reflect.h"

using namespace reflect;
using namespace ashan;

int main()
{
    node o = {
        .x = 100,
        .y = 0.2,
        .z = 0.001,
        .h = {
            .a = 99,
            .b = 98,
            .d = 0xfffff,
            .k = "helloworld",
        },
    };        

    std::cout << "set c=" << o.h.c << std::endl;
    std::cout << "field:" << get_field(o.h, "a") << get_field(o.h, "b") << std::endl;
    std::cout << "field:" << get_info(o.h, "a").field << get_info(o.h, "b").field << std::endl;
    std::cout << get_type(o, "x") << get_type(o, "y") <<get_type(o,"z")<< get_type(o, "h") << std::endl;
    std::cout << get_type(o.h, "a") << get_type(o.h, "b") << std::endl;
    std::cout << get_info(o.h, "a").type << get_info(o.h, "b").type << std::endl;
    std::cout << get_value<int>(o,"x") << get_value<float>(o, "y") << get_value<double>(o, "z") <<std::endl;

    auto& h = get_value<base>(o, "h");
    std::cout<< get_value<int64_t>(h, "d") << get_value<std::string>(h, "k")  << std::endl;

    for (size_t i = 0; i < field_max(o.h); i++)
    {
        std::cout << field_member(o.h, i) << ":" << field_type(o.h, i) << std::endl;
    }
    for (size_t i = 0; i < field_max(o); i++)
    {
        std::cout << field_member(o, i) << ":" << field_type(o, i) <<std::endl;
    }

    return 0;
}
