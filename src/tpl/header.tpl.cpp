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

#include <string>
#include "tpl.h"

const std::string header_tpl = R"magic({{license}}
#pragma once
#include <string>
#include <typeinfo>
#include <cassert>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "{{header}}"

using namespace reflect;{{#namesp}}
namespace {{namespace}}
{{{/namesp}}
{{raw_class}};
namespace __details__
{
    meta<{{class}}> &get_meta(const {{class}} *cls, branch_string& tag);    
    meta<{{class}}> &get_meta(const {{class}} *cls, branch_string& tag, const std::string& func_args);
}
void *get_value(const {{class}} *cls, const char *tag);
void *get_value(const {{class}} *cls, const std::string &tag);
void *get_value(const {{class}} *cls, const std::string &tag, const char *expected_type);
void *get_field_value(const {{class}} *cls, uint32_t field);
const char *get_type(const {{class}} *cls, const std::string &tag);
const char *get_type(const {{class}} *cls, const char *tag);
const char *get_type(const {{class}} *cls);
uint64_t get_field(const {{class}} *cls, const std::string &tag);
uint64_t get_field(const {{class}} *cls, const char *tag);
const uint64_t get_fields_max(const {{class}} *cls);
const char *get_name(const {{class}} *cls, uint32_t field);

template <class T>
T *get_value({{class}} *cls, const char *tag)
{
    static auto type = ::get_type((T *)(0));
    return static_cast<T *>(get_value(cls, tag, type));
}
template <class T>
T *get_value({{class}} *cls, const std::string &tag)
{
    static auto type = ::get_type((T *)(0));
    return static_cast<T *>(get_value(cls, tag, type));
}
template <class T>
T *get_value({{class}} *cls, uint32_t field)
{
    return static_cast<T *>(get_field_value(cls, field));
}   
template <class T>
T *set_value({{class}} *cls, const std::string &tag, const T &value)
{
    static auto type = ::get_type((T *)(0));
    auto o = static_cast<T *>(get_value(cls, tag, type));
    if (o)
    {
        *o = value;    
    }
    return o;
}
template <class T>
T *set_value({{class}} *cls, const std::string &tag, T &&value)
{
    static auto type = ::get_type((T *)(0));
    auto o = static_cast<T *>(get_value(cls, tag, type));
    if (o)
    {
        *o = std::move(value);
    }
    return o;
}

template <class... R>
int invoke({{class}} *cls, const std::string &_tag, R &&...args)
{
    branch_string tag(_tag);
    if constexpr (sizeof...(args) > 0)
    {
        static const std::string func_args = std::string("(") + __join(get_type(std::addressof(args))...) + ")";
        return __details__::get_meta(cls, tag, func_args).m_func(cls, sizeof...(args), std::forward<R>(args)...);
    }
    else
    {
        static const std::string func_args = "()";
        return __details__::get_meta(cls, tag, func_args).m_func(cls, sizeof...(args));
    }
}
template <class Ret, class... R>
int invoke_r({{class}} *cls, const std::string &_tag, Ret&& ret, R &&...args)
{   
    branch_string tag(_tag);
    if constexpr (sizeof...(args) > 0)
    {
        static const std::string func_args = std::string(get_type(std::addressof(ret))) + std::string("(") + __join(get_type(std::addressof(args))...) + ")";
        return __details__::get_meta(cls, tag, func_args).m_func(cls, sizeof...(args) + 1, std::forward<Ret>(ret), std::forward<R>(args)...);
    }
    else
    {
        static const std::string func_args = std::string(get_type(std::addressof(ret))) + "()";
        return __details__::get_meta(cls, tag, func_args).m_func(cls, sizeof...(args) + 1, std::forward<Ret>(ret));
    }
}
{{#namesp}}
}{{/namesp}}
)magic";

namespace tpl
{
    const std::string &header()
    {
        return header_tpl;
    }
}