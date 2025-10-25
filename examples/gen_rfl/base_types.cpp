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


const char *get_type(char * *)
{
    return "char *";
}
const char *get_type(const char * *)
{
    return "const char *";
}
const char *get_type(const double *)
{
    return "const double";
}
const char *get_type(const float *)
{
    return "const float";
}
const char *get_type(const int *)
{
    return "const int";
}
const char *get_type(const long *)
{
    return "const long";
}
const char *get_type(const short *)
{
    return "const short";
}
const char *get_type(const signed char *)
{
    return "const signed char";
}
const char *get_type(const std::map<int, int> *)
{
    return "const std::map<int, int>";
}
const char *get_type(const std::string *)
{
    return "const std::string";
}
const char *get_type(const std::vector<int> *)
{
    return "const std::vector<int>";
}
const char *get_type(const unsigned char *)
{
    return "const unsigned char";
}
const char *get_type(const unsigned int *)
{
    return "const unsigned int";
}
const char *get_type(const unsigned long *)
{
    return "const unsigned long";
}
const char *get_type(const unsigned short *)
{
    return "const unsigned short";
}
const char *get_type(double *)
{
    return "double";
}
const char *get_type(float *)
{
    return "float";
}
const char *get_type(int *)
{
    return "int";
}
const char *get_type(long *)
{
    return "long";
}
const char *get_type(short *)
{
    return "short";
}
const char *get_type(signed char *)
{
    return "signed char";
}
const char *get_type(std::map<int, int> *)
{
    return "std::map<int, int>";
}
const char *get_type(std::string *)
{
    return "std::string";
}
const char *get_type(std::vector<int> *)
{
    return "std::vector<int>";
}
const char *get_type(unsigned char *)
{
    return "unsigned char";
}
const char *get_type(unsigned int *)
{
    return "unsigned int";
}
const char *get_type(unsigned long *)
{
    return "unsigned long";
}
const char *get_type(unsigned short *)
{
    return "unsigned short";
}

