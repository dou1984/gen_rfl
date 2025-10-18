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
#include <cstring>
#include <cstdint>
#include <cstddef>
#include <any>

namespace reflect
{
#ifndef countof
#define countof(X) (sizeof(X) / sizeof(X[0]))
#endif
#define offset(CLS, META) ((char *)(CLS) + (uint64_t)(META.m_offset))

    template <typename CLS, typename M>
    constexpr uint64_t to_offset(M CLS::*member)
    {
        return uint64_t(&(static_cast<CLS *>(0)->*member));
    }
    template <typename CLS, typename M>
    constexpr uint64_t to_offset()
    {
        return uint64_t(static_cast<M *>(static_cast<CLS *>(0)));
    }

    constexpr uint32_t __flag(uint32_t flag) { return 1 << flag; }
    template <typename... CLS>
    constexpr uint32_t __flags(CLS... flag) { return (__flag(flag) | ...); }

    template <typename... CLS>
    constexpr bool __has_flag(uint32_t flags, CLS... flag)
    {
        return (flags & __flags(flag...)) != 0;
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
    enum
    {
        flag_none,
        flag_integer,
        flag_floating,
        flag_char,
        flag_string,
        flag_pointer,
        flag_reference,
        flag_enum,
        flag_signed,

        flag_union,
        flag_array,
        flag_map,
        flag_set,
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
    template <class T>
    struct meta
    {
        using meta_member_t = const void *(*)(const T *);
        using meta_invoke_t = meta &(*)(const T *, const std::string &);
        using meta_func_t = int (*)(const T *, uint64_t, ...);
        const char *m_variant = "";
        const char *m_type = "";
        uint32_t m_flags = 0;
        uint32_t m_field = 0;
        union
        {
            meta_func_t m_func;
            meta_invoke_t m_invoke;
            meta_member_t m_member;
        };
    };

}