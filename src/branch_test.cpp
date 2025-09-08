#include <gtest/gtest.h>
#include "analyzer.h"
#include "branch.h"

TEST(branch_map, test_alpha)
{

    analyzer a;
    a.push_back("aaaaaaaaaaa");
    a.push_back("bbbbbbbbbbb");
    a.push_back("ccccccccccc");
    a.push_back("ddddddddddd");
    a.push_back("eeeeeeeeeee");
    a.push_back("fffffffffff");
    a.push_back("ggggggggggg");

    auto b = branch_builder(0, a);
}