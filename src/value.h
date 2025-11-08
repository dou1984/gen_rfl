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
#include <cstdint>
#include <cstring>
#include <type_traits>
#include "reflect.h"
#include "setter.h"

namespace reflect
{
    class Value
    {
        void *m_data = nullptr;
        uint32_t m_flags = 0;

    public:
        Value(void *_data, uint32_t _flags) : m_data(_data), m_flags(_flags)
        {
        }
        operator bool() const { return m_data != nullptr; }
        void *data() { return m_data; }

        float to_float() { return __to<float>(); }
        double to_double() { return __to<double>(); }
        int32_t to_int32() { return __to<int32_t>(); }
        int64_t to_int64() { return __to<int64_t>(); }
        uint32_t to_uint32() { return __to<uint32_t>(); }
        uint64_t to_uint64() { return __to<uint64_t>(); }
        std::string to_string() { return __to<std::string>(); }

        const std::string &as_string()
        {
            if (__contains__(m_flags, flag_string))
            {
                return __ref<std::string>();
            }
            static std::string _ = "";
            return _;
        }
        const char *as_cstr()
        {
            if (__contains__(m_flags, flag_char_pointer))
            {
                return __ref<const char *>();
            }
            else if (__contains__(m_flags, flag_string))
            {
                return __ref<std::string>().data();
            }
            static const char *_ = "";
            return _;
        }
        int32_t as_int32() { return as_number<int32_t>(); }
        int64_t as_int64() { return as_number<int64_t>(); }
        uint32_t as_uint32() { return as_number<uint32_t>(); }
        uint64_t as_uint64() { return as_number<uint64_t>(); }
        float as_float() { return as_number<float>(); }
        double as_double() { return as_number<double>(); }

    private:
        template <class T>
        T &__ref() { return *((T *)m_data); }

        template <class T>
        T as_number()
        {
            if (__contains__(m_flags, flag_integral))
            {
                if (__contains__(m_flags, flag_signed))
                {
                    if (__contains__(m_flags, flag_4bytes))
                    {
                        return __ref<uint32_t>();
                    }
                    else if (__contains__(m_flags, flag_8bytes))
                    {
                        return __ref<uint64_t>();
                    }
                }
            }
            else if (__contains__(m_flags, flag_floating))
            {
                if (__contains__(m_flags, flag_4bytes))
                {
                    return __ref<float>();
                }
                else if (__contains__(m_flags, flag_8bytes))
                {
                    return __ref<double>();
                }
            }
            return 0;
        }
        template <class T, class S>
        T __to()
        {
            T t;
            __set__(t, m_flags, __ref<S>());
            return t;
        }
        template <class T>
        T __to()
        {
            if (__contains__(m_flags, flag_integral))
            {
                if (__contains__(m_flags, flag_signed))
                {
                    if (__contains__(m_flags, flag_4bytes))
                    {
                        return __to<T, uint32_t>();
                    }
                    else if (__contains__(m_flags, flag_8bytes))
                    {
                        return __to<T, uint64_t>();
                    }
                }
                else
                {
                    if (__contains__(m_flags, flag_4bytes))
                    {
                        return __to<T, int32_t>();
                    }
                    else if (__contains__(m_flags, flag_8bytes))
                    {
                        return __to<T, int64_t>();
                    }
                }
            }
            else if (__contains__(m_flags, flag_floating))
            {
                if (__contains__(m_flags, flag_4bytes))
                {
                    return __to<T, float>();
                }
                else if (__contains__(m_flags, flag_8bytes))
                {
                    return __to<T, double>();
                }
            }
            else if (__contains__(m_flags, flag_string))
            {
                return __to<T, std::string>();
            }
            else if (__contains__(m_flags, flag_char_pointer))
            {
                return __to<T, const char *>();
            }
            return T{};
        }
    };
}