
#pragma once

#include <string>
#include <gen_rfl/reflect.h>

using namespace reflect;

struct base;
meta &get_meta(const base *cls, const std::string &tag);
void* get_value(const base *cls, const std::string &tag);
void* get_value(const base *cls, const char* tag);
const char *get_type(const base *cls, const std::string &tag);
const char *get_type(const base *cls, const char* tag);
const char *get_type(const base *cls);
uint64_t get_field(const base *cls, const std::string &tag);
uint64_t get_field(const base *cls, const char* tag);
uint64_t get_field_max(const base *cls);
template <class T>
T& get_value(const base *cls, const std::string &tag)
{
    return *(T *)get_value(cls, tag);
}
template <class T>
T& get_value(const base *cls, const char* tag)
{ 
    return *(T *)get_value(cls, tag);
}
