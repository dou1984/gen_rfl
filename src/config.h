#pragma once
#include <string>
#include <map>
#include <set>
#include <chrono>

struct Data
{
    std::map<std::string, std::chrono::system_clock::time_point> generate_header;
    std::set<std::string> generated;
};
struct Conf : Data
{
    std::string include_dir;
    std::string libs_dir;
    std::string src_dir;
    std::string tmp_dir;
    std::string real_tmp_dir_loc;
    std::string cwd;
    std::string regex;
    // std::string base_regex;
    std::string filter;
};

Conf &get_config();