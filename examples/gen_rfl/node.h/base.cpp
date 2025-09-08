
#include <stdint.h>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "../../node.h"

using namespace reflect;
using base_func = meta &(*)(const base *, branch_string &, uint64_t);

enum base_meta_enum
{
    
    e_base_h,
    e_base_a,
    e_base_b,
    e_base_c,
    e_base_d,
    e_base_e,
    e_base_f,
    e_base_g,
    e_base_i,
    e_base_j,
    e_base_k,
    e_base_l,
    e_base_m,
    e_base_n,
    e_base_o,
    e_base_end,
};
static meta g_meta = {
    .m_variant = "",
    .m_type = "",
    .m_raw_type = "",
    .m_flags = __flags(flag_none),
    .m_field = UINT64_MAX,
    .m_offset = UINT64_MAX,
};
static meta g_base_meta[] = {

    {
        .m_variant = "h",
        .m_type = "uint64_t",
        .m_raw_type = "unsigned long",
        .m_flags = 0,
        .m_field = e_base_h,
        .m_offset = _offsetof(&base::h),        
    },
    {
        .m_variant = "a",
        .m_type = "int8_t",
        .m_raw_type = "signed char",
        .m_flags = 0,
        .m_field = e_base_a,
        .m_offset = _offsetof(&base::a),        
    },
    {
        .m_variant = "b",
        .m_type = "int16_t",
        .m_raw_type = "short",
        .m_flags = 0,
        .m_field = e_base_b,
        .m_offset = _offsetof(&base::b),        
    },
    {
        .m_variant = "c",
        .m_type = "int32_t",
        .m_raw_type = "int",
        .m_flags = 0,
        .m_field = e_base_c,
        .m_offset = _offsetof(&base::c),        
    },
    {
        .m_variant = "d",
        .m_type = "int64_t",
        .m_raw_type = "long",
        .m_flags = 0,
        .m_field = e_base_d,
        .m_offset = _offsetof(&base::d),        
    },
    {
        .m_variant = "e",
        .m_type = "uint8_t",
        .m_raw_type = "unsigned char",
        .m_flags = 0,
        .m_field = e_base_e,
        .m_offset = _offsetof(&base::e),        
    },
    {
        .m_variant = "f",
        .m_type = "uint16_t",
        .m_raw_type = "unsigned short",
        .m_flags = 0,
        .m_field = e_base_f,
        .m_offset = _offsetof(&base::f),        
    },
    {
        .m_variant = "g",
        .m_type = "uint32_t",
        .m_raw_type = "unsigned int",
        .m_flags = 0,
        .m_field = e_base_g,
        .m_offset = _offsetof(&base::g),        
    },
    {
        .m_variant = "i",
        .m_type = "float",
        .m_raw_type = "float",
        .m_flags = 0,
        .m_field = e_base_i,
        .m_offset = _offsetof(&base::i),        
    },
    {
        .m_variant = "j",
        .m_type = "double",
        .m_raw_type = "double",
        .m_flags = 0,
        .m_field = e_base_j,
        .m_offset = _offsetof(&base::j),        
    },
    {
        .m_variant = "k",
        .m_type = "std::string",
        .m_raw_type = "std::string",
        .m_flags = 0,
        .m_field = e_base_k,
        .m_offset = _offsetof(&base::k),        
    },
    {
        .m_variant = "l",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_base_l,
        .m_offset = _offsetof(&base::l),        
    },
    {
        .m_variant = "m",
        .m_type = "const char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_base_m,
        .m_offset = _offsetof(&base::m),        
    },
    {
        .m_variant = "n",
        .m_type = "std::map<int, int>",
        .m_raw_type = "std::map<int, int>",
        .m_flags = 0,
        .m_field = e_base_n,
        .m_offset = _offsetof(&base::n),        
    },
    {
        .m_variant = "o",
        .m_type = "std::vector<int>",
        .m_raw_type = "std::vector<int>",
        .m_flags = 0,
        .m_field = e_base_o,
        .m_offset = _offsetof(&base::o),        
    },
};

