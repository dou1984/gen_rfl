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
#include <cstdarg>
#include "reflect.h"

namespace reflect
{
#define END_IF_ERR(t)    \
    if (errno == ERANGE) \
    {                    \
        return -1;       \
    }                    \
    if (end == t)        \
    {                    \
        return -1;       \
    }

    template <class T>
    concept signed_integer = std::integral<std::decay_t<T>> && std::is_signed_v<std::decay_t<T>>;

    template <class T>
    concept unsigned_integer = std::integral<std::decay_t<T>> && std::is_unsigned_v<std::decay_t<T>>;

    template <class T>
    concept integer = std::integral<std::decay_t<T>>;

    template <class T>
    concept float_pointer = std::is_floating_point_v<std::decay_t<T>>;

    template <typename T>
    concept arithmetic = std::is_arithmetic_v<std::decay_t<T>>;

    template <class T>
    concept char_string = std::same_as<std::decay_t<T>, std::string> || std::same_as<std::decay_t<T>, std::string_view>;

    template <class T>
    concept char_pointer = std::same_as<std::decay_t<T>, const char *> || std::same_as<std::decay_t<T>, char *>;

    template <class T>
    concept fundamental = std::is_arithmetic_v<std::decay_t<T>> || std::same_as<std::decay_t<T>, const char *> || std::same_as<std::decay_t<T>, char *>;

    template <integer S, arithmetic T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        if constexpr (std::is_integral<std::decay_t<T>>::value)
        {
            if (std::cmp_greater(t, std::numeric_limits<S>::max()) || std::cmp_less(t, std::numeric_limits<S>::min()))
            {
                return -1;
            }
        }
        else if constexpr (std::is_floating_point<std::decay_t<T>>::value)
        {
            if (t > static_cast<std::decay_t<T>>(std::numeric_limits<S>::max()) || t < static_cast<std::decay_t<T>>(std::numeric_limits<S>::min()))
            {
                return -1;
            }
        }
        s = std::forward<T>(t);
        return 0;
    }
    template <float_pointer S, arithmetic T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_uint8, e_uint16, e_uint32, e_uint64, e_int8, e_int16, e_int32, e_int64, e_float, e_double));
        s = std::forward<T>(t);
        return 0;
    }
    template <signed_integer S, char_string T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_string));
        if (t.empty())
        {
            return -1;
        }
        char *end = nullptr;
        auto _value = std::strtoll(t.data(), &end, 10);
        END_IF_ERR(t.data());
        return __set__(s, flag_type<decltype(_value)>(), _value);
    }
    template <unsigned_integer S, char_string T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_string));
        if (t.empty())
        {
            return -1;
        }
        char *end = nullptr;
        auto _value = std::strtoull(t.data(), &end, 10);
        END_IF_ERR(t.data());
        return __set__(s, flag_type<decltype(_value)>(), _value);
    }
    template <float_pointer S, char_string T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_string));
        if (t.empty())
        {
            return -1;
        }
        char *end = nullptr;
        auto _value = std::strtod(t.data(), &end);
        END_IF_ERR(t.data());
        return __set__(s, flag_type<decltype(_value)>(), _value);
    }
    template <signed_integer S, char_pointer T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_cstr));
        if (t == nullptr)
        {
            return -1;
        }
        char *end = nullptr;
        auto _value = std::strtoll(t, &end, 10);
        END_IF_ERR(t);
        return __set__(s, flag_type<decltype(_value)>(), _value);
    }
    template <unsigned_integer S, char_pointer T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_cstr));
        if (t == nullptr)
        {
            return -1;
        }
        char *end = nullptr;
        auto _value = std::strtoull(t, &end, 10);
        END_IF_ERR(t);
        return __set__(s, flag_type<decltype(_value)>(), _value);
    }
    template <float_pointer S, char_pointer T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_cstr));
        if (t == nullptr)
        {
            return -1;
        }
        char *end = nullptr;
        auto _value = std::strtod(t, &end);
        END_IF_ERR(t);
        return __set__(s, flag_type<decltype(_value)>(), _value);
    }
    template <char_string S, arithmetic T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_uint8, e_uint16, e_uint32, e_uint64, e_int8, e_int16, e_int32, e_int64, e_float, e_double));
        s = std::to_string(t);
        return 0;
    }
    template <char_string S, char_string T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_string));
        s = std::forward<T>(t);
        return 0;
    }
    template <char_string S, char_pointer T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_cstr));
        if (t == nullptr)
        {
            return -1;
        }
        s = std::forward<T>(t);
        return 0;
    }
    template <char_pointer S, char_pointer T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_cstr));
        if (t == nullptr)
        {
            return -1;
        }
        if constexpr (std::is_const<typename std::remove_pointer<S>::type>::value)
        {
            s = std::forward<T>(t);
        }
        return 0;
    }
    template <char_pointer S, char_string T>
    int __set__(S &s, uint32_t _flag, T &&t)
    {
        assert(__exists__(_flag, e_string));
        if constexpr (std::is_const<typename std::remove_pointer<S>::type>::value)
        {
            s = t.data();
        }
        return 0;
    }
    template <class S>
    int __set__(S &s, uint32_t _flag, S *p)
    {
        s = *p;
        return 0;
    }
    template <class S, class T>
    int __set__(S &s, uint32_t _flag, T &&p)
    {
        assert(false);
        return 0;
    }
    template <class CLS, class O, class T>
    int set_value(CLS &cls, O &o, T &&value)
    {
        if (!__contains__(o.m_flags, flag_function, flag_argument))
        {
            if constexpr (std::is_arithmetic<std::decay_t<T>>::value)
            {
                return o.m_setter(cls, flag_type<T>(), value);
            }
            else if constexpr (std::is_same<std::decay_t<T>, std::string>::value || std::is_same<std::decay_t<T>, std::string_view>::value)
            {
                return o.m_setter(cls, flag_type<T>(), value.data(), value.size());
            }
            else if constexpr (std::is_same<std::decay_t<T>, const char *>::value || std::is_same<std::decay_t<T>, char *>::value)
            {
                return o.m_setter(cls, flag_type<T>(), value);
            }
            else
            {
                auto _ptr = std::addressof(value);
                return o.m_setter(cls, flag_type<T>(), get_type(_ptr), _ptr);
            }
        }
        return -1;
    }
}