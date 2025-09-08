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
    if (!ctemplate::StringToTemplateCache("func_root.tpl", tpl::func_root(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error func_root.tpl" << std::endl;
        return -1;
    }
    if (!ctemplate::StringToTemplateCache("func_leaf.tpl", tpl::func_leaf(), ctemplate::DO_NOT_STRIP))
    {
        std::cerr << "template error func_leaf.tpl" << std::endl;
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
        std::cerr << "template error" << std::endl;
        return -1;
    }

    if (!_tpl->Expand(&output, &dict))
    {
        std::cerr << "template error" << std::endl;
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
    _header.SetValue("header", SplitFile(analyzer::get_config().m_file));
    _header.SetValue("string", "branch_string");

    expand(tpl_key, _header, m_output_header);
    return 0;
}
int format_tpl::to_meta(branch &sel, analyzer &ana)
{
    auto tpl_key = "meta.tpl";

    ctemplate::TemplateDictionary _meta(tpl_key);

    auto header_name = GetRelativePath(analyzer::get_config().m_file, ::get_config().real_tmp_dir_loc) + "/../" + SplitFile(analyzer::get_config().m_file);
    std::cout << analyzer::get_config().m_file << " real_tmp_dir:" << ::get_config().real_tmp_dir_loc << std::endl;
    std::cout << "header_name:" << header_name << std::endl;
    _meta.SetValue("header", header_name);
    _meta.SetValue("string", "branch_string");

    auto _field = 0;
    for (auto &field : ana.get())
    {
        auto dict = _meta.AddSectionDictionary("fields");
        dict->SetValue("variant", field.m_variant);
        dict->SetValue("type", field.m_type);
        dict->SetValue("raw_type", field.m_raw_type);
        dict->SetIntValue("flags", field.m_flags);

        if ((field.m_flags & __flags(flag_struct, flag_class)) == 0)
        {
            dict->AddSectionDictionary("is_field");
        }
        else
        {
            dict->AddSectionDictionary("is_derived");
        }
        dict->SetIntValue("field", _field);
    }
    _meta.SetValue("class", analyzer::get_config().m_class);

    std::string _output;
    expand(tpl_key, _meta, _output);
    m_output_source.emplace_back(std::move(_output));

    return 0;
}

int format_tpl::to_get_meta(branch &sel, analyzer &ana)
{
    auto tpl_key = "get_meta.tpl";
    ctemplate::TemplateDictionary _get_meta(tpl_key);
    _get_meta.SetValue("class", analyzer::get_config().m_class);
    _get_meta.SetValue("layer", std::to_string(0));

    std::string _output;
    expand(tpl_key, _get_meta, _output);
    m_output_source.emplace_back(std::move(_output));
    return 0;
}
int format_tpl::to_func_root(uint32_t layer, uint32_t position, branch &bra, analyzer &ana)
{

    if (layer == 0)
    {
        auto tpl_key = "func_root.tpl";
        ctemplate::TemplateDictionary _func(tpl_key);
        _func.SetValue("class", analyzer::get_config().m_class);
        _func.SetIntValue("layer", layer);
        _func.SetIntValue("position", position);

        for (auto &v : bra)
        {
            ctemplate::TemplateDictionary *dict = _func.AddSectionDictionary("indices");
            dict->SetIntValue("layer", layer);
            dict->SetIntValue("index", v.m_index);
        }

        std::string _output;
        expand(tpl_key, _func, _output);
        m_output_source.emplace_back(std::move(_output));
    }

    return 0;
}
std::string format_tpl::to_func_leaf(uint32_t layer, uint32_t index, uint32_t position, branch_info &info)
{
    std::string _output;
    if (layer == 0)
    {
        return _output;
    }
    if (info.m_variants.empty())
    {
        return _output;
    }
    if (info.m_branch_child.empty())
    {
        return _output;
    }
    auto tpl_key = "func_leaf.tpl";
    ctemplate::TemplateDictionary _func(tpl_key);
    auto leaf = _func.AddSectionDictionary("leaf");
    _func.SetValue("class", analyzer::get_config().m_class);
    _func.SetIntValue("layer", layer);
    _func.SetIntValue("index", index);
    _func.SetIntValue("position", position);

    for (auto &v : info.m_branch_child)
    {
        ctemplate::TemplateDictionary *dict = _func.AddSectionDictionary("indices");
        dict->SetIntValue("layer", v.m_layer);
        dict->SetIntValue("index", v.m_index);
    }

    expand(tpl_key, _func, _output);
    return _output;
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
            _func.SetIntValue("iindex", index);
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
                    if (_value.find(details.second.m_value) != _value.end())
                    {
                        continue;
                    }
                    _value.insert(details.second.m_value);
                    uint32_t next_position = _value.size();
                    to_func(layer + 1, info.second.m_index, next_position, info.second.m_branch_child);

                    _output_leaf.emplace_back(to_func_leaf(layer + 1, info.second.m_index, next_position, info.second));

                    auto block = _func.AddSectionDictionary("block");
                    char buf[64];
                    to_hex(details.second.m_value, buf, sizeof(buf));
                    block->SetValue("value", buf);
                    if (details.first.size() > sizeof(uint64_t))
                    {
                        auto incomplete = block->AddSectionDictionary("incomplete");
                        _func.SetIntValue("next_layer", info.second.m_layer + 1);
                        _func.SetIntValue("field", details.second.m_field);
                        _func.SetIntValue("position", next_position);
                    }
                    else
                    {
                        auto complete = block->AddSectionDictionary("complete");
                        complete->SetValue("variant", details.second.m_raw_variant);
                        complete->SetIntValue("field", details.second.m_field);
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

    to_func_root(0, 0, sel, ana);

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
int format_tpl::to_rfl_h()
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

    std::ostringstream oss;
    oss << conf.tmp_dir << "/rfl.h";
    write_file(oss.str(), _output);
    return 0;
}