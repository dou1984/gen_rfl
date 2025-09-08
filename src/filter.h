#pragma once
#include <string>
#include <functional>

namespace reflect
{
    using filter = std::function<bool(const std::string &file)>;

    filter get_filter();

    filter get_rfl_filter();

}