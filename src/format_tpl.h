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
