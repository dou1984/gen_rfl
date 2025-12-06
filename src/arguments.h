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
#include "arguments.h"
#include "reflect.h"

namespace reflect
{
    struct Arguments
    {
        std::list<Item> m_arguments;
    };
    struct IArguments : Arguments
    {
        IArguments()
        {
        }
        template <class... T>
        IArguments(T &&...t)
        {
            (m_arguments.emplace_back(get_type(std::addressof(t)), flag_type<T>()), ...);
        }
    };
    struct OArguments : Arguments
    {
        template <class R, class... T>
        OArguments(R &&r, T &&...t)
        {
            m_arguments.emplace_back(get_type(std::addressof(r)) + std::string("@"), flag_type<R>());
            (m_arguments.emplace_back(get_type(std::addressof(t)), flag_type<T>()), ...);
        }
        template <class R>
        OArguments(R &&r)
        {
            m_arguments.emplace_back(get_type(std::addressof(r)) + std::string("@"), flag_type<R>());
        }
    };
}