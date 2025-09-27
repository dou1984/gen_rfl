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
