#pragma once
#include <cstring>
#include <cstdint>
#include <cstddef>

namespace reflect
{
#ifndef countof
#define countof(X) (sizeof(X) / sizeof(X[0]))
#endif
    template <typename CLS, typename M>
    constexpr uint64_t _offsetof(M CLS::*member)
    {
        return reinterpret_cast<uint64_t>(&(static_cast<CLS *>(nullptr)->*member));
    }
    template <typename CLS, typename M>
    constexpr uint64_t _offsetof()
    {
        return (uint64_t)(static_cast<M *>(reinterpret_cast<CLS *>(0)));
    }

    constexpr uint64_t __flag(uint32_t flag) { return 1 << flag; }
    template <typename... CLS>
    constexpr uint64_t __flags(CLS... flag) { return (__flag(flag) | ...); }

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

        flag_union,
        flag_array,
        flag_map,
        flag_set,
        flag_struct,
        flag_class,

        flag_const,
        flag_static,

        flag_member,
        flag_function,
        flag_lambda,

        flag_8bit,
        flag_16bit,
        flag_32bit,
        flag_64bit,
        flag_128bit,

        flag_signed,
    };
    struct meta
    {
        const char *m_variant = "";
        const char *m_type = "";
        const char *m_raw_type = "";
        uint64_t m_flags = 0;
        uint64_t m_field = 0;
        uint64_t m_offset = 0;
    };

}