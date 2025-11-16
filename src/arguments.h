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
#include <bitset>
#include <cstring>
#include "reflect.h"

namespace reflect
{
    struct Arguments
    {
        uint32_t m_count = 0;
        std::bitset<ARGUMENTS_SIZE_MAX> m_t_flags;
        std::string m_arguments;

        template <class T>
        void __set(uint32_t i)
        {
            if constexpr (std::is_const<T>::value)
            {
                m_t_flags.set(i);
            }
        }
    };
    struct NArguments : Arguments
    {
        NArguments()
        {
            m_count = 0;
            m_arguments += "(";

            m_arguments += ")";
        }
        template <class... T>
        NArguments(T &&...t)
        {
            m_count = 0;
            m_arguments += "(";
            if (sizeof...(t) > 0)
            {
                (__set<T>(m_count++), ...);
                m_arguments += ::reflect::__join(get_type(std::addressof(t))...);
            }
            m_arguments += ")";
        }
    };
    struct RArguments : Arguments
    {
        template <class R, class... T>
        RArguments(R &&r, T &&...t)
        {
            m_count = 0;
            m_arguments += get_type(std::addressof(r));
            m_arguments += "(";
            (__set<T>(m_count++), ...);
            m_arguments += ::reflect::__join(get_type(std::addressof(t))...);
            m_arguments += ")";
            m_count++;
        }
        template <class R>
        RArguments(R &&r)
        {
            m_count = 0;
            m_arguments += get_type(std::addressof(r));
            m_arguments += "(";
            m_arguments += ")";
            m_count++;
        }
    };
}