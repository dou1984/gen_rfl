#pragma once

#include <typeinfo>
#include <vector>
#include <string>
#include <memory>

#define TYPE(CLS, C, X, V) typeid(C.X).name()
#define ADDR(CLS, C, X, V) (void *)std::addressof(C.X)
#define FIELD(CLS, C, X, V) (int)CLS##_field_##X
#define NAME(CLS, C, X, V) #X
#define INFO(CLS, C, X, V) info(ADDR(CLS, C, X, 0), TYPE(CLS, C, X, 0), FIELD(CLS, C, X, 0))
#define SETV(CLS, C, X, V) (C.X = V)
#define Reflect0(CLS)                                         \
    const char *get_type_0(const CLS &, const char *, void *) \
    {                                                         \
        return "";                                            \
    }                                                         \
    void *get_pointer_0(const CLS &, const char *, void *)    \
    {                                                         \
        return NULL;                                          \
    }                                                         \
    int get_field_0(const CLS &, const char *, void *)        \
    {                                                         \
        return -1;                                            \
    }                                                         \
    info get_info_0(const CLS &, const char *, void *)        \
    {                                                         \
        return info(0, "", -1);                               \
    }                                                         \
    int set_value_0(const CLS &, const char *, void *)        \
    {                                                         \
        return 0;                                             \
    }
#define ReflectFunc(MET, FUN, CLS, X, Y)                     \
    auto MET##X(const CLS &cls, const char *argu, void *val) \
    {                                                        \
        if (strcmp(#X, argu) == 0)                           \
            return FUN(CLS, cls, X, val);                    \
        else                                                 \
            return MET##Y(cls, argu, val);                   \
    }
#define ReflectMethod1(MET, FUN, CLS, X) \
    ReflectFunc(MET, FUN, CLS, X, 0);
#define ReflectMethod2(MET, FUN, CLS, X, Y) \
    ReflectFunc(MET, FUN, CLS, Y, 0);       \
    ReflectFunc(MET, FUN, CLS, X, Y);
#define ReflectMethod3(MET, FUN, CLS, X, Y, Z) \
    ReflectFunc(MET, FUN, CLS, Z, 0);          \
    ReflectFunc(MET, FUN, CLS, Y, Z);          \
    ReflectFunc(MET, FUN, CLS, X, Y);
#define ReflectMethod4(MET, FUN, CLS, X, Y, Z)               \
    auto MET##Y(const CLS &cls, const char *argu, void *val) \
    {                                                        \
        auto r = strcmp(#Y, argu);                           \
        if (r > 0)                                           \
        {                                                    \
            return MET##X(cls, argu, val);                   \
        }                                                    \
        else if (r < 0)                                      \
        {                                                    \
            return MET##Z(cls, argu, val);                   \
        }                                                    \
        else                                                 \
        {                                                    \
            return FUN(CLS, cls, Y, val);                    \
        }                                                    \
    }
#define ReflectX(CLS, N, ...)                              \
    ReflectMethod##N(get_type_, TYPE, CLS, __VA_ARGS__);   \
    ReflectMethod##N(get_info_, INFO, CLS, __VA_ARGS__);   \
    ReflectMethod##N(get_field_, FIELD, CLS, __VA_ARGS__); \
    ReflectMethod##N(get_pointer_, ADDR, CLS, __VA_ARGS__)
#define Reflect(CLS, X)                                    \
    const char *get_type(const CLS &cls, const char *argu) \
    {                                                      \
        return get_type_##X(cls, argu, 0);                 \
    }                                                      \
    void *get_pointer(const CLS &cls, const char *argu)    \
    {                                                      \
        return get_pointer_##X(cls, argu, 0);              \
    }                                                      \
    int get_field(const CLS &cls, const char *argu)        \
    {                                                      \
        return get_field_##X(cls, argu, 0);                \
    }                                                      \
    info get_info(const CLS &cls, const char *argu)        \
    {                                                      \
        return get_info_##X(cls, argu, 0);                 \
    }
#define ReflectField(MET, FUN, CLS, X) \
    auto MET##X(const CLS &cls)        \
    {                                  \
        return FUN(CLS, cls, X, 0);       \
    }
#define FieldX(CLS, X)                         \
    ReflectField(field_member_, NAME, CLS, X); \
    ReflectField(field_type_, TYPE, CLS, X);   \
    ReflectField(field_pointer_, ADDR, CLS, X);

template <class T>
struct reflectfield
{
    using t = const char *(*)(const T &);
    using p = void *(*)(const T &);
    using m = const char *(*)(const T &);
    std::vector<t> _type;
    std::vector<p> _pointer;
    std::vector<m> _member;
};