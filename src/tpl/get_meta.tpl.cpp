#include <string>
#include "tpl.h"

const std::string get_meta_tpl = R"(
meta& get_meta(const {{class}} *cls, const std::string &tag)
{
    branch_string b(tag);
    auto count = countof(g_{{class}}_L{{layer}});
    return __meta(g_{{class}}_L{{layer}}, count, cls, b);
}
void* get_value(const {{class}} *cls, const std::string &tag)
{
    return ((char *)cls + get_meta(cls, tag).m_offset);
}
void* get_value(const {{class}} *cls, const char* tag)
{ 
    return ((char *)cls + get_meta(cls, std::string(tag)).m_offset);
}
const char* get_type(const {{class}} *cls, const std::string &tag)
{
    return get_meta(cls, tag).m_type;
}
const char* get_type(const {{class}} *cls, const char* tag) 
{
    return get_meta(cls, std::string(tag)).m_type;    
}
const char *get_type(const {{class}} *cls)
{
    static const char _class[] = "{{class}}";
    return _class;
}
uint64_t get_field(const {{class}} *cls, const std::string &tag)
{
    return get_meta(cls, tag).m_field;  
}
uint64_t get_field(const {{class}} *cls, const char* tag)
{
    return get_meta(cls, std::string(tag)).m_field;  
}
uint64_t get_field_max(const {{class}} *cls)
{
    return countof(g_{{class}}_L{{layer}});
}
)";

namespace tpl
{
    const std::string &get_meta()
    {
        return get_meta_tpl;
    }
}