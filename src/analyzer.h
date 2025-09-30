#pragma once
#include <vector>
#include <cstdint>
#include <list>
#include <string>
#include <tuple>

class analyzer
{
public:
    struct param_t
    {
        // std::string m_input;
        std::list<std::string> m_input;
        std::string m_output;
    };
    struct info_t
    {
        std::string m_variant;
        uint64_t m_value;
        std::string m_raw_variant;
        std::string m_type;
        std::string m_raw_type;
        uint64_t m_field = 0;
        uint64_t m_flags = 0;
        std::list<param_t> m_params;
    };
    struct config_t
    {
        std::string m_file;
        std::string m_relative_file;
        std::string m_class;
        std::string m_raw_class;
        std::string m_namespace;
        std::vector<uint32_t> m_max_index;
        void clear()
        {
            m_file.clear();
            m_relative_file.clear();
            m_raw_class.clear();
            m_class.clear();
            m_namespace.clear();
            m_max_index.clear();
        }
    };

public:
    analyzer();
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

    auto &get_data()
    {
        return m_data;
    }
    static auto &get_config()
    {
        return m_config;
    }
    static int generate_file_name(std::string &header, std::string &source, std::string &_header);
    static bool is_generated(std::string &header, std::string &source);

private:
    void __push_back_view(const std::string &variant, const info_t &detail);

    static config_t m_config;
    // std::vector<info_t> m_data;
    std::map<std::string, info_t> m_data;
};
