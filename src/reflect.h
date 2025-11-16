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
#define ARGUMENTS_SIZE_MAX 32

    constexpr uint32_t __flag(uint32_t flag) { return 1 << flag; }
    template <typename... F>
    constexpr uint32_t __flags(F... flag) { return (__flag(flag) | ...); }

    template <typename... F>
    constexpr bool __contains__(uint32_t flags, F... flag)
    {
        return (flags & __flags(flag...)) != 0;
    }
    template <class... F>
    constexpr bool __exists__(uint32_t flags, F &&...flag)
    {
        return ((flags == flag) || ...);
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
    template <typename S>
    std::string __join(S &&s)
    {
        return s;
    }
    template <typename S>
    std::string __join()
    {
        return "";
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
    enum TYPE_REFLECT
    {
        e_nullptr,
        e_uint8,
        e_uint16,
        e_uint32,
        e_uint64,
        e_int8,
        e_int16,
        e_int32,
        e_int64,
        e_float,
        e_double,
        e_cstr,
        e_string,
        e_type_unfundamental,
        e_type_end
    };
    struct Arguments;
    template <class T>
    struct meta
    {
        using meta_getter_t = void *(*)(const T *);
        using meta_setter_t = int (*)(T *, unsigned int, ...);
        using meta_invoke_t = meta &(*)(const T *, const std::string &);
        using meta_func_t = int (*)(const T *, const Arguments *, ...);
        const std::string m_variant;
        const std::string m_type;
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
        if constexpr (std::is_integral<std::decay_t<T>>::value)
        {
            if constexpr (std::is_signed<std::decay_t<T>>::value)
            {
                return l == 1   ? e_int8
                       : l == 2 ? e_int16
                       : l == 4 ? e_int32
                       : l == 8 ? e_int64
                                : e_type_unfundamental;
            }
            else
            {
                return l == 1   ? e_uint8
                       : l == 2 ? e_uint16
                       : l == 4 ? e_uint32
                       : l == 8 ? e_uint64
                                : e_type_unfundamental;
            }
        }
        else if constexpr (std::is_floating_point<std::decay_t<T>>::value)
        {
            return l == 4   ? e_float
                   : l == 8 ? e_double
                            : e_type_unfundamental;
        }
        else if constexpr (std::is_same<std::decay_t<T>, std::string>::value)
        {
            return e_string;
        }
        else if constexpr (std::is_same<std::decay_t<T>, const char *>::value || std::is_same<std::decay_t<T>, char *>::value)
        {
            return e_cstr;
        }
        return e_type_unfundamental;
    }

}
