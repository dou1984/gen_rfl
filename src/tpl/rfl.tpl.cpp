#include <string>
#include "tpl.h"

const std::string rfl_tpl = R"(
#pragma once
#include "base_types.h"
{{#indices}}#include "{{header}}"
{{/indices}}
)";
namespace tpl
{
    const std::string &rfl()
    {
        return rfl_tpl;
    }   
}