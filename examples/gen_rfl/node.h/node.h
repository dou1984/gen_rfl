
#pragma once

#include <string>
#include <gen_rfl/reflect.h>

using namespace reflect;

struct node;
meta &get_meta(const node *cls, const std::string &tag);
void* get_value(const node *cls, const std::string &tag);
void* get_value(const node *cls, const char* tag);
const char *get_type(const node *cls, const std::string &tag);
const char *get_type(const node *cls, const char* tag);
const char *get_type(const node *cls);
uint64_t get_field(const node *cls, const std::string &tag);
uint64_t get_field(const node *cls, const char* tag);
uint64_t get_field_max(const node *cls);
template <class T>
T& get_value(const node *cls, const std::string &tag)
{
    return *(T *)get_value(cls, tag);
}
template <class T>
T& get_value(const node *cls, const char* tag)
{ 
    return *(T *)get_value(cls, tag);
}
