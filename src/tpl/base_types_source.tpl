{{license}}
#include "base_types.h"

{{#base_types}}
const std::string &get_type({{class}} *)
{
    static const std::string _ = "{{raw_class}}";
    return _;
}{{/base_types}}{{#base_stl}}
void* get_field_value({{class}} *cls, uint32_t field)
{
    if (field < cls->size())
    {
        return &cls->at(field);
    }
    return nullptr;
}{{/base_stl}}