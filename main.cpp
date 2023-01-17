#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <gflags/gflags.h>

#define OUT(...)                             \
    {                                        \
        char t[4000];                        \
        snprintf(t, sizeof(t), __VA_ARGS__); \
        outfile << t;                        \
    }

using splice = std::vector<std::string>;
using namespace gflags;

std::ofstream outfile;
DEFINE_string(header, "", "include header file");
DEFINE_string(class, "", "parse class");
DEFINE_string(member, "", "class member list");
DEFINE_string(out, "", "output direction");
DEFINE_string(namespace, "", "namespace");

auto split(const std::string &s, char delim = ',')
{
    splice r;
    size_t pos = 0;
    size_t lastpos = 0;
    while (true)
    {
        pos = s.find_first_not_of(delim, lastpos);
        if (pos == std::string::npos)
        {
            break;
        }
        lastpos = s.find(delim, pos);
        if (lastpos == std::string::npos)
        {
            r.emplace_back(s.substr(pos));
            break;
        }
        r.emplace_back(s.substr(pos, lastpos - pos));
    }
    return r;
}

splice split(const splice &v, size_t begin, size_t end)
{
    begin = std::max(begin, size_t(0));
    end = std::min(end, v.size());
    splice r;
    for (auto i = begin; i < end; i++)
    {
        r.emplace_back(v[i]);
    }
    return r;
}

std::string reflectctl(const std::string &cls, const splice &v)
{
    if (v.size() > 3)
    {
        size_t mid = v.size() - v.size() / 2 - 1;
        auto l = split(v, 0, mid);
        auto g = split(v, mid + 1, 1000000000);

        auto x = reflectctl(cls, l);
        auto z = reflectctl(cls, g);
        auto y = v[mid];
        OUT("ReflectX(%s,4,%s,%s,%s);\n", cls.data(), x.data(), y.data(), z.data());
        return y;
    }
    else if (v.size() == 3)
    {
        OUT("ReflectX(%s,3,%s,%s,%s);\n", cls.data(), v[0].data(), v[1].data(), v[2].data());
        return v[0];
    }
    else if (v.size() == 2)
    {
        OUT("ReflectX(%s,2,%s,%s);\n", cls.data(), v[0].data(), v[1].data());
        return v[0];
    }
    else if (v.size() == 1)
    {
        OUT("ReflectX(%s,1,%s);\n", cls.data(), v[0].data());
        return v[0];
    }
    throw("error v.size() == 0");
}

