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