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
#include <vector>
#include <cstdint>
#include <list>
#include <string>
#include <tuple>
#include <map>

namespace reflect
{

    class analyzer
    {
    public:
        struct info_t
        {
            std::string m_variant;
            std::string m_raw_variant;
            std::string m_raw_type;
            std::list<std::string> m_input;
            std::string m_output;
            uint64_t m_value = 0;
            uint32_t m_flags = 0;
            uint32_t m_t_flags = 0;
            uint32_t m_field = 0;
        };

        struct config_t
        {
            std::vector<uint32_t> m_max_index;
            uint32_t m_max_field = 0;
            void clear()
            {
                m_max_index.clear();
                m_max_field = 0;
            }
        };

    public:
        analyzer();

        analyzer &init(config_t *_config);

        void push_back(const std::string &variant)
        {
            info_t detail;
            push_back_view(variant, detail);
        }
        void push_back(const std::string &variant, const info_t &detail)
        {
            push_back_view(variant, detail);
        }
        void push_back_view(const std::string &variant, const info_t &detail);

        void copy_view(const std::string &variant, const info_t &detail);

        bool get_prefect_index(int index) const;

        uint64_t calc_perfect_index() const;

        auto &get_data() { return m_data; }
        auto get_config() { return m_config; }

    private:
        void __push_back_view(const std::string &variant, const info_t &detail);

        config_t *m_config;
        // std::multimap<std::string, info_t> m_data;
        std::map<std::string, info_t> m_data;
    };
}