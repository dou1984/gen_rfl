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

    m_data.emplace_back(std::move(info));
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

    m_data.emplace_back(std::move(info));
}
uint64_t analyzer::calc_perfect_index() const
{
    std::set<uint64_t> m;
    for (auto i = 0; i < m_data.size(); i++)
    {
        m.emplace(m_data[i].m_value);
    }
    return m.size() | 1;
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
    std::cout << "generate_file_name from" << fname << std::endl;

    // auto pos = fname.find_last_of(".");
    // if (pos != std::string::npos)
    // {
    //     std::ostringstream oss;
    //     oss << conf.tmp_dir << "/" << fname.substr(0, pos);
    //     auto path = oss.str();
    //     MkDir(path);
    //     {
    //         std::ostringstream oss;
    //         oss << path << "/" << _class << ".h";
    //         header = oss.str();
    //     }
    //     {
    //         std::ostringstream oss;
    //         oss << path << "/" << _class << ".cpp";
    //         source = oss.str();
    //     }
    //     {
    //         std::ostringstream oss;
    //         oss << fname.substr(0, pos) << "/" << _class << ".h";
    //         _header = oss.str();
    //     }
    // }
    // else
    {
        std::ostringstream oss;
        oss << conf.tmp_dir << "/" << fname;
        auto path = oss.str();
        MkDir(path);
        {
            std::ostringstream oss;
            oss << path << "/" << _class << ".h";
            header = oss.str();
        }
        {
            std::ostringstream oss;
            oss << path << "/" << _class << ".cpp";
            source = oss.str();
        }
        {
            std::ostringstream oss;
            oss << fname << "/" << _class << ".h";
            _header = oss.str();
        }
    }
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
    conf.generated.emplace(__header);
    return true;
}
