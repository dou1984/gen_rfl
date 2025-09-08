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

TEST(format, rander_branch)
{
    analyzer ana;
    ana.push_back("hello");
    ana.push_back("world");
    ana.push_back("say");
    ana.push_back("hi");

    branch bra = branch_builder(0, ana);

    format_tpl tpl;
    tpl.to_header(bra, ana);
    tpl.to_file(ana, "header.h", "source.cpp");
}