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

namespace reflect
{
    using ::func;
    namespace details
    {
        meta<func> &get_meta(const func *cls, branch_string& tag);    
        meta<func> &get_func(const func *cls, branch_string& tag, const std::list<Item>& args_tag);
        int get_base_func(const func *cls, const std::string& tag, const Arguments *_, ...);
    }
    Value get_value(const func *cls, const char *tag);
    Value get_value(const func *cls, const std::string &tag);
    Value get_field_value(const func *cls, uint32_t field);
    const std::string &get_type(const func *cls, const std::string &tag);
    const std::string &get_type(const func *cls, const char *tag);
    const std::string &get_type(func *cls);
    const std::string &get_type(const func *cls);
    const std::string &get_typeid(const func *cls, const std::string &tag);
    const std::string &get_typeid(const func *cls);
    const std::string &get_field_type(const func *cls, uint32_t field);
    uint64_t get_field(const func *cls, const std::string &tag);
    uint64_t get_field(const func *cls, const char *tag);
    const uint64_t get_fields_count(const func *cls);
    const std::string &get_name(const func *cls, uint32_t field);
    
    template <class T>
    int set_value(func *cls, const std::string &_tag, T &&value)
    {    
        branch_string tag(_tag);
        auto o = details::get_meta(cls, tag);
        return set_value(cls, o, get_type((std::decay_t<decltype(value)> *)(0)), std::forward<T>(value));    
    }
    template <class... R>
    int invoke(func *cls, const std::string &_tag, R &&...args)
    {
        static IArguments _(std::forward<R>(args)...);
        branch_string tag(_tag);
        auto &_invoke = details::get_func(cls, tag, _.m_arguments);
        if (__contains__(_invoke.m_flags, flag_argument))
        {
            return _invoke.m_func(cls, std::addressof(_), std::addressof(args)...);
        }
        return details::get_base_func(cls, _tag, std::addressof(_), std::addressof(args)...);
    }
    template <class Ret, class... R>
    int invoke2(func *cls, const std::string &_tag, Ret&& ret, R &&...args)
    {
        static OArguments _(std::forward<Ret>(ret), std::forward<R>(args)...);
        branch_string tag(_tag);
        auto &_invoke = details::get_func(cls, tag, _.m_arguments);
        if (__contains__(_invoke.m_flags, flag_argument))
        {
            return _invoke.m_func(cls, std::addressof(_), std::addressof(ret), std::addressof(args)...);
        }
        return details::get_base_func(cls, _tag, std::addressof(_), std::addressof(ret), std::addressof(args)...);
    }
}
