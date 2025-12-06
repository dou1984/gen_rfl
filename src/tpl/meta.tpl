#include <cstdint>
#include <cstdarg>
#include <iostream>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "{{header}}"{{#is_base}}
#include "{{variant}}.h"{{/is_base}}
#include "{{class}}.h"
#include <gen_rfl/setter.h>
#include <gen_rfl/arguments.h>
#include <gen_rfl/item.h>
{{#nmsp}}
using namespace {{namespace}};{{/nmsp}}

namespace reflect
{
    enum {{class}}_meta_enum
    {{{#fields}}
        e__{{class}}__{{variant}},{{/fields}}
        e__{{class}}__end,
    };
    enum {{class}}_func_enum
    {{{#invoke_fields}}
        e__{{class}}__{{variant}}{{__field}},{{/invoke_fields}}
        e__{{class}}__func__end,
    };
    static int set_value_invalid({{class}} *cls, uint32_t, ...)
    {
        return 0;
    }
    static reflect::meta<{{class}}> g_default_meta = {
        .m_variant = "",
        .m_type = "",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const {{class}} *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    static reflect::meta<{{class}}> g_{{class}} = {
        .m_variant = "{{class}}",
        .m_type = "{{type}}",
        .m_flags = 0,
        .m_t_flags = 0,
        .m_field = UINT32_MAX,
        .m_getter = [](const {{class}} *c) -> void* { return nullptr; },
        .m_setter = set_value_invalid,
    };
    {{#invoke_fields}}
    int invoke__{{class}}__{{variant}}{{__field}}(const {{class}}* c, const Arguments *, ...);
    int invoke__{{class}}__{{variant}}{{__field}}_v({{class}}* c, const Arguments *, va_list);{{/invoke_fields}}
    static meta<{{class}}> g_{{class}}_func[] = 
    {{{#invoke_fields}}
        {
            .m_variant = "{{variant}}",
            .m_type = "{{type}}",
            .m_flags = {{flags}},
            .m_t_flags = 0,
            .m_field = e__{{class}}__{{variant}}{{__field}}, // {{field}}{{#invoke_field}}
            .m_func = invoke__{{class}}__{{variant}}{{__field}},
            .m_func_v = invoke__{{class}}__{{variant}}{{__field}}_v,{{/invoke_field}}        
        },{{/invoke_fields}}
    };
    {{#invoke_func}}
    reflect::meta<{{class}}>& invoke__{{class}}__{{variant}}(const {{class}} *c, const std::list<Item> &tag);{{/invoke_func}}
    static reflect::meta<{{class}}> g_{{class}}_meta[] = {{{#fields}}
    {
        .m_variant = "{{variant}}",{{#not}}{{#is_member}}{{#is_field}}
        .m_type = []() -> auto
        {
            if constexpr (reflect::fundamental<{{type}}>) 
            {          
                return typeid({{type}}).name();         
            }                                         
            return "{{type}}";
        }(),{{/is_field}}{{#is_static}}
        .m_type = []() -> auto
        {
            if constexpr (reflect::fundamental<{{type}}>) 
            {          
                return typeid({{type}}).name();         
            }                                         
            return "{{type}}";
        }(),{{/is_static}}{{#is_derived}}
        .m_type = "{{type}}",{{/is_derived}}{{/is_member}}{{/not}}
        .m_type = "{{type}}",
        .m_flags = {{flags}},
        .m_t_flags = {{t_flags}},
        .m_field = e__{{class}}__{{variant}}, // {{field}}{{#is_invoke}}
        .m_invoke = invoke__{{class}}__{{variant}},
        .m_setter = set_value_invalid,{{/is_invoke}}{{#is_member}}{{#is_field}}
        .m_getter = [](const {{class}} *cls) -> void * 
        { return (void *)std::addressof(cls->{{variant}}); },{{/is_field}}{{#is_static}}
        .m_getter = [](const {{class}} *cls) -> void * 
        { return (void *)std::addressof(cls->{{variant}}); },{{/is_static}}{{#is_derived}}
        .m_getter = [](const {{class}} *cls) -> void * 
        { return (void *)static_cast<const {{variant}} *>(cls); },{{/is_derived}}{{#is_field}}
        .m_setter = []() -> auto
        { return __setter__<{{class}}, __ref_member__<{{class}}, &{{class}}::{{variant}}>>; }(),{{/is_field}}{{#is_static}}
        .m_setter = []() -> auto
        { return __setter__<{{class}}, __ref_static__<{{class}}, &{{class}}::{{variant}}>>; }(),{{/is_static}}{{#is_derived}}
        .m_setter = []() -> auto
        { return __setter__<{{class}}, __ref_base__<{{class}}, {{variant}}>>; }(),{{/is_derived}}{{/is_member}}
    },{{/fields}}
    };
    reflect::Value __get_value(const {{class}}* cls, const std::string& _tag)
    {{{#is_base}} 
        {
            branch_string tag(_tag);
            auto &_meta = details::get_meta(static_cast<const {{variant}} *>(cls), tag);
            if (__contains__(_meta.m_flags, flag_member))
            {
                return reflect::Value(_meta.m_getter(cls), _meta.m_t_flags);   
            }
        }{{/is_base}}
        return reflect::Value(nullptr, reflect::e_nullptr);
    }

