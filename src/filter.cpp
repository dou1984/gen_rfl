#include <regex>
#include <iostream>
#include "filter.h"
#include "config.h"

namespace reflect
{
    filter get_filter()
    {
        auto &conf = get_config();
        std::regex tmp_regex(conf.tmp_dir);
        std::regex base_regex(conf.regex);
        std::regex cmake_regex("^.*/CMakeFiles/\\d+\\.\\d+.\\d+/.+/CMake.+$");
        return [=](const std::string &file) -> bool
        {
            if (std::regex_search(file, tmp_regex))
            {
                return true;
            }

            if (!std::regex_search(file, base_regex))
            {
                return true;
            }
            if (std::regex_search(file, cmake_regex))
            {
                return true;
            }
            std::cout << "get_filter: " << file << std::endl;
            return false;
        };
    }
    filter get_rfl_filter()
    {
        auto &conf = get_config();
        std::regex tmp_regex(conf.tmp_dir);
        return [=](const std::string &file) -> bool
        {
            if (std::regex_search(file, tmp_regex))
            {
                return true;
            }
            std::cout << "get_rfl_filter: " << file << std::endl;
            return false;
        };
    }
}