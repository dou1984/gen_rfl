// Copyright (c) 2023-2025 ZhaoYunshan
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

    constexpr uint64_t __flag(uint32_t flag) { return 1 << flag; }
    template <typename... CLS>
    constexpr uint64_t __flags(CLS... flag) { return (__flag(flag) | ...); }

    template <typename... CLS>
    constexpr bool __has_flag(uint64_t flags, CLS... flag)
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
        // flag_lambda,
        flag_argument,
        flag_return,

        flag_next,

    };
    struct meta
    {
        const char *m_variant = "";
        const char *m_type = "";
        uint64_t m_flags = 0;
        uint64_t m_field = 0;
        union
        {
            uint64_t m_offset = 0;
            void *m_ptr;
            int (*m_func)(void *, uint64_t, ...);
            meta &(*m_invoke)(void *, const std::string &);
        };
    };

}