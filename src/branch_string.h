#pragma once
#include <cstdint>
#include <string>
#include <cstring>
#include <string_view>

#define magic_value (0)
// #define max_word_length (10000)
class branch_string
{

public:
    branch_string(const char *_data) : m_data(_data, strlen(_data)) {}
    branch_string(const std::string &_data) : m_data(_data) {}
    branch_string(const std::string_view &_data) : m_data(_data) {}
    operator bool() const { return m_data.size(); }
    uint64_t operator()()
    {
        uint64_t value = magic_value;
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

    uint64_t peek(size_t pos) const
    {
        if (pos < (m_data.size() / sizeof(uint64_t)))
        {
            return *((uint64_t *)(m_data.data()) + pos);
        }
        else if ((pos == (m_data.size() / sizeof(uint64_t))) && ((m_data.size() % sizeof(uint64_t)) != 0))
        {
            uint64_t value = magic_value;
            auto offset = pos * sizeof(uint64_t);
            strncpy((char *)&value, m_data.data() + offset, m_data.size() - offset);
            return value;
        }
        return magic_value;
    }

private:
    std::string_view m_data;
};