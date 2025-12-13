{{license}}
#pragma once
#include "{{header}}"
#include "{{class}}.h"{{#is_base}}
#include "{{variant}}.h"{{/is_base}}
#include <gen_rfl/arguments.h>
#include <gen_rfl/set_value.h>
#include <gen_rfl/invoke.h>

namespace reflect
{{{#nmsp}}
    using {{namespace}}::{{class}};{{#is_base}}
    using {{namespace}}::{{variant}};{{/is_base}}{{/nmsp}}{{#no_nmsp}}{{#is_base}}
    using ::{{variant}};{{/is_base}}
    using ::{{class}};{{/no_nmsp}}
    
    template <class S, class T>
    int set_value({{class}} *cls, const S &_tag, T &&value)
    {
        branch_string tag(_tag);
        auto o = details::get_meta(cls, tag);
        return __set_value__(cls, o, get_type((std::decay_t<T> *)0), std::forward<T>(value));    
    }
    template <class S, class... A>
    int invoke({{class}} *cls, const S &_tag, A &&...args)
    {
        static IArguments _(std::addressof(args)...);
        return __invoke__(cls, _tag, _, std::forward<A>(args)...);
    }
    template <class S, class R, class... A>
    int invoke_r({{class}} *cls, const S &_tag, R&& ret, A &&...args)
    {
        static OArguments _(std::addressof(ret), std::addressof(args)...);
        return __invoke__(cls, _tag, _, std::forward<R>(ret), std::forward<A>(args)...);
    }
}
