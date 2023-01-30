#pragma once

#include <typeinfo>
#include <vector>
#include <string>
#include <type_traits>

#define TYPE(CLS, C, X, V) typeid(C.X).name()
#define ADDR(CLS, C, X, V) (void *)(&C.X)
#define FIELD(CLS, C, X, V) (int)(CLS##_field_##X)
#define NAME(CLS, C, X, V) (#X)
#define INFO(CLS, C, X, V) info(ADDR(CLS, C, X, V), TYPE(CLS, C, X, V), FIELD(CLS, C, X, V))
#define SETV(CLS, C, X, V) strcmp(TYPE(CLS, C, X, V), V->type) == 0 ? [&]() -> int { C.X = *((decltype(C.X) *)(V->pointer)); return 0; }() : -1
#define Reflect0(CLS)                                   \
    const char *get_type_0(CLS &, const char *, info *) \
    {                                                   \
        return "";                                      \
    }                                                   \
    void *get_pointer_0(CLS &, const char *, info *)    \
    {                                                   \
        return NULL;                                    \
    }                                                   \
    int get_field_0(CLS &, const char *, info *)        \
    {                                                   \
        return -1;                                      \
    }                                                   \
    info get_info_0(CLS &, const char *, info *)        \
    {                                                   \
        return info(0, "", -1);                         \
    }                                                   \
    int set_value_0(CLS &, const char *, info *)        \
    {                                                   \
        return -1;                                      \
    }
#define ReflectF(MTH, FUN, CLS, X, Y)                  \
    auto MTH##X(CLS &cls, const char *argu, info *obj) \
    {                                                  \
        if (strcmp(#X, argu) == 0)                     \
        {                                              \
            return FUN(CLS, cls, X, obj);              \
        }                                              \
        else                                           \
        {                                              \
            return MTH##Y(cls, argu, obj);             \
        }                                              \
    }
#define ReflectMethod1(MTH, FUN, CLS, X) \
    ReflectF(MTH, FUN, CLS, X, 0);
#define ReflectMethod2(MTH, FUN, CLS, X, Y) \
    ReflectF(MTH, FUN, CLS, Y, 0);          \
    ReflectF(MTH, FUN, CLS, X, Y);
#define ReflectMethod3(MTH, FUN, CLS, X, Y, Z) \
    ReflectF(MTH, FUN, CLS, Z, 0);             \
    ReflectF(MTH, FUN, CLS, Y, Z);             \
    ReflectF(MTH, FUN, CLS, X, Y);
#define ReflectMethod4(MTH, FUN, CLS, X, Y, Z)         \
    auto MTH##Y(CLS &cls, const char *argu, info *obj) \
    {                                                  \
        auto r = strcmp(#Y, argu);                     \
        if (r > 0)                                     \
        {                                              \
            return MTH##X(cls, argu, obj);             \
        }                                              \
        else if (r < 0)                                \
        {                                              \
            return MTH##Z(cls, argu, obj);             \
        }                                              \
        else                                           \
        {                                              \
            return FUN(CLS, cls, Y, obj);              \
        }                                              \
    }
#define ReflectX(CLS, N, ...)                               \
    ReflectMethod##N(get_type_, TYPE, CLS, __VA_ARGS__);    \
    ReflectMethod##N(get_info_, INFO, CLS, __VA_ARGS__);    \
    ReflectMethod##N(get_field_, FIELD, CLS, __VA_ARGS__);  \
    ReflectMethod##N(get_pointer_, ADDR, CLS, __VA_ARGS__); \
    ReflectMethod##N(set_value_, SETV, CLS, __VA_ARGS__);
#define Reflect(CLS, X)                                  \
    const char *get_type(CLS &cls, const char *argu)     \
    {                                                    \
        return get_type_##X(cls, argu, 0);               \
    }                                                    \
    void *get_pointer(CLS &cls, const char *argu)        \
    {                                                    \
        return get_pointer_##X(cls, argu, 0);            \
    }                                                    \
    int get_field(CLS &cls, const char *argu)            \
    {                                                    \
        return get_field_##X(cls, argu, 0);              \
    }                                                    \
    info get_info(CLS &cls, const char *argu)            \
    {                                                    \
        return get_info_##X(cls, argu, 0);               \
    }                                                    \
    int set_value(CLS &cls, const char *argu, info *obj) \
    {                                                    \
        return set_value_##X(cls, argu, obj);            \
    }
#define ReflectField(MTH, FUN, CLS, X) \
    auto MTH##X(CLS &cls)              \
    {                                  \
        return FUN(CLS, cls, X, 0);    \
    }
#define FieldX(CLS, X)                         \
    ReflectField(field_member_, NAME, CLS, X); \
    ReflectField(field_type_, TYPE, CLS, X);   \
    ReflectField(field_pointer_, ADDR, CLS, X);
template <class T>
struct reflectfield
{
    using t = const char *(*)(T &);
    using p = void *(*)(T &);
    using m = const char *(*)(T &);
    std::vector<t> _type;
    std::vector<p> _pointer;
    std::vector<m> _member;
};
