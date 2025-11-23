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
#include "../../base_types.h"
#include <gen_rfl/arguments.h>

namespace fastest
{
struct common;
namespace __details__
{
    ::reflect::meta<common> &get_meta(const common *cls, ::reflect::branch_string& tag);    
    ::reflect::meta<common> &get_meta(const common *cls, ::reflect::branch_string& tag, const std::string& func_args);
}
::reflect::Value get_value(const common *cls, const char *tag);
::reflect::Value get_value(const common *cls, const std::string &tag);
::reflect::Value get_field_value(const common *cls, uint32_t field);
const std::string &get_type(const common *cls, const std::string &tag);
const std::string &get_type(const common *cls, const char *tag);
const std::string &get_type(const common *cls);
const std::string &get_field_type(const common *cls, uint32_t field);
uint64_t get_field(const common *cls, const std::string &tag);
uint64_t get_field(const common *cls, const char *tag);
const uint64_t get_fields_count(const common *cls);
const std::string &get_name(const common *cls, uint32_t field);
 
template <class T>
int set_value(common *cls, const std::string &_tag, T &&value)
{    
    ::reflect::branch_string tag(_tag);
    auto o = __details__::get_meta(cls, tag);
    return set_value(cls, o, std::forward<T>(value));    
}
template <class... R>
int invoke(common *cls, const std::string &_tag, R &&...args)
{
    static reflect::BArguments _(std::forward<R>(args)...);
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag, _.m_arguments).m_func(cls, std::addressof(_), std::addressof(args)...);
}
template <class Ret, class... R>
int invoke_r(common *cls, const std::string &_tag, Ret&& ret, R &&...args)
{
    static reflect::RArguments _(std::forward<Ret>(ret), std::forward<R>(args)...);
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag, _.m_arguments).m_func(cls, std::addressof(_), std::addressof(ret), std::addressof(args)...);
}

}