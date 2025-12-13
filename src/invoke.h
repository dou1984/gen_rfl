#pragma once
#include "arguments.h"

namespace reflect
{
    template <class C, class S, class... A>
    int __invoke__(C *cls, const S &_tag, const Arguments &_, A &&...args)
    {
        branch_string tag(_tag);
        auto &_invoke = details::get_func(cls, tag, _.m_arguments);
        if (__contains__(_invoke.m_flags, flag_argument))
        {
            return _invoke.m_func(cls, std::addressof(_), std::addressof(args)...);
        }
        return details::get_base_func(cls, _tag, std::addressof(_), std::addressof(args)...);
    }
}