#include <gtest/gtest.h>
#include "branch_string.h"
TEST(branch_string, normal)
{
    const char *str = "hello world! everyone";
    branch_string b(str);

    EXPECT_TRUE(b);
    EXPECT_EQ(b(), 8031924123371070824u);
    EXPECT_TRUE(b);
    EXPECT_EQ(b(), 7311142233756167282u);
    EXPECT_TRUE(b);
    EXPECT_EQ(b(), 435644496242);
}

TEST(branch_string, empty)
{
    std::string str = "oooooooooooo";
    branch_string b(str);

    EXPECT_TRUE(b);
    EXPECT_EQ(b(), 0x6f6f6f6f6f6f6f6f);
    EXPECT_TRUE(b);
    EXPECT_EQ(b(), 1869573999);
    EXPECT_FALSE(b);
}