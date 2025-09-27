#include <cstdint>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include "config.h"
#include "analyzer.h"
#include "sys.h"
#include "branch_string.h"

analyzer::config_t analyzer::m_config = {};

analyzer::analyzer()
{
}

void analyzer::push_back_view(const std::string &variant, const info_t &detail)
{

    branch_string b(variant);
    assert(b);
    auto field = m_data.size();
    info_t info;
    info.m_variant = variant;
    info.m_value = b();
    info.m_raw_variant = detail.m_raw_variant;
    info.m_type = detail.m_type;
    info.m_raw_type = detail.m_raw_type;
    info.m_field = field;
    info.m_flags = detail.m_flags;
    info.m_params = detail.m_params;

    m_data.emplace(variant, std::move(info));
}
void analyzer::copy_view(const std::string &variant, const info_t &detail)
{

    branch_string b(variant);
    assert(b);
    info_t info;
    info.m_variant = variant;
    info.m_value = b();
    info.m_raw_variant = detail.m_raw_variant;
    info.m_type = detail.m_type;
    info.m_raw_type = detail.m_raw_type;
    info.m_field = detail.m_field;
    info.m_flags = detail.m_flags;

    m_data.emplace(variant, std::move(info));
}

bool analyzer::get_prefect_index(int index) const
{
    std::map<uint64_t, std::set<uint64_t>> _prefect;
    for (auto &v : m_data)
    {
        auto idx = v.second.m_value % index;
        _prefect[idx].emplace(v.second.m_value);
        if (_prefect[idx].size() > 2)
        {
            return false;
        }
    }
    return true;
}
uint64_t analyzer::calc_perfect_index() const
{
    std::set<uint64_t> m;
    for (auto &v : m_data)
    {
        m.emplace(v.second.m_value);
    }
    auto index = (m.size() / 3) | 1;

    while (!get_prefect_index(index))
    {
        index += 2;
    }
    return index;
}

int analyzer::generate_file_name(std::string &header, std::string &source, std::string &_header)
{
    auto &conf = ::get_config();

    auto fname = get_config().m_file;
    auto _class = get_config().m_class;

    assert(fname.size() > 0);
    assert(fname.back() != '/');
    if (fname.find(conf.cwd) == 0)
    {
        fname = fname.substr(conf.cwd.size());
    }
    // std::cout << "generate_file_name from " << fname << std::endl;
    get_config().m_relative_file = fname;

    auto path = conf.tmp_dir + "/" + fname;
    MkDir(path);

    header = path + "/" + _class + ".h";
    source = path + "/" + _class + ".cpp";
    _header = fname + "/" + _class + ".h";

    return 0;
}
bool analyzer::is_generated(std::string &header, std::string &source)
{
    std::string __header;
    auto r = generate_file_name(header, source, __header);
    if (r != 0)
    {
        std::cerr << "generate_file_name error" << std::endl;
        return false;
    }

    auto &conf = ::get_config();
    conf.generated.emplace(__header);

    auto key_file = m_config.m_file + ":" + header;
    auto it = conf.generate_header.find(key_file);
    if (it == conf.generate_header.end())
    {
        auto modified_time = GetFileModified(m_config.m_file);
        conf.generate_header.emplace(key_file, modified_time);
        return false;
    }
    auto modified_time = GetFileModified(m_config.m_file);
    if (modified_time > it->second)
    {
        std::cerr << "file " << m_config.m_file << "header " << header << std::endl;
        conf.generate_header.emplace(key_file, modified_time);
        return false;
    }
    return true;
}
