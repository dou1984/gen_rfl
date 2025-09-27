#include <gtest/gtest.h>
#include "analyzer.h"

TEST(analyzer, push_back)
{
    analyzer a;
    a.push_back("hellooooooo");
    a.push_back("worldddddddd");
    a.push_back("select");
    a.push_back("where");
    a.push_back("and");
    a.push_back("or");

    auto t = a.calc_perfect_index();

    EXPECT_EQ(t, 9);
    auto x = a.get_data();
    EXPECT_EQ(x["hellooooooo"].m_value, 8029759184975979880u);
    EXPECT_EQ(x["worldddddddd"].m_value, 7234017283942805367u);
}