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

#include "base_types.h"


const std::string &get_type(bool *)
{
    static const std::string _ = "bool";
    return _;
}
const std::string &get_type(char *)
{
    static const std::string _ = "char";
    return _;
}
const std::string &get_type(char * *)
{
    static const std::string _ = "char *";
    return _;
}
const std::string &get_type(const bool *)
{
    static const std::string _ = "const bool";
    return _;
}
const std::string &get_type(const char *)
{
    static const std::string _ = "const char";
    return _;
}
const std::string &get_type(const char * *)
{
    static const std::string _ = "const char *";
    return _;
}
const std::string &get_type(const double *)
{
    static const std::string _ = "const double";
    return _;
}
const std::string &get_type(const float *)
{
    static const std::string _ = "const float";
    return _;
}
const std::string &get_type(const int *)
{
    static const std::string _ = "const int";
    return _;
}
const std::string &get_type(const long *)
{
    static const std::string _ = "const long";
    return _;
}
const std::string &get_type(const long double *)
{
    static const std::string _ = "const long double";
    return _;
}
const std::string &get_type(const long long *)
{
    static const std::string _ = "const long long";
    return _;
}
const std::string &get_type(const short *)
{
    static const std::string _ = "const short";
    return _;
}
const std::string &get_type(const signed char *)
{
    static const std::string _ = "const signed char";
    return _;
}
const std::string &get_type(const std::map<int, int> *)
{
    static const std::string _ = "const std::map<int, int>";
    return _;
}
const std::string &get_type(const std::string *)
{
    static const std::string _ = "const std::string";
    return _;
}
const std::string &get_type(const std::vector<int> *)
{
    static const std::string _ = "const std::vector<int>";
    return _;
}
const std::string &get_type(const unsigned char *)
{
    static const std::string _ = "const unsigned char";
    return _;
}
const std::string &get_type(const unsigned int *)
{
    static const std::string _ = "const unsigned int";
    return _;
}
const std::string &get_type(const unsigned long *)
{
    static const std::string _ = "const unsigned long";
    return _;
}
const std::string &get_type(const unsigned long long *)
{
    static const std::string _ = "const unsigned long long";
    return _;
}
const std::string &get_type(const unsigned short *)
{
    static const std::string _ = "const unsigned short";
    return _;
}
const std::string &get_type(double *)
{
    static const std::string _ = "double";
    return _;
}
const std::string &get_type(float *)
{
    static const std::string _ = "float";
    return _;
}
const std::string &get_type(int *)
{
    static const std::string _ = "int";
    return _;
}
const std::string &get_type(long *)
{
    static const std::string _ = "long";
    return _;
}
const std::string &get_type(long double *)
{
    static const std::string _ = "long double";
    return _;
}
const std::string &get_type(long long *)
{
    static const std::string _ = "long long";
    return _;
}
const std::string &get_type(short *)
{
    static const std::string _ = "short";
    return _;
}
const std::string &get_type(signed char *)
{
    static const std::string _ = "signed char";
    return _;
}
const std::string &get_type(std::map<int, int> *)
{
    static const std::string _ = "std::map<int, int>";
    return _;
}
const std::string &get_type(std::string *)
{
    static const std::string _ = "std::string";
    return _;
}
const std::string &get_type(std::vector<int> *)
{
    static const std::string _ = "std::vector<int>";
    return _;
}
const std::string &get_type(unsigned char *)
{
    static const std::string _ = "unsigned char";
    return _;
}
const std::string &get_type(unsigned int *)
{
    static const std::string _ = "unsigned int";
    return _;
}
const std::string &get_type(unsigned long *)
{
    static const std::string _ = "unsigned long";
    return _;
}
const std::string &get_type(unsigned long long *)
{
    static const std::string _ = "unsigned long long";
    return _;
}
const std::string &get_type(unsigned short *)
{
    static const std::string _ = "unsigned short";
    return _;
}
::reflect::Value get_field_value(std::map<int, int> *cls, uint32_t field)
{
    if (field < cls->size())
    {
        return ::reflect::Value(std::addressof(cls->at(field)), ::reflect::flag_type<std::map<int, int>>());        
    }
    return ::reflect::Value(nullptr, ::reflect::e_nullptr);
}
::reflect::Value get_field_value(std::vector<int> *cls, uint32_t field)
{
    if (field < cls->size())
    {
        return ::reflect::Value(std::addressof(cls->at(field)), ::reflect::flag_type<std::vector<int>>());        
    }
    return ::reflect::Value(nullptr, ::reflect::e_nullptr);
}
