#include <string>
#include "tpl.h"

const std::string func_leaf_tpl = R"(
static {{class}}_func g_{{class}}_L{{layer}}_I{{index}}_P{{position}}[] = {
{{#indices}}    rfl_L{{layer}}_I{{index}},
{{/indices}}
};
)";

namespace tpl
{
    const std::string &func_leaf()
    {
        return func_leaf_tpl;
    }
}