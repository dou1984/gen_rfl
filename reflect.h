#pragma once

namespace reflect
{
    struct info
    {
        void* pointer;
        const char* type;
        int field;
        info(void* p, const char* t, int f) : pointer(p), type(t), field(f){}
    };
}