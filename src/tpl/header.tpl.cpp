#include <string>
#include "tpl.h"

const std::string header_tpl = R"(
#pragma once

#include <string>
#include <gen_rfl/reflect.h>

using namespace reflect;

{{raw_class}};
meta &get_meta(const {{class}} *cls, const std::string &tag);
void* get_value(const {{class}} *cls, const std::string &tag);
void* get_value(const {{class}} *cls, const char* tag);
const char *get_type(const {{class}} *cls, const std::string &tag);
const char *get_type(const {{class}} *cls, const char* tag);
const char *get_type(const {{class}} *cls);
uint64_t get_field(const {{class}} *cls, const std::string &tag);
uint64_t get_field(const {{class}} *cls, const char* tag);
uint64_t get_field_max(const {{class}} *cls);
template <class T>
T& get_value(const {{class}} *cls, const std::string &tag)
{
    return *(T *)get_value(cls, tag);
}
template <class T>
T& get_value(const {{class}} *cls, const char* tag)
{ 
    return *(T *)get_value(cls, tag);
}
)";

namespace tpl
{
    const std::string &header()
    {
        return header_tpl;
    }
}