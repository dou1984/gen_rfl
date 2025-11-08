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
#include <limits>
#include <cstring>
#include <cstdint>
#include <cstddef>
#include <concepts>
#include <cassert>
#include <string_view>
#include <type_traits>
#include <utility>
#include <iostream>

namespace reflect
{
#ifndef countof
#define countof(X) (sizeof(X) / sizeof(X[0]))
#endif

    constexpr uint32_t __flag(uint32_t flag) { return 1 << flag; }
    template <typename... F>
    constexpr uint32_t __flags(F... flag) { return (__flag(flag) | ...); }

    template <typename... F>
    constexpr bool __contains__(uint32_t flags, F... flag)
    {
        return (flags & __flags(flag...)) != 0;
    }
    template <typename... F>
    constexpr bool __exclude__(uint32_t flags, F... flag)
    {
        return (flags & __flags(flag...)) == 0;
    }
    template <typename S, typename... T>
    std::string __join(S &&s, T &&...t)
    {
        std::string result = s;
        if constexpr (sizeof...(T) > 0)
        {
            ((result += std::string(",") + std::string(t)), ...);
        }
        return result;
    }
    enum FLAG_REFLECT
    {
        flag_member,

        flag_pointer,
        flag_reference,
        flag_enum,

        flag_union,
        flag_struct,
        flag_class,

        flag_const,
        flag_static,
        flag_virtual,
        flag_volatile,

        flag_public,
        flag_protected,
        flag_private,

        flag_function,
        flag_argument,

    };
    enum BASE_REFLECT
    {
        flag_4bytes,
        flag_8bytes,
        flag_signed,
        flag_integral,
        flag_floating,
        flag_string,
        flag_char_pointer,
        flag_end,
    };

    template <class T>
    struct meta
    {
        using meta_getter_t = void *(*)(const T *);
        using meta_setter_t = int (*)(T *, uint32_t, ...);
        using meta_invoke_t = meta &(*)(const T *, const std::string &);
        using meta_func_t = int (*)(const T *, uint64_t, ...);
        const char *m_variant = "";
        const char *m_type = "";
        uint32_t m_flags = 0;
        uint32_t m_t_flags = 0;
        uint64_t m_field = 0;
        union
        {
            meta_func_t m_func;
            meta_invoke_t m_invoke;
            meta_getter_t m_getter;
        };
        meta_setter_t m_setter;
    };

    template <class T>
    constexpr uint32_t flag_type()
    {
        constexpr auto l = sizeof(T);
        uint32_t _flag = 0;
        _flag |= l <= 4   ? __flag(flag_4bytes)
                 : l <= 8 ? __flag(flag_8bytes)
                          : __flag(flag_end);
        if constexpr (std::is_integral<std::decay_t<T>>::value)
        {
            _flag |= __flag(flag_integral);
            if constexpr (std::is_signed<std::decay_t<T>>::value)
            {
                _flag |= __flag(flag_signed);
            }
        }
        else if constexpr (std::is_floating_point<std::decay_t<T>>::value)
        {
            _flag |= __flag(flag_floating);
        }
        else if constexpr (std::is_same<std::decay_t<T>, std::string>::value)
        {
            _flag |= __flag(flag_string);
        }
        else if constexpr (std::is_same<std::decay_t<T>, const char *>::value || std::is_same<std::decay_t<T>, char *>::value)
        {
            _flag |= __flag(flag_char_pointer);
        }
        return _flag;
    }

}
