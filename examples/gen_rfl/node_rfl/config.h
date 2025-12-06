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

#pragma once
#include <string>
#include <typeinfo>
#include <cassert>
#include <gen_rfl/value.h>
#include <gen_rfl/branch_string.h>
#include <gen_rfl/reflect.h>
#include "../base_types.h"
#include <gen_rfl/arguments.h>
#include <gen_rfl/set_value.h>

struct config;
namespace __details__
{
    ::reflect::meta<config> &get_meta(const config *cls, ::reflect::branch_string& tag);    
    ::reflect::meta<config> &get_func(const config *cls, ::reflect::branch_string& tag, const std::list<::reflect::Item>& args_tag);
    int get_base_func(const config *cls, const std::string& tag, const ::reflect::Arguments *_, ...);
}
::reflect::Value get_value(const config *cls, const char *tag);
::reflect::Value get_value(const config *cls, const std::string &tag);
::reflect::Value get_field_value(const config *cls, uint32_t field);
const std::string &get_type(const config *cls, const std::string &tag);
const std::string &get_type(const config *cls, const char *tag);
const std::string &get_type(const config *cls);
const std::string &get_typeid(const config *cls, const std::string &tag);
const std::string &get_typeid(const config *cls);
const std::string &get_field_type(const config *cls, uint32_t field);
uint64_t get_field(const config *cls, const std::string &tag);
uint64_t get_field(const config *cls, const char *tag);
const uint64_t get_fields_count(const config *cls);
const std::string &get_name(const config *cls, uint32_t field);
 
template <class T>
int set_value(config *cls, const std::string &_tag, T &&value)
{    
    ::reflect::branch_string tag(_tag);
    auto o = __details__::get_meta(cls, tag);
    return set_value(cls, o, std::forward<T>(value));    
}
template <class... R>
int invoke(config *cls, const std::string &_tag, R &&...args)
{
    static ::reflect::IArguments _(std::forward<R>(args)...);
    ::reflect::branch_string tag(_tag);
    auto &_invoke = __details__::get_func(cls, tag, _.m_arguments);
    if (::reflect::__contains__(_invoke.m_flags, ::reflect::flag_argument))
    {
        return _invoke.m_func(cls, std::addressof(_), std::addressof(args)...);
    }
    return __details__::get_base_func(cls, _tag, std::addressof(_), std::addressof(args)...);
}
template <class Ret, class... R>
int invoke2(config *cls, const std::string &_tag, Ret&& ret, R &&...args)
{
    static ::reflect::OArguments _(std::forward<Ret>(ret), std::forward<R>(args)...);
    ::reflect::branch_string tag(_tag);
    auto &_invoke = __details__::get_func(cls, tag, _.m_arguments);
    if (::reflect::__contains__(_invoke.m_flags, ::reflect::flag_argument))
    {
         return _invoke.m_func(cls, std::addressof(_), std::addressof(ret), std::addressof(args)...);
    }
    return __details__::get_base_func(cls, _tag, std::addressof(_), std::addressof(ret), std::addressof(args)...);
}
