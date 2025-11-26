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
                auto &_type = get_type(_ptr);
                return o.m_setter(cls, flag_type<T>(), _type, _ptr);
            }
        }
        return -1;
    }
}