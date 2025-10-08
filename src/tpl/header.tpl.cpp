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

#include <string>
#include "tpl.h"

const std::string header_tpl = R"magic({{lincense}}
#pragma once
#include <string>
#include <typeinfo>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "{{header}}"

using namespace reflect;{{#namesp}}
namespace {{namespace}}
{{{/namesp}}
{{raw_class}};
namespace __details__
{
    meta &get_meta(const {{class}} *cls, branch_string& tag);
    meta &get_meta({{class}} *cls, branch_string& tag, const std::string& func_args);
}
void *get_value(const {{class}} *cls, const char *tag);
void *get_value(const {{class}} *cls, const std::string &tag);
void *get_value(const {{class}} *cls, const std::string &tag, const char *expected_type);
const char *get_type(const {{class}} *cls, const std::string &tag);
const char *get_type(const {{class}} *cls, const char *tag);
const char *get_type(const {{class}} *cls);
uint64_t get_field(const {{class}} *cls, const std::string &tag);
uint64_t get_field(const {{class}} *cls, const char *tag);
const uint64_t get_fields_max(const {{class}} *cls);
void* get_field_value(const {{class}} *cls, uint64_t field);
const char *get_name(const {{class}} *cls, uint64_t field);

template <class T>
T &get_value(const {{class}} *cls, const char *tag)
{
    auto type = get_type((T *)(0));
    return *(T *)get_value(cls, tag, type);    
}
template <class T>
T &get_value(const {{class}} *cls, const std::string &tag)
{ 
    return get_value<T>(cls, tag.c_str());
}
template <class T>
T &get_value(const {{class}} *cls, uint64_t field)
{
    return *(T *)get_field_value(cls, field);
}   
template <class T>
T *set_value({{class}} *cls, const std::string &tag, const T &value)
{
    auto type = get_type(&value);
    auto o = (T *)get_value(cls, tag, type);
    if (o)
    {
        *o = value;    
    }
    return o;
}
template <class T>
T *set_value({{class}} *cls, const std::string &tag, T &&value)
{
    auto type = get_type(&value);
    auto o = (T *)get_value(cls, tag, type);
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
        static std::string func_args = std::string("(") + __join(get_type(std::addressof(args))...) + ")";
        auto _meta = __details__::get_meta(cls, tag, func_args);
        return (_tag == _meta.m_variant) ? _meta.m_func(cls, sizeof...(args), std::forward<R>(args)...) : -1;
    }
    else
    {
        static std::string func_args = "()";       
        auto _meta = __details__::get_meta(cls, tag, func_args);
        return (_tag == _meta.m_variant) ? _meta.m_func(cls, sizeof...(args)) : -1;
    }
}
template <class Ret, class... R>
int invoke_r({{class}} *cls, const std::string &_tag, Ret&& ret, R &&...args)
{   
    branch_string tag(_tag);   
    if constexpr (sizeof...(args) > 0)
    {
        static std::string func_args = std::string(get_type(std::addressof(ret))) + std::string("(") + __join(get_type(std::addressof(args))...) + ")";
        auto _meta = __details__::get_meta(cls, tag, func_args);
        return (_tag == _meta.m_variant) ? _meta.m_func(cls, sizeof...(args) + 1, std::forward<Ret>(ret), std::forward<R>(args)...) : -1;
    }
    else
    {
        static std::string func_args = std::string(get_type(std::addressof(ret))) + "()";       
        auto _meta = __details__::get_meta(cls, tag, func_args);
        return (_tag == _meta.m_variant) ? _meta.m_func(cls, sizeof...(args) + 1, std::forward<Ret>(ret)) : -1;
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