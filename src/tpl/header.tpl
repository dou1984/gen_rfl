{{license}}
#pragma once
#include <string>
#include <typeinfo>
#include <cassert>
#include <gen_rfl/value.h>
#include <gen_rfl/branch_string.h>
#include <gen_rfl/reflect.h>
#include "{{header}}"{{#is_base}}
#include "{{variant}}.h"{{/is_base}}
#include <gen_rfl/arguments.h>
#include <gen_rfl/set_value.h>

namespace reflect
{{{#nmsp}}
    using {{namespace}}::{{class}};{{#is_base}}
    using {{namespace}}::{{variant}};{{/is_base}}{{/nmsp}}{{#no_nmsp}}{{#is_base}}
    using ::{{variant}};{{/is_base}}
    using ::{{class}};{{/no_nmsp}}
    namespace details
    {
        meta<{{class}}> &get_meta(const {{class}} *cls, branch_string& tag);    
        meta<{{class}}> &get_func(const {{class}} *cls, branch_string& tag, const std::list<Item>& args_tag);
        int get_base_func(const {{class}} *cls, const std::string& tag, const Arguments *_, ...);
    }
    Value get_value(const {{class}} *cls, const char *tag);
    Value get_value(const {{class}} *cls, const std::string &tag);
    Value get_field_value(const {{class}} *cls, uint32_t field);
    const std::string &get_type(const {{class}} *cls, const std::string &tag);
    const std::string &get_type(const {{class}} *cls, const char *tag);
    const std::string &get_type({{class}} *cls);
    const std::string &get_type(const {{class}} *cls);
    const std::string &get_typeid(const {{class}} *cls, const std::string &tag);
    const std::string &get_typeid(const {{class}} *cls);
    const std::string &get_field_type(const {{class}} *cls, uint32_t field);
    uint64_t get_field(const {{class}} *cls, const std::string &tag);
    uint64_t get_field(const {{class}} *cls, const char *tag);
    const uint64_t get_fields_count(const {{class}} *cls);
    const std::string &get_name(const {{class}} *cls, uint32_t field);
    
    template <class T>
    int set_value({{class}} *cls, const std::string &_tag, T &&value)
    {    
        branch_string tag(_tag);
        auto o = details::get_meta(cls, tag);
        return set_value(cls, o, get_type((std::decay_t<decltype(value)> *)(0)), std::forward<T>(value));    
    }
    template <class... R>
    int invoke({{class}} *cls, const std::string &_tag, R &&...args)
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
    int invoke2({{class}} *cls, const std::string &_tag, Ret&& ret, R &&...args)
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
