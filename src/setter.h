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
    template <class CLS, auto MEMBER>
    auto &__ref_member__(CLS *cls)
    {
        return (cls->*MEMBER);
    }
    template <class CLS, class BASE>
    auto &__ref_base__(CLS *cls)
    {
        return *(static_cast<BASE *>(cls));
    }
    template <class CLS, auto STATIC>
    auto &__ref_static__(CLS *cls)
    {
        return *STATIC;
    }
    template <class CLS, auto FUNC>
    int __setter__(CLS *cls, unsigned int _flag, ...)
    {
        auto &field = FUNC(cls);
        int r = 0;
        va_list __arguments__;
        va_start(__arguments__, _flag);
        do
        {
            constexpr void *__meta__[] = {
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
                &&label_type_other,
            };
            goto *__meta__[_flag];
        label_uint8:
        label_uint16:
        label_uint32:
        {
            auto _value = va_arg(__arguments__, uint32_t);
            r = __set__(field, _flag, _value);
            break;
        }
        label_uint64:
        {
            auto _value = va_arg(__arguments__, uint64_t);
            r = __set__(field, _flag, _value);
            break;
        }
        label_int8:
        label_int16:
        label_int32:
        {
            auto _value = va_arg(__arguments__, int32_t);
            r = __set__(field, _flag, _value);
            break;
        }
        label_int64:
        {
            auto _value = va_arg(__arguments__, int64_t);
            r = __set__(field, _flag, _value);
            break;
        }
        label_float:
        label_double:
        {
            auto _value = va_arg(__arguments__, double);
            r = __set__(field, _flag, _value);
            break;
        }
        label_cstr:
        {
            auto _value = va_arg(__arguments__, const char *);
            r = __set__(field, _flag, _value);
            break;
        }
        label_string:
        {
            auto _value = va_arg(__arguments__, const char *);
            auto _size = va_arg(__arguments__, size_t);
            std::string_view str(_value, _size);
            r = __set__(field, _flag, str);
            break;
        }
        label_type_other:
        {
            std::decay_t<decltype(field)> *t = nullptr;
            auto _type = va_arg(__arguments__, const std::string *);
            if (*_type == ::get_type(t))
            {
                auto _value = va_arg(
                    __arguments__, std::decay_t<decltype(field)> *);
                r = __set__(field, _flag, _value);
                break;
            }
        }
        } while (false);
        va_end(__arguments__);
        return r;
    }
}