inline meta &__meta(base_func *arr, int count, const base *cls, branch_string& b)
{  
    if (b)
    {
        auto value = b();
        auto index = value % count;
        return (arr[index])(cls, b, value);
    }
    return g_meta;
}

inline meta &rfl_L0_I0(const base *cls, branch_string &str, uint64_t value)
{
    if (0x69 == value)
    { 
        return g_base_meta[e_base_i];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I1(const base *cls, branch_string &str, uint64_t value)
{
    if (0x6a == value)
    { 
        return g_base_meta[e_base_j];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I2(const base *cls, branch_string &str, uint64_t value)
{
    if (0x6b == value)
    { 
        return g_base_meta[e_base_k];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I3(const base *cls, branch_string &str, uint64_t value)
{
    if (0x6c == value)
    { 
        return g_base_meta[e_base_l];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I4(const base *cls, branch_string &str, uint64_t value)
{
    if (0x6d == value)
    { 
        return g_base_meta[e_base_m];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I5(const base *cls, branch_string &str, uint64_t value)
{
    if (0x6e == value)
    { 
        return g_base_meta[e_base_n];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I6(const base *cls, branch_string &str, uint64_t value)
{
    if (0x6f == value)
    { 
        return g_base_meta[e_base_o];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I7(const base *cls, branch_string &str, uint64_t value)
{
    if (0x61 == value)
    { 
        return g_base_meta[e_base_a];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I8(const base *cls, branch_string &str, uint64_t value)
{
    if (0x62 == value)
    { 
        return g_base_meta[e_base_b];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I9(const base *cls, branch_string &str, uint64_t value)
{
    if (0x63 == value)
    { 
        return g_base_meta[e_base_c];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I10(const base *cls, branch_string &str, uint64_t value)
{
    if (0x64 == value)
    { 
        return g_base_meta[e_base_d];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I11(const base *cls, branch_string &str, uint64_t value)
{
    if (0x65 == value)
    { 
        return g_base_meta[e_base_e];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I12(const base *cls, branch_string &str, uint64_t value)
{
    if (0x66 == value)
    { 
        return g_base_meta[e_base_f];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I13(const base *cls, branch_string &str, uint64_t value)
{
    if (0x67 == value)
    { 
        return g_base_meta[e_base_g];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I14(const base *cls, branch_string &str, uint64_t value)
{
    if (0x68 == value)
    { 
        return g_base_meta[e_base_h];
    }
    
    return g_meta;
}

static base_func g_base_L0[] = {
    rfl_L0_I0,
    rfl_L0_I1,
    rfl_L0_I2,
    rfl_L0_I3,
    rfl_L0_I4,
    rfl_L0_I5,
    rfl_L0_I6,
    rfl_L0_I7,
    rfl_L0_I8,
    rfl_L0_I9,
    rfl_L0_I10,
    rfl_L0_I11,
    rfl_L0_I12,
    rfl_L0_I13,
    rfl_L0_I14,

};

meta& get_meta(const base *cls, const std::string &tag)
{
    branch_string b(tag);
    auto count = countof(g_base_L0);
    return __meta(g_base_L0, count, cls, b);
}
void* get_value(const base *cls, const std::string &tag)
{
    return ((char *)cls + get_meta(cls, tag).m_offset);
}
void* get_value(const base *cls, const char* tag)
{ 
    return ((char *)cls + get_meta(cls, std::string(tag)).m_offset);
}
const char* get_type(const base *cls, const std::string &tag)
{
    return get_meta(cls, tag).m_type;
}
const char* get_type(const base *cls, const char* tag) 
{
    return get_meta(cls, std::string(tag)).m_type;    
}
const char *get_type(const base *cls)
{
    static const char _class[] = "base";
    return _class;
}
uint64_t get_field(const base *cls, const std::string &tag)
{
    return get_meta(cls, tag).m_field;  
}
uint64_t get_field(const base *cls, const char* tag)
{
    return get_meta(cls, std::string(tag)).m_field;  
}
uint64_t get_field_max(const base *cls)
{
    return countof(g_base_L0);
}
