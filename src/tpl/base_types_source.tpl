{{license}}
#include "base_types.h"

{{#base_types}}
const std::string &get_type({{class}} *)
{
    static const std::string _ = "{{raw_class}}";
    return _;
}{{/base_types}}{{#base_stl}}
::reflect::Value get_field_value({{class}} *cls, uint32_t field)
{
    if (field < cls->size())
    {
        return ::reflect::Value(std::addressof(cls->at(field)), ::reflect::flag_type<{{class}}>());        
    }
    return ::reflect::Value(nullptr, ::reflect::e_nullptr);
}{{/base_stl}}
