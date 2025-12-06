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
#include "branch_string.h"
#include "branch.h"
#include "format_tpl.h"

TEST(format, rander_string)
{
    EXPECT_TRUE(ctemplate::StringToTemplateCache("test.tpl", "{{grand}} {{name}}", ctemplate::DO_NOT_STRIP));

    ctemplate::TemplateDictionary dict("test");
    dict.SetValue("grand", "hello");
    dict.SetValue("name", "world");

    std::string result;
    auto _tpl = ctemplate::Template::GetTemplate("test.tpl", ctemplate::DO_NOT_STRIP);
    EXPECT_TRUE(_tpl != nullptr);

    EXPECT_TRUE(_tpl->Expand(&result, &dict));

    EXPECT_EQ(result, "hello world");

    std::cout << result << std::endl;
}
TEST(format, rander_file)
{
    EXPECT_TRUE(ctemplate::Template::SetTemplateRootDirectory("/home/dou1984/github/genreflect/src/tpl/"));

    ctemplate::TemplateDictionary dict("rfl");
    auto includes = dict.AddSectionDictionary("includes");
    includes->SetValue("header", "#include <iostream>");

    std::string result;
    EXPECT_TRUE(ctemplate::ExpandTemplate("rfl.tpl", ctemplate::DO_NOT_STRIP, &dict, &result));

    EXPECT_EQ(result, R"word(
#pragma once
#include "base_types.h"
)word");

    std::cout << result << std::endl;
}
TEST(format, rander_branch)
{

    branch_info bra;
    bra.push_back("hello");
    bra.push_back("world");
    bra.push_back("say");
    bra.push_back("hi");

    bra.builder(0);

    format_tpl tpl;
    tpl.to_header(bra);
    tpl.to_file("header.h", "source.cpp");
}
