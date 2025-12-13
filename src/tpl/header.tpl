{{license}}
#pragma once
#include <string>
#include <string_view>
#include <typeinfo>
#include <cassert>
#include <functional>
#include <gen_rfl/value.h>
#include <gen_rfl/branch_string.h>
#include <gen_rfl/reflect.h>
#include "{{header}}"{{#is_base}}
#include "{{variant}}.h"{{/is_base}}

namespace reflect
{{{#nmsp}}
    using {{namespace}}::{{class}};{{#is_base}}
    using {{namespace}}::{{variant}};{{/is_base}}{{/nmsp}}{{#no_nmsp}}{{#is_base}}
    using ::{{variant}};{{/is_base}}
    using ::{{class}};{{/no_nmsp}}
    namespace details
    {
        meta<{{class}}> &get_meta(const {{class}} *cls, branch_string& tag);    
        meta<{{class}}> &get_func(const {{class}} *cls, branch_string& tag, const std::list<Item> &argu_item);
        int get_base_func(const {{class}} *cls, const std::string_view& tag, const Arguments *_, ...);
    }
    Value get_value(const {{class}} *cls, const char *tag);
    Value get_value(const {{class}} *cls, const std::string &tag);
    Value get_field_value(const {{class}} *cls, uint32_t field);
    const std::string &get_type(const {{class}} *cls, const std::string &tag);
    const std::string &get_type(const {{class}} *cls, const char *tag);
    const std::string &get_type({{class}} *cls);
    const std::string &get_type(const {{class}} *cls);
    const std::string &get_type({{class}} **cls);
    const std::string &get_type(const {{class}} **cls);
    const std::string &get_typeid(const {{class}} *cls, const std::string &tag);
    const std::string &get_typeid(const {{class}} *cls);
    const std::string &get_field_type(const {{class}} *cls, uint32_t field);
    uint64_t get_field(const {{class}} *cls, const std::string &tag);
    uint64_t get_field(const {{class}} *cls, const char *tag);
    const uint64_t get_fields_count(const {{class}} *cls);
    const std::string &get_name(const {{class}} *cls, uint32_t field);
    
    int for_each(const {{class}} *cls, const std::function<void(const std::string &, const std::string &, const Value &)> &);
   
}