void reflectcpp(const std::string &h)
{
    OUT("#include <cstring>\n");
    OUT("#include <string>\n");
    OUT("#include <reflect.def.h>\n");
    OUT("#include \"%s.reflect.h\"\n", h.data());
    OUT("\n");
    OUT("namespace reflect {\n\n");    
    if (FLAGS_namespace != "")
    {
        OUT("using namespace %s;\n\n", FLAGS_namespace.c_str());
    }
}
void reflectbody(const std::string &cls, const splice &v)
{
    OUT("Reflect0(%s);\n", cls.data());
    auto a = reflectctl(cls, v);
    OUT("Reflect(%s,%s);\n\n", cls.data(), a.data());
}
void reflectfield(const std::string &cls, const splice &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OUT("FieldX(%s, %s);\n", cls.data(), v[i].data());
    }
    OUT("\n");
    OUT("reflectfield<%s> %s_field = {\n", cls.data(), cls.data());
    OUT("\t._type = {");
    for (auto &i : v)
    {
        OUT("field_type_%s,", i.data());
    }
    OUT("},\n");
    OUT("\t._pointer = {");
    for (auto &i : v)
    {
        OUT("field_pointer_%s,", i.data());
    }
    OUT("},\n");
    OUT("\t._member = {");
    for (auto &i : v)
    {
        OUT("field_member_%s,", i.data());
    }
    OUT("},\n");
    OUT("};\n\n");
}
void reflectfield(const std::string &cls)
{
    OUT("void* field_pointer(const %s& cls, int idx)\n{\n\treturn %s_field._pointer[idx](cls);\n}\n", cls.data(), cls.data());
    OUT("const char* field_type(const %s& cls, int idx)\n{\n\treturn %s_field._type[idx](cls);\n}\n", cls.data(), cls.data());
    OUT("const char* field_member(const %s& cls, int idx)\n{\n\treturn %s_field._member[idx](cls);\n}\n", cls.data(), cls.data());
    OUT("size_t field_max(const %s& cls)\n{\n\treturn %s_field._member.size();\n}\n", cls.data(), cls.data());
}
void reflectend()
{
    OUT("\n}\n");
}
void reflecthpp(const std::string &h)
{
    OUT("#pragma once\n");
    OUT("#include <reflect.h>\n");
    OUT("#include <%s>\n", h.data());

    OUT("\n");
    OUT("namespace reflect {\n\n");
    if (FLAGS_namespace != "")
    {
        OUT("using namespace %s;\n\n", FLAGS_namespace.c_str());
    }
}
void reflectdelclare(const std::string &cls)
{
    OUT("const char* get_type(const %s&, const char*);\n", cls.data());
    OUT("void* get_pointer(const %s&, const char*);\n", cls.data());
    OUT("info get_info(const %s&, const char*);\n", cls.data());
    OUT("int get_field(const %s&, const char*);\n", cls.data());
    OUT("template<class T>\nauto& get_value(const %s& cls, const char* argu)\n{\n\treturn *(T*)get_pointer(cls, argu);\n}\n", cls.data());
    OUT("const char* field_member(const %s&, int);\n", cls.data());
    OUT("void* field_pointer(const %s&, int);\n", cls.data());
    OUT("const char* field_type(const %s&, int);\n", cls.data());
    OUT("template<class T>\nauto& field_value(const %s& cls, int idx)\n{\n\treturn *(T*)field_pointer(cls, idx);\n}\n", cls.data());
    OUT("size_t field_max(const %s& cls);\n", cls.data());
}
int gen_hpp(const std::string &header, const std::string &cls)
{
    reflecthpp(header);
    reflectdelclare(cls);
    reflectend();
    return 0;
}
void gen_cpp_field(const std::string &cls, const splice &v)
{
    OUT("enum %s_field_idx\n{\n", cls.data());
    for (int i = 0; i < v.size(); i++)
    {
        OUT("\t%s_field_%s,\n", cls.data(), v[i].data());
    }
    OUT("};\n");
}
void gen_cpp_body(const std::string &cls, const splice &t)
{
    auto v = t;
    std::sort(v.begin(), v.end());
    reflectbody(cls, v);
    reflectfield(cls, v);
    reflectfield(cls);
}
int gen_cpp(const std::string &cls, const std::string &args)
{
    reflectcpp(cls);
    auto v = split(args);
    gen_cpp_field(cls, v);
    gen_cpp_body(cls, v);
    reflectend();
    return 0;
}

int main(int argc, char **argv)
{

    gflags::ParseCommandLineFlags(&argc, &argv, true);

    if (FLAGS_header == "" || FLAGS_class == "" || FLAGS_member == "")
    {
        return 0;
    }
    if (FLAGS_out != "")
    {
        auto r = chdir(FLAGS_out.c_str());
        if (r > 0)
        {
            exit(r);
        }
    }

    std::ofstream hpp(FLAGS_class + ".reflect.h", std::ios::out);
    outfile = std::move(hpp);

    gen_hpp(FLAGS_header, FLAGS_class);
    outfile.close();

    std::ofstream cpp(FLAGS_class + ".reflect.cpp", std::ios::out);
    outfile = std::move(cpp);
    gen_cpp(FLAGS_class, FLAGS_member);
    outfile.close();

    return 0;
}