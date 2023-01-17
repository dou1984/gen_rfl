#pragma once
#include <cstring>

namespace reflect
{
    struct info
    {
        const void *pointer;
        const char *type;
        int field;
        info(const void *p, const char *t, int f) : pointer(p), type(t), field(f) {}
    };
}