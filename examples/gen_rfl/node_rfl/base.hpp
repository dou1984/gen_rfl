// Copyright (c) 2023-2025 Zhao Yun Shan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#pragma once
#include "../base_types.h"
#include "base.h"
#include <gen_rfl/arguments.h>
#include <gen_rfl/set_value.h>
#include <gen_rfl/invoke.h>

namespace reflect
{
    using ::base;
    
    template <class S, class T>
    int set_value(base *cls, const S &_tag, T &&value)
    {
        branch_string tag(_tag);
        auto o = details::get_meta(cls, tag);
        return __set_value__(cls, o, get_type((std::decay_t<T> *)0), std::forward<T>(value));    
    }
    template <class S, class... A>
    int invoke(base *cls, const S &_tag, A &&...args)
    {
        static IArguments _(std::addressof(args)...);
        return __invoke__(cls, _tag, _, std::forward<A>(args)...);
    }
    template <class S, class R, class... A>
    int invoke2(base *cls, const S &_tag, R&& ret, A &&...args)
    {
        static OArguments _(std::addressof(ret), std::addressof(args)...);
        return __invoke__(cls, _tag, _, std::forward<R>(ret), std::forward<A>(args)...);
    }
}
