#include "config.h"

Conf &get_config()
{
    static Conf conf;
    return conf;
}