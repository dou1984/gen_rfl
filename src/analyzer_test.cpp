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
    reflect::analyzer a;
    auto info1 = std::make_shared<reflect::analyzer::info_t>();
    auto info2 = std::make_shared<reflect::analyzer::info_t>();
    auto info3 = std::make_shared<reflect::analyzer::info_t>();
    auto info4 = std::make_shared<reflect::analyzer::info_t>();
    auto info5 = std::make_shared<reflect::analyzer::info_t>();
    auto info6 = std::make_shared<reflect::analyzer::info_t>();
    a.push_back("hellooooooo", info1);
    a.push_back("worldddddddd", info2);
    a.push_back("select", info3);
    a.push_back("where", info4);
    a.push_back("and", info5);
    a.push_back("or", info6);

    auto t = a.calc_perfect_index();

    EXPECT_EQ(t, 13);
    auto x = a.get_data();
    auto it = x.find("hellooooooo");
    EXPECT_EQ(it->second->m_value, 8029759184975979880u);
    it = x.find("worldddddddd");
    EXPECT_EQ(it->second->m_value, 7234017283942805367u);
}