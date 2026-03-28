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
#include "branch.h"

TEST(branch_map, test_alpha)
{

    reflect::branch_info bra;
    auto info1 = std::make_shared<reflect::analyzer::info_t>();
    auto info2 = std::make_shared<reflect::analyzer::info_t>();
    auto info3 = std::make_shared<reflect::analyzer::info_t>();
    auto info4 = std::make_shared<reflect::analyzer::info_t>();
    auto info5 = std::make_shared<reflect::analyzer::info_t>();
    auto info6 = std::make_shared<reflect::analyzer::info_t>();
    auto info7 = std::make_shared<reflect::analyzer::info_t>();
    bra.ana().push_back("aaaaaaaaaaa", info1);
    bra.ana().push_back("bbbbbbbbbbb", info2);
    bra.ana().push_back("ccccccccccc", info3);
    bra.ana().push_back("ddddddddddd", info4);
    bra.ana().push_back("eeeeeeeeeee", info5);
    bra.ana().push_back("fffffffffff", info6);
    bra.ana().push_back("ggggggggggg", info7);

    bra.builder(0);
}