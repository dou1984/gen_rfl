{{license}}
#pragma once
#include <string>
#include <typeinfo>
#include <cassert>
#include <gen_rfl/value.h>
#include <gen_rfl/branch_string.h>
#include <gen_rfl/reflect.h>
#include "{{header}}"
#include <gen_rfl/arguments.h>
#include <gen_rfl/set_value.h>
{{#namesp}}
namespace {{namespace}}
{{{/namesp}}
{{raw_class}};
namespace __details__
{
    ::reflect::meta<{{class}}> &get_meta(const {{class}} *cls, ::reflect::branch_string& tag);    
    ::reflect::meta<{{class}}> &get_meta(const {{class}} *cls, ::reflect::branch_string& tag, const std::string& func_args);
}
::reflect::Value get_value(const {{class}} *cls, const char *tag);
::reflect::Value get_value(const {{class}} *cls, const std::string &tag);
::reflect::Value get_field_value(const {{class}} *cls, uint32_t field);
const std::string &get_type(const {{class}} *cls, const std::string &tag);
const std::string &get_type(const {{class}} *cls, const char *tag);
const std::string &get_type(const {{class}} *cls);
const std::string &get_field_type(const {{class}} *cls, uint32_t field);
uint64_t get_field(const {{class}} *cls, const std::string &tag);
uint64_t get_field(const {{class}} *cls, const char *tag);
const uint64_t get_fields_count(const {{class}} *cls);
const std::string &get_name(const {{class}} *cls, uint32_t field);
 
template <class T>
int set_value({{class}} *cls, const std::string &_tag, T &&value)
{    
    ::reflect::branch_string tag(_tag);
    auto o = __details__::get_meta(cls, tag);
    return set_value(cls, o, std::forward<T>(value));    
}
template <class... R>
int invoke({{class}} *cls, const std::string &_tag, R &&...args)
{
    static reflect::BArguments _(std::forward<R>(args)...);
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag, _.m_arguments).m_func(cls, std::addressof(_), std::addressof(args)...);
}
template <class Ret, class... R>
int invoke_r({{class}} *cls, const std::string &_tag, Ret&& ret, R &&...args)
{
    static reflect::RArguments _(std::forward<Ret>(ret), std::forward<R>(args)...);
    ::reflect::branch_string tag(_tag);
    return __details__::get_meta(cls, tag, _.m_arguments).m_func(cls, std::addressof(_), std::addressof(ret), std::addressof(args)...);
}
{{#namesp}}
}{{/namesp}}