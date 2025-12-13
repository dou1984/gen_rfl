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
#include <regex>
#include <cassert>
#include <iostream>
#include "gen_rfl.h"
#include "config.h"
#include "sys.h"

namespace reflect
{
    int generate_file_name(rfl_config &cfg, std::string &__header)
    {
        auto &conf = ::reflect::get_config();

        auto fname = conf.m_file;
        auto _class = conf.m_class;

        assert(fname.size() > 0);
        assert(fname.back() != '/');
        if (fname.find(conf.cwd) == 0)
        {
            fname = fname.substr(conf.cwd.size());
        }
        conf.m_relative_file = fname;

        std::regex suffix(R"(\.(h|hpp|c|cc|cxx|c++|cpp)$)");
        fname = std::regex_replace(fname, suffix, "_rfl");

        auto path = conf.rfl_dir + "/" + fname;
        MkDir(path);

        cfg.header = path + "/" + _class + ".h";
        cfg.header_hpp = path + "/" + _class + ".hpp";
        cfg.source = path + "/" + _class + ".cpp";
        __header = fname + "/" + _class + ".h";

        return 0;
    }
    bool is_generated(rfl_config &cfg)
    {
        std::string __header;
        auto r = generate_file_name(cfg, __header);
        if (r != 0)
        {
            std::cerr << "generate_file_name error" << std::endl;
            return false;
        }
        auto &conf = ::reflect::get_config();
        conf.generated.emplace(__header);

        auto f = [&](auto header)
        {
            auto key_file = conf.m_file + ":" + header;
            auto it = conf.generate_header.find(key_file);
            if (it == conf.generate_header.end())
            {
                auto modified_time = GetFileModified(conf.m_file);
                conf.generate_header.emplace(key_file, modified_time);
                return false;
            }
            auto modified_time = GetFileModified(conf.m_file);
            if (modified_time > it->second)
            {
                std::cerr << "file " << conf.m_file << "header " << header << std::endl;
                conf.generate_header.emplace(key_file, modified_time);
                return false;
            }
            return true;
        };
        if (!f(cfg.header))
        {
            return false;
        }
        if (!f(cfg.header_hpp))
        {
            return false;
        }

        return true;
    }
}