#include <string>
#include "tpl.h"

const std::string func_root_tpl = R"(
static {{class}}_func g_{{class}}_L{{layer}}[] = {
{{#indices}}    rfl_L{{layer}}_I{{index}},
{{/indices}}
};
)";

namespace tpl
{
    const std::string &func_root()
    {
        return func_root_tpl;
    }
}
