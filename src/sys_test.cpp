#include <gtest/gtest.h>
#include <iostream>
#include "sys.h"

TEST(sys, GetRelativePath)
{
    auto path = GetRelativePath("/home/xxxx/github/genreflect/examples/node.h", "/home/xxxx/github/genreflect/examples");

    std::cout << "node:" << path << std::endl;

    EXPECT_EQ(path, "..");

    path = GetRelativePath("/home/xxxx/github/genreflect/examples/node.h", "/home/xxxx/github/genreflect/examples/gen_rfl");


}