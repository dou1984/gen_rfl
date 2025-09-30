#include <string>
#include "tpl.h"

const std::string header_tpl = R"(
{{lincense}}
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
meta &get_meta(const {{class}} *cls, branch_string& tag);
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
    auto _meta = get_meta(cls, tag);
    if constexpr (sizeof...(args) > 0)
    {
        static std::string func_args = ((std::string(get_type(&args)) + ",") + ...);
        return _meta.m_func(cls, sizeof...(args), func_args, get_type(&args)..., std::forward<R>(args)...);
    }
    else
    {
        static std::string func_args = "";
        return _meta.m_func(cls, sizeof...(args), func_args);
    }
}
{{#namesp}}
}{{/namesp}}
)";

namespace tpl
{
    const std::string &header()
    {
        return header_tpl;
    }
}