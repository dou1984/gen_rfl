#include "format_tpl.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "reflect.h"
#include "config.h"
#include "tpl/tpl.h"
#include "sys.h"

using namespace reflect;

int to_hex(uint64_t value, char *buf, int size)
{
    return snprintf(buf, size, "0x%lx", value);
}
std::string remove_duplicate_const(const std::string &type)
{
    // return (type.find("const ") == 0) ? type.substr(6) : type;
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
    if (!ctemplate::StringToTemplateCache("makefile.tpl", tpl::makefile(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error makefile.tpl" << std::endl;
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
int format_tpl::to_header(branch &sel, analyzer &ana)
{
    auto tpl_key = "header.tpl";
    ctemplate::TemplateDictionary _header(tpl_key);
    _header.SetValue("class", analyzer::get_config().m_class);
    _header.SetValue("raw_class", analyzer::get_config().m_raw_class);
    _header.SetValue("string", "branch_string");
    _header.SetValue("header", GetRelativePath(analyzer::get_config().m_relative_file, "") + "/base_types.h");

    if (!analyzer::get_config().m_namespace.empty())
    {
        auto _namespace = _header.AddSectionDictionary("namesp");
        _namespace->SetValue("namespace", analyzer::get_config().m_namespace);
    }
    expand(tpl_key, _header, m_output_header);
    return 0;
}
int format_tpl::to_meta(branch &sel, analyzer &ana)
{
    auto tpl_key = "meta.tpl";

    ctemplate::TemplateDictionary _meta(tpl_key);

    auto header_name = GetRelativePath(analyzer::get_config().m_file, ::get_config().real_tmp_dir_loc) + "/../" + analyzer::get_config().m_relative_file;
    std::cout << "file: " << analyzer::get_config().m_file << std::endl;
    std::cout << "real_tmp_dir: " << ::get_config().real_tmp_dir_loc << std::endl;
    std::cout << "header_name: " << header_name << std::endl;
    _meta.SetValue("header", header_name);
    _meta.SetValue("string", "branch_string");

    if (!analyzer::get_config().m_namespace.empty())
    {
        auto _namespace = _meta.AddSectionDictionary("namesp");
        _namespace->SetValue("namespace", analyzer::get_config().m_namespace);
    }

    auto _field = 0;
    for (auto &it : ana.get_data())
    {
        auto &field = it.second;
        if ((field.m_flags & __flags(flag_function)) != 0)
        {
            auto func = _meta.AddSectionDictionary("is_invoke");
            func->SetValue("variant", field.m_variant);

            for (auto &argu_list : field.m_params)
            {
                if (argu_list.m_input.size() > 0)
                {
                    uint64_t i = 0;
                    auto has_argv = func->AddSectionDictionary("has_argv");
                    has_argv->SetIntValue("argc", argu_list.m_input.size());
                    for (auto &input : argu_list.m_input)
                    {
                        auto argv = has_argv->AddSectionDictionary("argv");
                        argv->SetIntValue("index", i++);
                        argv->SetValue("input", input);
                        if (i < argu_list.m_input.size())
                        {
                            argv->SetValue("comma", ", ");
                        }
                    }
                }
                else
                {
                    auto no_argv = func->AddSectionDictionary("no_argv");
                    no_argv->SetIntValue("argc", argu_list.m_input.size());
                }
            }
        }
        auto dict = _meta.AddSectionDictionary("fields");
        dict->SetValue("variant", field.m_variant);
        dict->SetValue("type", field.m_type);
        dict->SetValue("raw_type", field.m_raw_type);
        char buf[64];
        to_hex(field.m_flags, buf, sizeof(buf));
        dict->SetValue("flags", buf);

        if ((field.m_flags & __flags(flag_struct, flag_class)) != 0)
        {
            dict->AddSectionDictionary("is_derived");
        }
        else if ((field.m_flags & __flags(flag_function)) != 0)
        {
            dict->AddSectionDictionary("is_func");
        }
        else if ((field.m_flags & __flags(flag_static)) != 0)
        {
            dict->AddSectionDictionary("is_static");
        }
        else
        {
            dict->AddSectionDictionary("is_field");
        }
        dict->SetIntValue("field", _field);
    }
    _meta.SetValue("class", analyzer::get_config().m_class);

    std::string _output;
    expand(tpl_key, _meta, _output);
    m_output_source.emplace_back(std::move(_output));

    return 0;
}

int format_tpl::to_get_meta(branch &bra, analyzer &ana)
{
    auto tpl_key = "get_meta.tpl";
    ctemplate::TemplateDictionary _get_meta(tpl_key);
    _get_meta.SetValue("class", analyzer::get_config().m_class);
    _get_meta.SetValue("layer", std::to_string(0));

    auto _field = 0;
    for (auto &v : bra)
    {
        auto _labels = _get_meta.AddSectionDictionary("labels");
        _labels->SetIntValue("index", v.m_index);
    }

    if (!analyzer::get_config().m_namespace.empty())
    {
        auto _namespace = _get_meta.AddSectionDictionary("namesp");
        _namespace->SetValue("namespace", analyzer::get_config().m_namespace);
    }
    std::string _output;
    expand(tpl_key, _get_meta, _output);
    m_output_source.emplace_back(std::move(_output));
    return 0;
}
int format_tpl::to_func(uint32_t layer, uint32_t index, uint32_t position, branch &bra)
{
    auto tpl_key = "func.tpl";

    for (auto i = 0; i < bra.size(); ++i)
    {
        auto &_bra = bra[i];
        std::list<std::string> _output_leaf;
        ctemplate::TemplateDictionary _func(tpl_key);
        if (_bra.empty())
        {
            _func.SetIntValue("layer", _bra.m_layer);
            _func.SetIntValue("index", _bra.m_index);

            _func.SetValue("class", analyzer::get_config().m_class);
            _func.SetValue("string", "branch_string");
        }
        else
        {
            for (auto &info : _bra)
            {

                _func.SetIntValue("layer", info.second.m_layer);
                _func.SetIntValue("index", info.second.m_index);
                _func.SetValue("class", analyzer::get_config().m_class);
                _func.SetValue("string", "branch_string");

                std::set<uint64_t> _value;
                for (auto &details : info.second.m_variants)
                {
                    auto _detail = details.second;
                    if (_value.find(_detail->m_value) != _value.end())
                    {
                        continue;
                    }
                    _value.insert(_detail->m_value);
                    uint32_t next_position = _value.size();
                    to_func(layer + 1, info.second.m_index, next_position, info.second.m_branch_child);

                    auto block = _func.AddSectionDictionary("block");
                    char buf[64];
                    to_hex(_detail->m_value, buf, sizeof(buf));
                    block->SetValue("value", buf);
                    if (details.first.size() > sizeof(uint64_t))
                    {
                        _func.SetIntValue("next_layer", info.second.m_layer + 1);
                        _func.SetIntValue("field", _detail->m_field);
                        _func.SetIntValue("position", next_position);
                        if (info.second.m_branch_child.size() > 1)
                        {
                            auto incomplete = block->AddSectionDictionary("incomplete");
                            incomplete->SetIntValue("next_count", info.second.m_branch_child.size());
                            for (auto &child : info.second.m_branch_child)
                            {
                                auto labels = incomplete->AddSectionDictionary("labels");
                                labels->SetIntValue("next_index", child.m_index);
                            }
                        }
                        else if (info.second.m_branch_child.size() == 1)
                        {
                            auto incomplete_one = block->AddSectionDictionary("incomplete_one");
                            incomplete_one->SetIntValue("next_index", info.second.m_branch_child[0].m_index);
                        }
                    }
                    else
                    {
                        auto complete = block->AddSectionDictionary("complete");
                        complete->SetValue("variant", _detail->m_raw_variant);
                        complete->SetIntValue("field", _detail->m_field);
                    }
                }
            }
        }
        m_output_source.splice(m_output_source.end(), _output_leaf);
        std::string _output;
        expand(tpl_key, _func, _output);
        m_output_source.emplace_back(std::move(_output));
    }

    return 0;
}
int format_tpl::to_rfl(branch &sel, analyzer &ana)
{

    to_header(sel, ana);

    to_meta(sel, ana);

    to_func(0, 0, 0, sel);

    to_get_meta(sel, ana);

    return 0;
}

int format_tpl::to_file(analyzer &ana, const std::string &header, const std::string &source)
{

    write_file(header, m_output_header);

    write_file(source, m_output_source);
    return 0;
}

int format_tpl::to_makefile()
{
    auto &conf = get_config();
    auto tpl_key = "makefile.tpl";

    ctemplate::TemplateDictionary _dict(tpl_key);
    _dict.SetValue("SRC", "../" + conf.src_dir);

    expand(tpl_key, _dict, m_output_makefile);

    std::ostringstream oss;
    oss << conf.tmp_dir << "/" << "Makefile";
    write_file(oss.str(), m_output_makefile);
    return 0;
}
int format_tpl::to_rfl()
{
    auto &conf = get_config();

    auto tpl_key = "rfl.tpl";
    ctemplate::TemplateDictionary _dict(tpl_key);

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