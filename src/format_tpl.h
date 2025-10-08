// Copyright (c) 2023-2025 ZhaoYunshan
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

#pragma once
#include <string>
#include <ctemplate/template.h>
#include <ctemplate/template_string.h>
#include "branch.h"
#include "analyzer.h"

class format_tpl
{
public:
    format_tpl();

    int to_header(branch &sel, analyzer &ana);

    int to_meta(branch &sel, analyzer &ana);

    int to_get_meta(branch &sel, analyzer &ana);

    int to_func(uint32_t layer, uint32_t index, branch &sel);

    int to_invoke(uint32_t layer, uint32_t index, const std::string &variant, const branch_info &bra);

    int to_invoke_field(const branch_info &bra);

    int to_invoke_layer(const std::string &variant, const branch_map &bra);

    int to_rfl(branch &sel, analyzer &ana);

    int to_file(analyzer &ana, const std::string &header, const std::string &source);

public:
    int to_rfl();

    int to_base_types();

    int to_base_types_source();

    auto &get() const { return m_output_source; }

    static int init();

private:
    std::string m_output_header;
    std::list<std::string> m_output_source;
    std::string m_output_makefile;
};
