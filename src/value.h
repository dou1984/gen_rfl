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
#include <bitset>
#include "reflect.h"
#include "set_variant.h"

namespace reflect
{
    class Value
    {

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
            if (m_flags == e_string)
            {
                return __ref<std::string>();
            }
            static std::string _ = "";
            return _;
        }
        const char *as_cstr()
        {
            if (m_flags == e_cstr)
            {
                return __ref<const char *>();
            }
            else if (m_flags == e_string)
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
        void *m_data = nullptr;
        uint32_t m_flags = 0;

    private:
        template <class T>
        T &__ref() { return *((T *)m_data); }
        template <class T, class S>
        T __to()
        {
            T t;
            __set__(t, m_flags, __ref<S>());
            return t;
        }
        template <class T>
        T as_number()
        {
            constexpr void *__meta__[] = {
                &&label_nullptr,
                &&label_uint8,
                &&label_uint16,
                &&label_uint32,
                &&label_uint64,
                &&label_int8,
                &&label_int16,
                &&label_int32,
                &&label_int64,
                &&label_float,
                &&label_double,
                &&label_cstr,
                &&label_string,
                &&label_type_unfundametal,
            };
            assert(m_flags < e_reflect_end);
            goto *__meta__[m_flags];
        label_uint8:
            return __ref<uint8_t>();
        label_uint16:
            return __ref<uint16_t>();
        label_uint32:
            return __ref<uint32_t>();
        label_uint64:
            return __ref<uint64_t>();
        label_int8:
            return __ref<int8_t>();
        label_int16:
            return __ref<int16_t>();
        label_int32:
            return __ref<int32_t>();
        label_int64:
            return __ref<int64_t>();
        label_float:
            return __ref<float>();
        label_double:
            return __ref<double>();
        label_nullptr:
        label_cstr:
        label_string:
        label_type_unfundametal:
            return 0;
        }
        template <class T>
        T __to()
        {
            constexpr void *__meta__[] = {
                &&label_nullptr,
                &&label_uint8,
                &&label_uint16,
                &&label_uint32,
                &&label_uint64,
                &&label_int8,
                &&label_int16,
                &&label_int32,
                &&label_int64,
                &&label_float,
                &&label_double,
                &&label_cstr,
                &&label_string,
                &&label_type_unfundametal,
            };
            assert(m_flags < e_reflect_end);
            goto *__meta__[m_flags];
        label_uint8:
            return __to<T, uint8_t>();
        label_uint16:
            return __to<T, uint16_t>();
        label_uint32:
            return __to<T, uint32_t>();
        label_uint64:
            return __to<T, uint64_t>();
        label_int8:
            return __to<T, int8_t>();
        label_int16:
            return __to<T, int16_t>();
        label_int32:
            return __to<T, int32_t>();
        label_int64:
            return __to<T, int64_t>();
        label_float:
            return __to<T, float>();
        label_double:
            return __to<T, double>();
        label_cstr:
            return __to<T, const char *>();
        label_string:
            return __to<T, std::string>();
        label_type_unfundametal:
        label_nullptr:
            return T{};
        }
    };

}