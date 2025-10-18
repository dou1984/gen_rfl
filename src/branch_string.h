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
#include <string>
#include <cstring>
#include <string_view>

class branch_string
{

public:
    branch_string(const char *_data) : m_data(_data, strlen(_data)) {}
    branch_string(const std::string &_data) : m_data(_data) {}
    branch_string(const std::string_view &_data) : m_data(_data) {}
    operator bool() const { return m_data.size(); }
    uint64_t operator()()
    {
        uint64_t value = 0;
        auto l = m_data.size();
        if (l < sizeof(uint64_t))
        {
            strncpy((char *)&value, m_data.data(), l);
            m_data = m_data.substr(l);
        }
        else
        {
            value = *((uint64_t *)m_data.data());
            m_data = m_data.substr(sizeof(uint64_t));
        }
        return value;
    }

private:
    std::string_view m_data;
};

inline bool has_zero_byte_bitmagic(uint64_t value)
{
    constexpr uint64_t magic = 0x0101010101010101ULL;
    constexpr uint64_t mask = 0x8080808080808080ULL;
    return ((value - magic) & ~value & mask) != 0;
}
inline uint64_t peek(const char *data)
{
    uint64_t r = *(uint64_t *)data;
    if (has_zero_byte_bitmagic(r))
    {
        r = 0;
        for (auto i = 0; i < sizeof(uint64_t) && data[i] != '\0'; i++)
        {
            reinterpret_cast<char *>(&r)[i] = data[i];
        }
    }
    return r;
}
