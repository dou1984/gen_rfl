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
    auto it = x.find("hellooooooo");
    EXPECT_EQ(it->second.m_value, 8029759184975979880u);
    it = x.find("worldddddddd");
    EXPECT_EQ(it->second.m_value, 7234017283942805367u);
}