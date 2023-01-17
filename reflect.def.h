#pragma once

#include <typeinfo>
#include <vector>
#include <string>
#include <memory>

#define TYPE(CLS, C, X) typeid(C.X).name()
#define ADDR(CLS, C, X) (const void *)&C.X
#define FIELD(CLS, C, X) (int)CLS##_field_##X
#define NAME(CLS, C, X) #X
#define INFO(CLS, C, X) info(ADDR(CLS, C, X), TYPE(CLS, C, X), FIELD(CLS, C, X))
#define Reflect0(CLS)                                    \
    const char *get_type_0(const CLS &, const char *)    \
    {                                                    \
        return "";                                       \
    }                                                    \
    const void *get_pointer_0(const CLS &, const char *) \
    {                                                    \
        return NULL;                                     \
    }                                                    \
    int get_field_0(const CLS &, const char *)           \
    {                                                    \
        return -1;                                       \
    }                                                    \
    info get_info_0(const CLS &, const char *)           \
    {                                                    \
        return info(0, "", -1);                          \
    }
#define ReflectFun(MET, FUN, CLS, X, Y)           \
    auto MET##X(const CLS &cls, const char *argu) \
    {                                             \
        if (strcmp(#X, argu) == 0)                \
            return FUN(CLS, cls, X);              \
        else                                      \
            return MET##Y(cls, argu);             \
    }
#define ReflectMethod1(MET, FUN, CLS, X) \
    ReflectFun(MET, FUN, CLS, X, 0);
#define ReflectMethod2(MET, FUN, CLS, X, Y) \
    ReflectFun(MET, FUN, CLS, Y, 0);        \
    ReflectFun(MET, FUN, CLS, X, Y);
#define ReflectMethod3(MET, FUN, CLS, X, Y, Z) \
    ReflectFun(MET, FUN, CLS, Z, 0);           \
    ReflectFun(MET, FUN, CLS, Y, Z);           \
    ReflectFun(MET, FUN, CLS, X, Y);
#define ReflectMethod4(MET, FUN, CLS, X, Y, Z)    \
    auto MET##Y(const CLS &cls, const char *argu) \
    {                                             \
        auto r = strcmp(#Y, argu);                \
        if (r > 0)                                \
        {                                         \
            return MET##X(cls, argu);             \
        }                                         \
        else if (r < 0)                           \
        {                                         \
            return MET##Z(cls, argu);             \
        }                                         \
        else                                      \
        {                                         \
            return FUN(CLS, cls, Y);              \
        }                                         \
    }
#define ReflectX(CLS, N, ...)                              \
    ReflectMethod##N(get_type_, TYPE, CLS, __VA_ARGS__);   \
    ReflectMethod##N(get_info_, INFO, CLS, __VA_ARGS__);   \
    ReflectMethod##N(get_field_, FIELD, CLS, __VA_ARGS__); \
    ReflectMethod##N(get_pointer_, ADDR, CLS, __VA_ARGS__);
#define Reflect(CLS, X)                                       \
    const char *get_type(const CLS &cls, const char *argu)    \
    {                                                         \
        return get_type_##X(cls, argu);                       \
    }                                                         \
    const void *get_pointer(const CLS &cls, const char *argu) \
    {                                                         \
        return get_pointer_##X(cls, argu);                    \
    }                                                         \
    int get_field(const CLS &cls, const char *argu)           \
    {                                                         \
        return get_field_##X(cls, argu);                      \
    }                                                         \
    info get_info(const CLS &cls, const char *argu)           \
    {                                                         \
        return get_info_##X(cls, argu);                       \
    }

#define ReflectField(MET, FUN, CLS, X) \
    auto MET##X(const CLS &cls)        \
    {                                  \
        return FUN(CLS, cls, X);       \
    }
#define FieldX(CLS, X)                         \
    ReflectField(field_member_, NAME, CLS, X); \
    ReflectField(field_type_, TYPE, CLS, X);   \
    ReflectField(field_pointer_, ADDR, CLS, X);

template <class T>
struct reflectfield
{
    using t = const char *(*)(const T &);
    using p = const void *(*)(const T &);
    using m = const char *(*)(const T &);
    std::vector<t> _type;
    std::vector<p> _pointer;
    std::vector<m> _member;
};
