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

using namespace gflags;
DEFINE_string(tmp_dir, "gen_rfl", "tmp directory");
DEFINE_string(src, "./", "source directory");
DEFINE_string(libs, "libs", "output libs directory");
DEFINE_string(include, "include", "output include directory");
DEFINE_string(regex, ".+\\.cpp$", "regex");

auto &conf = get_config();

void set_config()
{
    conf.tmp_dir = FLAGS_tmp_dir;
    conf.src_dir = FLAGS_src;
    conf.libs_dir = FLAGS_libs;
    conf.include_dir = FLAGS_include;
    conf.regex = FLAGS_regex;

    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    conf.cwd = cwd;
    if (conf.cwd.back() != '/')
    {
        conf.cwd += '/';
    }
    MkDir(conf.tmp_dir);

    char real_tmp_dir[PATH_MAX];
    auto tmp_dir = conf.tmp_dir + (conf.tmp_dir.back() == '/' ? ".." : "/..");
    realpath(tmp_dir.c_str(), real_tmp_dir);
    conf.real_tmp_dir_loc = real_tmp_dir;
    conf.real_tmp_dir_loc += "/";
    std::cout << "real_tmp_dir:" << conf.real_tmp_dir_loc << std::endl;
}
int main(int argc, char *argv[])
{

    ParseCommandLineFlags(&argc, &argv, true);
    set_config();

    std::vector<std::string> Args = {
        "--std=c++20",
        "-I/usr/include",
        "-I/usr/include/c++/12",
        "-I/usr/include/x86_64-linux-gnu/c++/12",
        "-I/usr/lib/llvm-15/include",
        "-fparse-all-comments",
        "-D__clang__",
    };

    auto filter = reflect::get_filter();
    std::vector<std::string> sources;
    TraverseDir(conf.src_dir,
                [&](const std::string &path)
                {
                    if (filter(path))
                    {
                        return;
                    }

                    std::cout << "find source file:" << path << std::endl;
                    sources.push_back(path);
                });

    // 运行 ClangTool
    clang::tooling::FixedCompilationDatabase Compilations("./", Args);

    clang::tooling::ClangTool Tool(Compilations, sources);

    Tool.run(clang::tooling::newFrontendActionFactory<GetRflFrontendAction>().get());

    format_tpl fmt;
    // fmt.to_makefile();
    fmt.to_rfl();
    fmt.to_base_types();
    fmt.to_base_types_source();

    return 0;
}
