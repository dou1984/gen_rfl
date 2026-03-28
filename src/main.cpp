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

#include <vector>
#include <string>
#include <iostream>
#include <gflags/gflags.h>
#include <unistd.h>
#include "config.h"
#include "gen_rfl.h"
#include "format_tpl.h"
#include "sys.h"
#include "filter.h"
#include "travel_src.h"

using namespace gflags;
using namespace reflect;

DEFINE_string(config, "gen_rfl.yaml", "config file");

auto &conf = get_config();

void set_config()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        conf.cwd = cwd;
        if (conf.cwd.back() != '/')
        {
            conf.cwd += '/';
        }
    }
    if (!IsCurDir(conf.rfl_dir))
    {
        MkDir(conf.rfl_dir);

        char real_src_dir[PATH_MAX];
        auto rfl_dir = conf.rfl_dir + (conf.rfl_dir.back() == '/' ? ".." : "/..");
        if (realpath(rfl_dir.c_str(), real_src_dir) != NULL)
        {
            conf.real_source_dir = real_src_dir;
            conf.real_source_dir += "/";
            std::cout << "real_src_dir:" << conf.real_source_dir << std::endl;
        }
    }
    else
    {
        char real_src_dir[PATH_MAX];
        if (conf.rfl_dir == "")
        {
            conf.rfl_dir = ".";
        }
        if (realpath(conf.rfl_dir.c_str(), real_src_dir) != NULL)
        {
            conf.real_source_dir = real_src_dir;
            std::cout << "real_src_dir:" << conf.real_source_dir << std::endl;
        }
    }
}
int main(int argc, char *argv[])
{

    ParseCommandLineFlags(&argc, &argv, true);

    auto config_json = FLAGS_config;
    if (!IsExist(config_json))
    {
        write_default_to_yaml(config_json);
    }
    read_config_from_yaml(config_json);

    set_config();

    auto filter = get_filter();
    std::vector<std::string> sources;
    std::cout << "Traversing directory: " << conf.src_dir << std::endl;
    TraverseDir(conf.src_dir,
                [&](const std::string &path)
                {
                    std::cout << "Checking file: " << path << std::endl;
                    if (filter(path))
                    {
                        std::cout << "Filtering out: " << path << std::endl;
                        return;
                    }

                    std::cout << "find source file:" << path << std::endl;
                    sources.push_back(path);
                });

    // 使用 tree-sitter 解析源码
    for (const auto &source : sources)
    {
        std::cout << "Processing with tree-sitter: " << source << std::endl;
        travel_src(source);
    }
    
    // 处理命令行参数中指定的文件
    for (int i = 1; i < argc; i++) {
        std::string file = argv[i];
        if (file != "--config") {
            // 跳过 --config 选项及其值
            if (i > 1 && argv[i-1] == std::string("--config")) {
                continue;
            }
            std::cout << "Processing command line file: " << file << std::endl;
            travel_src(file);
        }
    }

    format_tpl fmt;

    fmt.to_rfl();
    fmt.to_base_types();
    fmt.to_base_types_source();

    return 0;
}
