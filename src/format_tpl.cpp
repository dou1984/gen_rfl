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

#include "format_tpl.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstring>
#include "reflect.h"
#include "config.h"
#include "tpl/tpl.h"
#include "sys.h"

using namespace reflect;

int to_hex(uint64_t value, char *buf, int size)
{
    return snprintf(buf, size, "0x%lx", value);
}
int to_comment(uint64_t value, char *buf, int size)
{
    char v[sizeof(uint64_t) + 1] = {0};
    strncpy(v, (const char *)&value, sizeof(uint64_t));
    return snprintf(buf, size, "%s", v);
}
std::string compatible(const std::string &t)
{
    if (t == "float")
    {
        static std::string r = "double";
        return r;
    }
    if (t.back() == '&')
    {
        auto r = t;
        r.pop_back();
        return r;
    }
    return t;
}
std::string __field(uint32_t field)
{
    return std::string("__") + std::to_string(field);
}
std::string remove_duplicate_const(const std::string &type)
{
    return (type.find("const const") == 0) ? type.substr(6) : type;
}
int format_tpl::init()
{
    if (!ctemplate::StringToTemplateCache("header.tpl", tpl::header(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error header.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("meta.tpl", tpl::meta(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error meta.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("get_meta.tpl", tpl::get_meta(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error get_meta.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("func.tpl", tpl::func(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error func.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("invoke_field.tpl", tpl::invoke_field(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error invoke_field.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("invoke.tpl", tpl::invoke(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error invoke.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("invoke_layer.tpl", tpl::invoke_layer(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error invoke_layer.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("rfl.tpl", tpl::rfl(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error rfl.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("base_types.tpl", tpl::base_types(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error base_types.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("base_types_source.tpl", tpl::base_types_source(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error base_types_source.tpl" << std::endl;
        return -1;
    }
    return 0;
}
template <class T>
int write_file(const std::string &path, const T &content)
{

    std::cout << "write to " << path << std::endl;
    std::ofstream f(path.c_str());
    if (f)
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            f << content;
        }
        else
        {
            for (auto &c : content)
            {
                f << c;
            }
        }

        f.close();
    }
    return 0;
}

int expand(const std::string &tpl_key, const ctemplate::TemplateDictionary &dict, std::string &output)
{
    auto _tpl = ctemplate::Template::GetTemplate(tpl_key, ctemplate::DO_NOT_STRIP);
    if (!_tpl)
    {
        std::cerr << "GetTemplate error: " << tpl_key << std::endl;
        return -1;
    }

    if (!_tpl->Expand(&output, &dict))
    {
        std::cerr << "Expand error: " << tpl_key << std::endl;
        return -1;
    }
    return 0;
}
format_tpl::format_tpl()
{
}
int format_tpl::to_header(branch &bra, analyzer &ana)
{
    auto tpl_key = "header.tpl";
    ctemplate::TemplateDictionary _header(tpl_key);
    _header.SetValue("license", tpl::license());
    _header.SetValue("class", ::get_config().m_class);
    _header.SetValue("raw_class", ::get_config().m_raw_class);
    _header.SetValue("header", GetRelativePath(::get_config().m_relative_file, "") + "/base_types.h");

    if (!::get_config().m_namespace.empty())
    {
        auto _namespace = _header.AddSectionDictionary("namesp");
        _namespace->SetValue("namespace", ::get_config().m_namespace);
    }
    expand(tpl_key, _header, m_output_header);
    return 0;
}
int format_tpl::to_meta(analyzer &ana, std::map<std::string, analyzer> &ana_func)
{
    auto tpl_key = "meta.tpl";

    ctemplate::TemplateDictionary _meta(tpl_key);
    auto &conf = ::get_config();

    auto upper_dir = IsCurDir(conf.tmp_dir) ? "/" : "/../";
    auto header_name = GetRelativePath(conf.m_file, conf.real_tmp_dir_loc) + upper_dir + conf.m_relative_file;
    std::cout << "file: " << conf.m_file << std::endl;
    std::cout << "real_tmp_dir: " << conf.real_tmp_dir_loc << std::endl;
    std::cout << "header_name: " << header_name << std::endl;
    _meta.SetValue("license", tpl::license());
    _meta.SetValue("header", header_name);
    _meta.SetValue("class", conf.m_class);
    if (!conf.m_namespace.empty())
    {
        auto _namespace = _meta.AddSectionDictionary("namesp");
        _namespace->SetValue("namespace", conf.m_namespace);
    };

    for (auto &it : ana.get_data())
    {
        auto &field = it.second;

        auto dict = _meta.AddSectionDictionary("fields");
        dict->SetValue("variant", field.m_variant);

        dict->SetValue("type", field.m_raw_type);
        char buf[64];
        to_hex(field.m_flags, buf, sizeof(buf));
        dict->SetValue("flags", buf);
        dict->SetIntValue("field", field.m_field);

        if (__has_flag(field.m_flags, flag_function))
        {
            dict->AddSectionDictionary("is_invoke");
            auto invoke_func = _meta.AddSectionDictionary("invoke_func");
            invoke_func->SetValue("variant", field.m_variant);
        }
        else
        {
            auto is_member = dict->AddSectionDictionary("is_member");
            if (__has_flag(field.m_flags, flag_struct, flag_class))
            {
                is_member->AddSectionDictionary("is_derived");
            }
            else if (__has_flag(field.m_flags, flag_static))
            {
                is_member->AddSectionDictionary("is_static");
            }
            else
            {
                is_member->AddSectionDictionary("is_field");
            }
        }
    }
    for (auto &_func : ana_func)
    {
        for (auto &it : _func.second.get_data())
        {
            auto &field = it.second;

            auto dict = _meta.AddSectionDictionary("invoke_fields");
            dict->SetValue("variant", field.m_raw_variant);
            dict->SetValue("type", field.m_raw_type);

            char buf[64];
            to_hex(field.m_flags, buf, sizeof(buf));
            dict->SetValue("flags", buf);
            dict->SetIntValue("field", field.m_field);
            dict->SetValue("__field", __field(field.m_field));
            if (__has_flag(field.m_flags, flag_argument))
            {
                auto invoke_field = dict->AddSectionDictionary("invoke_field");
                invoke_field->SetValue("variant", field.m_raw_variant);
                invoke_field->SetValue("__field", __field(field.m_field));
            }
        }
    }
    std::string _output;
    expand(tpl_key, _meta, _output);
    m_output_source.emplace_back(std::move(_output));

    return 0;
}

int format_tpl::to_get_meta(branch &bra, analyzer &ana)
{
    auto tpl_key = "get_meta.tpl";
    ctemplate::TemplateDictionary _get_meta(tpl_key);
    _get_meta.SetValue("class", ::get_config().m_class);
    _get_meta.SetValue("layer", std::to_string(0));

    auto _field = 0;
    if (bra.size() > 1)
    {
        auto _meta_multi = _get_meta.AddSectionDictionary("meta_bg_1");
        for (auto &v : bra)
        {
            auto _labels = _meta_multi->AddSectionDictionary("labels");
            _labels->SetIntValue("index", v.m_index);
            if (v.empty())
            {
                auto labels_eq_0 = _meta_multi->AddSectionDictionary("labels_eq_0");
                labels_eq_0->SetIntValue("index", v.m_index);
            }
            else
            {
                auto labels_bg_0 = _meta_multi->AddSectionDictionary("labels_bg_0");
                labels_bg_0->SetIntValue("index", v.m_index);
            }
        }
    }
    else if (bra.size() == 1)
    {
        auto _meta_one = _get_meta.AddSectionDictionary("meta_eq_1");
        auto &v = bra.front();
        _meta_one->SetIntValue("index", v.m_index);
    }
    if (!::get_config().m_namespace.empty())
    {
        auto _namespace = _get_meta.AddSectionDictionary("namesp");
        _namespace->SetValue("namespace", ::get_config().m_namespace);
    }
    std::string _output;
    expand(tpl_key, _get_meta, _output);
    m_output_source.emplace_back(std::move(_output));
    return 0;
}
int format_tpl::to_func(uint32_t layer, uint32_t index, branch &bra)
{
    auto tpl_key = "func.tpl";

    for (auto &_bra : bra)
    {
        if (_bra.empty())
        {
            continue;
        }
        ctemplate::TemplateDictionary _func(tpl_key);
        for (auto &info : _bra)
        {
            _func.SetIntValue("layer", info.second.m_layer);
            _func.SetIntValue("index", info.second.m_index);
            _func.SetValue("class", ::get_config().m_class);
            std::set<uint64_t> _value;
            for (auto &details : info.second.m_variants)
            {
                auto _detail = details.second;
                if (__has_flag(_detail->m_flags, flag_argument))
                {
                    continue;
                }
                if (_value.find(_detail->m_value) != _value.end())
                {
                    continue;
                }
                _value.insert(_detail->m_value);

                to_func(layer + 1, info.second.m_index, info.second.m_branch_child);

                auto block = _func.AddSectionDictionary("block");
                char buf[64];
                to_hex(_detail->m_value, buf, sizeof(buf));
                block->SetValue("value", buf);
                to_comment(_detail->m_value, buf, sizeof(buf));
                block->SetValue("comment", buf);

                if (_detail->m_variant.size() > sizeof(uint64_t))
                {
                    assert(layer == info.second.m_layer);
                    _func.SetIntValue("next_layer", info.second.m_layer + 1);
                    if (info.second.m_branch_child.size() > 1)
                    {
                        auto incomplete_bg_1 = block->AddSectionDictionary("incomplete_bg_1");
                        for (auto &child : info.second.m_branch_child)
                        {
                            auto labels = incomplete_bg_1->AddSectionDictionary("labels");
                            labels->SetIntValue("next_index", child.m_index);
                            if (child.empty())
                            {
                                auto labels_eq_0 = incomplete_bg_1->AddSectionDictionary("labels_eq_0");
                                labels_eq_0->SetIntValue("next_index", child.m_index);
                            }
                            else
                            {
                                auto labels_bg_0 = incomplete_bg_1->AddSectionDictionary("labels_bg_0");
                                labels_bg_0->SetIntValue("next_index", child.m_index);
                            }
                        }
                    }
                    else if (info.second.m_branch_child.size() == 1)
                    {
                        auto incomplete_eq_1 = block->AddSectionDictionary("incomplete_eq_1");
                        incomplete_eq_1->SetIntValue("next_index", info.second.m_branch_child[0].m_index);
                    }
                    else
                    {
                        assert(false);
                    }
                }
                else
                {
                    if (__has_flag(_detail->m_flags, flag_argument))
                    {
                        continue;
                    }
                    auto complete = block->AddSectionDictionary("complete");
                    complete->SetValue("variant", _detail->m_raw_variant);
                    if (__has_flag(_detail->m_flags, flag_argument))
                    {
                        complete->SetValue("__field", __field(_detail->m_field));
                    }
                }
            }
        }

        std::string _output;
        expand(tpl_key, _func, _output);
        m_output_source.emplace_back(std::move(_output));
    }

    return 0;
}

int format_tpl::to_invoke(const std::string &variant, const branch &bra)
{

    for (auto &_bra : bra)
    {
        if (!_bra.empty())
        {
            to_invoke_layer(variant, _bra);
        }
    }
    to_invoke(0, 0, variant, bra);
    return 0;
}
int format_tpl::to_invoke(uint32_t layer, uint32_t index, const std::string &variant, const branch &bra)
{

    auto tpl_key = "invoke.tpl";

    ctemplate::TemplateDictionary _invoke(tpl_key);
    _invoke.SetValue("class", ::get_config().m_class);
    _invoke.SetValue("variant", variant);
    _invoke.SetIntValue("layer", layer);
    _invoke.SetIntValue("index", index);

    if (bra.size() > 1)
    {
        auto _invoke_multi = _invoke.AddSectionDictionary("invoke_bg_1");
        for (auto &_bra : bra)
        {
            auto labels = _invoke_multi->AddSectionDictionary("labels");
            // labels->SetIntValue("next_layer", _bra.m_layer);
            labels->SetIntValue("next_index", _bra.m_index);
            if (_bra.empty())
            {
                auto labels_eq_0 = _invoke_multi->AddSectionDictionary("labels_eq_0");
                labels_eq_0->SetIntValue("next_layer", _bra.m_layer);
                labels_eq_0->SetIntValue("next_index", _bra.m_index);
            }
            else
            {
                auto labels_bg_0 = _invoke_multi->AddSectionDictionary("labels_bg_0");
                labels_bg_0->SetIntValue("next_layer", _bra.m_layer);
                labels_bg_0->SetIntValue("next_index", _bra.m_index);
            }
        }
    }
    else if (bra.size() == 1)
    {
        auto _invoke_one = _invoke.AddSectionDictionary("invoke_eq_1");
        auto &child = bra[0];
        _invoke_one->SetIntValue("next_layer", child.m_layer);
        _invoke_one->SetIntValue("next_index", child.m_index);
    }
    std::string _output;
    expand(tpl_key, _invoke, _output);
    m_output_source.emplace_back(std::move(_output));

    return 0;
}

int format_tpl::to_invoke_field(const branch_info &bra)
{

    auto tpl_key = "invoke_field.tpl";

    for (auto &_bra : bra.m_variants)
    {

        ctemplate::TemplateDictionary _invoke_field(tpl_key);
        _invoke_field.SetValue("class", ::get_config().m_class);
        _invoke_field.SetValue("variant", _bra.second->m_raw_variant);
        _invoke_field.SetValue("__field", __field(_bra.second->m_field));

        auto has_argv = _invoke_field.AddSectionDictionary("has_argv");

        auto _size = _bra.second->m_input.size();
        has_argv->SetIntValue("argc", _size + (_bra.second->m_output.size() != 0));
        has_argv->SetValue("variant", _bra.second->m_raw_variant);
        has_argv->SetValue("__field", __field(_bra.second->m_field));

        if (_bra.second->m_output.size() > 0)
        {
            if (_bra.second->m_output.back() == '&')
            {
                auto ret_ref = has_argv->AddSectionDictionary("ret_ref");
                ret_ref->SetValue("compatible_output", compatible(_bra.second->m_output));
            }
            else
            {
                auto ret = has_argv->AddSectionDictionary("ret");
                ret->SetValue("compatible_output", compatible(_bra.second->m_output));
            }
        }
        int index = 0;
        for (auto &_input : _bra.second->m_input)
        {
            if (_input.back() == '&')
            {
                auto argv = has_argv->AddSectionDictionary("argv_ref");
                argv->SetValue("input", _input);
                argv->SetValue("compatible_input", compatible(_input));
                argv->SetIntValue("index", index++);
                if (index != _size)
                {
                    argv->SetValue("comma", ", ");
                }
            }
            else
            {
                auto argv = has_argv->AddSectionDictionary("argv");
                argv->SetValue("input", _input);
                argv->SetValue("compatible_input", compatible(_input));
                argv->SetIntValue("index", index++);
                if (index != _size)
                {
                    argv->SetValue("comma", ", ");
                }
            }
        }

        std::string _output;
        expand(tpl_key, _invoke_field, _output);
        m_output_source.emplace_back(std::move(_output));
    }

    return 0;
}

int format_tpl::to_invoke_layer(const std::string &variant, const branch_map &bra)
{

    auto tpl_key = "invoke_layer.tpl";
    ctemplate::TemplateDictionary _invoke(tpl_key);
    _invoke.SetValue("class", ::get_config().m_class);
    _invoke.SetValue("variant", variant);
    _invoke.SetIntValue("layer", bra.m_layer);
    _invoke.SetIntValue("index", bra.m_index);

    if (!bra.empty())
    {
        for (auto &_bra : bra)
        {
            auto block = _invoke.AddSectionDictionary("block");
            char buf[64];
            to_hex(_bra.first, buf, sizeof(buf));
            block->SetValue("value", buf);
            to_comment(_bra.first, buf, sizeof(buf));
            block->SetValue("comment", buf);

            if (_bra.second.m_branch_child.empty())
            {
                to_invoke_field(_bra.second);

                auto info = _bra.second.first_variant();
                auto complete = block->AddSectionDictionary("complete");
                complete->SetValue("variant", info->m_raw_variant);

                if (__has_flag(info->m_flags, flag_argument))
                {
                    complete->SetValue("__field", __field(info->m_field));
                }
            }
            else
            {

                for (auto &child : _bra.second.m_branch_child)
                {
                    to_invoke_layer(variant, child);
                }

                if (_bra.second.m_branch_child.size() > 1)
                {
                    auto incomplete_bg_1 = block->AddSectionDictionary("incomplete_bg_1");
                    for (auto &child : _bra.second.m_branch_child)
                    {
                        auto labels = incomplete_bg_1->AddSectionDictionary("labels");
                        labels->SetIntValue("next_layer", child.m_layer);
                        labels->SetIntValue("next_index", child.m_index);
                    }
                }
                else if (_bra.second.m_branch_child.size() == 1)
                {
                    auto incomplete_eq_1 = block->AddSectionDictionary("incomplete_eq_1");
                    incomplete_eq_1->SetIntValue("next_layer", _bra.second.m_branch_child[0].m_layer);
                    incomplete_eq_1->SetIntValue("next_index", _bra.second.m_branch_child[0].m_index);
                }
            }
        }
    }

    std::string _output;
    expand(tpl_key, _invoke, _output);
    m_output_source.emplace_back(std::move(_output));
    return 0;
}
int format_tpl::to_rfl(analyzer &ana, std::map<std::string, analyzer> &ana_func)
{
    auto bra = branch_builder(0, ana);

    to_header(bra, ana);

    to_meta(ana, ana_func);

    to_func(0, 0, bra);

    for (auto &_func : ana_func)
    {
        auto bra_func = branch_builder(0, _func.second);
        to_invoke(_func.first, bra_func);
    }

    to_get_meta(bra, ana);

    return 0;
}

int format_tpl::to_file(const std::string &header, const std::string &source)
{

    write_file(header, m_output_header);

    write_file(source, m_output_source);
    return 0;
}

int format_tpl::to_rfl()
{
    auto &conf = get_config();

    auto tpl_key = "rfl.tpl";
    ctemplate::TemplateDictionary _dict(tpl_key);

    _dict.SetValue("license", tpl::license());
    for (auto &it : conf.generated)
    {
        auto header = _dict.AddSectionDictionary("indices");
        header->SetValue("header", it);
    }

    std::string _output;
    expand(tpl_key, _dict, _output);

    std::string path = conf.tmp_dir + "/rfl.h";
    write_file(path, _output);
    return 0;
}
int format_tpl::to_base_types()
{
    auto &conf = get_config();

    auto tpl_key = "base_types.tpl";
    ctemplate::TemplateDictionary _dict(tpl_key);

    _dict.SetValue("license", tpl::license());
    for (auto &it : conf.base_types)
    {
        auto base_types = _dict.AddSectionDictionary("base_types");
        base_types->SetValue("class", it);
        base_types->SetValue("raw_class", remove_duplicate_const(it));
    }

    static std::set<std::string_view> all_stl = {
        "std::vector",
        "std::list",
        "std::map",
        "std::unordered_map",
        "std::deque",
        "std::array",
    };
    for (auto &it : conf.base_types)
    {
        auto pos = it.find("<");
        if (pos == std::string_view::npos)
        {
            continue;
        }
        std::string_view key = it.substr(0, pos);
        if (all_stl.find(key) == all_stl.end())
        {
            continue;
        }
        auto base_types = _dict.AddSectionDictionary("base_stl");
        base_types->SetValue("class", it);
        base_types->SetValue("raw_class", remove_duplicate_const(it));
    }

    std::string _output;
    expand(tpl_key, _dict, _output);

    std::string path = conf.tmp_dir + "/base_types.h";
    write_file(path, _output);

    return 0;
}
int format_tpl::to_base_types_source()
{
    auto &conf = get_config();

    auto tpl_key = "base_types_source.tpl";
    ctemplate::TemplateDictionary _dict(tpl_key);

    _dict.SetValue("license", tpl::license());
    for (auto &it : conf.base_types)
    {
        auto base_types = _dict.AddSectionDictionary("base_types");
        base_types->SetValue("class", it);
        base_types->SetValue("raw_class", remove_duplicate_const(it));
    }

    std::string _output;
    expand(tpl_key, _dict, _output);

    std::string path = conf.tmp_dir + "/base_types.cpp";
    write_file(path, _output);

    return 0;
}

bool format_tpl::is_invoked(const std::string &variant)
{
    return m_invoke_filter.find(variant) != m_invoke_filter.end();
}