
#include <stdint.h>
#include <gen_rfl/reflect.h>
#include <gen_rfl/branch_string.h>
#include "../../node.h"

using namespace reflect;
using node_func = meta &(*)(const node *, branch_string &, uint64_t);

enum node_meta_enum
{
    
    e_node_base,
    e_node_oooooooooooooooooooooooooo0,
    e_node_oooooooooooooooooooooooooo1,
    e_node_oooooooooooooooooooooooooo2,
    e_node_oooooooooooooooooooooooooo3,
    e_node_oooooooooooooooooooooooooo4,
    e_node_oooooooooooooooooooooooooo5,
    e_node_ooooooooooooooooooooooo6,
    e_node_ooooooooooooooo7,
    e_node_oooooooooooooo8,
    e_node_ooooooooo9,
    e_node_oooooooo10,
    e_node_oooooooo11,
    e_node_oooooooooooooo12,
    e_node_ooooooooooooooooooooooooooo13,
    e_node_oooooooooooooooooooooooooo14,
    e_node_ooooooooooooooooooooooooooo15,
    e_node_ooooooooooooooooooooo16,
    e_node_ooooooooooooooo17,
    e_node_oooooooooooooo18,
    e_node_oooo19,
    e_node_oooo20,
    e_node_oooooo21,
    e_node_oooooo22,
    e_node_oooooo23,
    e_node_oooooo24,
    e_node_end,
};
static meta g_meta = {
    .m_variant = "",
    .m_type = "",
    .m_raw_type = "",
    .m_flags = __flags(flag_none),
    .m_field = UINT64_MAX,
    .m_offset = UINT64_MAX,
};
static meta g_node_meta[] = {

    {
        .m_variant = "base",
        .m_type = "base",
        .m_raw_type = "base",
        .m_flags = 4096,
        .m_field = e_node_base,
        .m_offset = _offsetof<node, base>(),        
    },
    {
        .m_variant = "oooooooooooooooooooooooooo0",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooooooooooooooo0,
        .m_offset = _offsetof(&node::oooooooooooooooooooooooooo0),        
    },
    {
        .m_variant = "oooooooooooooooooooooooooo1",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooooooooooooooo1,
        .m_offset = _offsetof(&node::oooooooooooooooooooooooooo1),        
    },
    {
        .m_variant = "oooooooooooooooooooooooooo2",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooooooooooooooo2,
        .m_offset = _offsetof(&node::oooooooooooooooooooooooooo2),        
    },
    {
        .m_variant = "oooooooooooooooooooooooooo3",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooooooooooooooo3,
        .m_offset = _offsetof(&node::oooooooooooooooooooooooooo3),        
    },
    {
        .m_variant = "oooooooooooooooooooooooooo4",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooooooooooooooo4,
        .m_offset = _offsetof(&node::oooooooooooooooooooooooooo4),        
    },
    {
        .m_variant = "oooooooooooooooooooooooooo5",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooooooooooooooo5,
        .m_offset = _offsetof(&node::oooooooooooooooooooooooooo5),        
    },
    {
        .m_variant = "ooooooooooooooooooooooo6",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_ooooooooooooooooooooooo6,
        .m_offset = _offsetof(&node::ooooooooooooooooooooooo6),        
    },
    {
        .m_variant = "ooooooooooooooo7",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_ooooooooooooooo7,
        .m_offset = _offsetof(&node::ooooooooooooooo7),        
    },
    {
        .m_variant = "oooooooooooooo8",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooo8,
        .m_offset = _offsetof(&node::oooooooooooooo8),        
    },
    {
        .m_variant = "ooooooooo9",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_ooooooooo9,
        .m_offset = _offsetof(&node::ooooooooo9),        
    },
    {
        .m_variant = "oooooooo10",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooo10,
        .m_offset = _offsetof(&node::oooooooo10),        
    },
    {
        .m_variant = "oooooooo11",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooo11,
        .m_offset = _offsetof(&node::oooooooo11),        
    },
    {
        .m_variant = "oooooooooooooo12",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooo12,
        .m_offset = _offsetof(&node::oooooooooooooo12),        
    },
    {
        .m_variant = "ooooooooooooooooooooooooooo13",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_ooooooooooooooooooooooooooo13,
        .m_offset = _offsetof(&node::ooooooooooooooooooooooooooo13),        
    },
    {
        .m_variant = "oooooooooooooooooooooooooo14",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooooooooooooooo14,
        .m_offset = _offsetof(&node::oooooooooooooooooooooooooo14),        
    },
    {
        .m_variant = "ooooooooooooooooooooooooooo15",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_ooooooooooooooooooooooooooo15,
        .m_offset = _offsetof(&node::ooooooooooooooooooooooooooo15),        
    },
    {
        .m_variant = "ooooooooooooooooooooo16",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_ooooooooooooooooooooo16,
        .m_offset = _offsetof(&node::ooooooooooooooooooooo16),        
    },
    {
        .m_variant = "ooooooooooooooo17",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_ooooooooooooooo17,
        .m_offset = _offsetof(&node::ooooooooooooooo17),        
    },
    {
        .m_variant = "oooooooooooooo18",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooooooooooo18,
        .m_offset = _offsetof(&node::oooooooooooooo18),        
    },
    {
        .m_variant = "oooo19",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooo19,
        .m_offset = _offsetof(&node::oooo19),        
    },
    {
        .m_variant = "oooo20",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooo20,
        .m_offset = _offsetof(&node::oooo20),        
    },
    {
        .m_variant = "oooooo21",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooo21,
        .m_offset = _offsetof(&node::oooooo21),        
    },
    {
        .m_variant = "oooooo22",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooo22,
        .m_offset = _offsetof(&node::oooooo22),        
    },
    {
        .m_variant = "oooooo23",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooo23,
        .m_offset = _offsetof(&node::oooooo23),        
    },
    {
        .m_variant = "oooooo24",
        .m_type = "char *",
        .m_raw_type = "char",
        .m_flags = 0,
        .m_field = e_node_oooooo24,
        .m_offset = _offsetof(&node::oooooo24),        
    },
};

inline meta &__meta(node_func *arr, int count, const node *cls, branch_string& b)
{  
    if (b)
    {
        auto value = b();
        auto index = value % count;
        return (arr[index])(cls, b, value);
    }
    return g_meta;
}

inline meta &rfl_L0_I0(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

inline meta &rfl_L0_I1(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

inline meta &rfl_L0_I2(const node *cls, branch_string &str, uint64_t value)
{
    if (0x33326f6f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_oooooo23];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I3(const node *cls, branch_string &str, uint64_t value)
{
    if (0x31326f6f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_oooooo21];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I4(const node *cls, branch_string &str, uint64_t value)
{
    if (0x39316f6f6f6f == value)
    { 
        return g_node_meta[e_node_oooo19];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I5(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

inline meta &rfl_L1_I0(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

inline meta &rfl_L2_I0(const node *cls, branch_string &str, uint64_t value)
{
    if (0x37 == value)
    { 
        return g_node_meta[e_node_ooooooooooooooo17];
    }
    
    return g_meta;
}

static node_func g_node_L2_I1_P1[] = {
    rfl_L2_I0,

};

inline meta &rfl_L1_I1(const node *cls, branch_string &str, uint64_t value)
{
    if (0x316f6f6f6f6f6f6f == value)
    { 
        return __meta(g_node_L2_I1_P1, countof(g_node_L2_I1_P1), cls, str);
    }
    
    return g_meta;
}

inline meta &rfl_L1_I2(const node *cls, branch_string &str, uint64_t value)
{
    if (0x3131 == value)
    { 
        return g_node_meta[e_node_oooooooo11];
    }
    if (0x386f6f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooo8];
    }
    
    return g_meta;
}

inline meta &rfl_L1_I3(const node *cls, branch_string &str, uint64_t value)
{
    if (0x38316f6f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooo18];
    }
    
    return g_meta;
}

inline meta &rfl_L1_I4(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

inline meta &rfl_L1_I5(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

inline meta &rfl_L3_I0(const node *cls, branch_string &str, uint64_t value)
{
    if (0x306f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooooooooooooooo0];
    }
    if (0x35316f6f6f == value)
    { 
        return g_node_meta[e_node_ooooooooooooooooooooooooooo15];
    }
    
    return g_meta;
}

inline meta &rfl_L3_I1(const node *cls, branch_string &str, uint64_t value)
{
    if (0x346f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooooooooooooooo4];
    }
    if (0x33316f6f6f == value)
    { 
        return g_node_meta[e_node_ooooooooooooooooooooooooooo13];
    }
    
    return g_meta;
}

inline meta &rfl_L3_I2(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

inline meta &rfl_L3_I3(const node *cls, branch_string &str, uint64_t value)
{
    if (0x336f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooooooooooooooo3];
    }
    
    return g_meta;
}

inline meta &rfl_L3_I4(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

inline meta &rfl_L3_I5(const node *cls, branch_string &str, uint64_t value)
{
    if (0x326f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooooooooooooooo2];
    }
    if (0x34316f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooooooooooooooo14];
    }
    
    return g_meta;
}

inline meta &rfl_L3_I6(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

inline meta &rfl_L3_I7(const node *cls, branch_string &str, uint64_t value)
{
    if (0x316f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooooooooooooooo1];
    }
    
    return g_meta;
}

inline meta &rfl_L3_I8(const node *cls, branch_string &str, uint64_t value)
{
    if (0x356f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooooooooooooooo5];
    }
    
    return g_meta;
}

static node_func g_node_L3_I1_P1[] = {
    rfl_L3_I0,
    rfl_L3_I1,
    rfl_L3_I2,
    rfl_L3_I3,
    rfl_L3_I4,
    rfl_L3_I5,
    rfl_L3_I6,
    rfl_L3_I7,
    rfl_L3_I8,

};

inline meta &rfl_L2_I1(const node *cls, branch_string &str, uint64_t value)
{
    if (0x366f6f6f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_ooooooooooooooooooooooo6];
    }
    if (0x6f6f6f6f6f6f6f6f == value)
    { 
        return __meta(g_node_L3_I1_P1, countof(g_node_L3_I1_P1), cls, str);
    }
    
    return g_meta;
}

inline meta &rfl_L2_I2(const node *cls, branch_string &str, uint64_t value)
{
    if (0x36316f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_ooooooooooooooooooooo16];
    }
    
    return g_meta;
}

inline meta &rfl_L2_I3(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

static node_func g_node_L2_I6_P1[] = {
    rfl_L2_I1,
    rfl_L2_I2,
    rfl_L2_I3,

};

inline meta &rfl_L1_I6(const node *cls, branch_string &str, uint64_t value)
{
    if (0x396f == value)
    { 
        return g_node_meta[e_node_ooooooooo9];
    }
    if (0x32316f6f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_oooooooooooooo12];
    }
    if (0x6f6f6f6f6f6f6f6f == value)
    { 
        return __meta(g_node_L2_I6_P1, countof(g_node_L2_I6_P1), cls, str);
    }
    
    return g_meta;
}

inline meta &rfl_L1_I7(const node *cls, branch_string &str, uint64_t value)
{
    if (0x3031 == value)
    { 
        return g_node_meta[e_node_oooooooo10];
    }
    if (0x376f6f6f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_ooooooooooooooo7];
    }
    
    return g_meta;
}

inline meta &rfl_L1_I8(const node *cls, branch_string &str, uint64_t value)
{
    
    return g_meta;
}

static node_func g_node_L1_I6_P1[] = {
    rfl_L1_I0,
    rfl_L1_I1,
    rfl_L1_I2,
    rfl_L1_I3,
    rfl_L1_I4,
    rfl_L1_I5,
    rfl_L1_I6,
    rfl_L1_I7,
    rfl_L1_I8,

};

inline meta &rfl_L0_I6(const node *cls, branch_string &str, uint64_t value)
{
    if (0x65736162 == value)
    { 
        return g_node_meta[e_node_base];
    }
    if (0x34326f6f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_oooooo24];
    }
    if (0x6f6f6f6f6f6f6f6f == value)
    { 
        return __meta(g_node_L1_I6_P1, countof(g_node_L1_I6_P1), cls, str);
    }
    
    return g_meta;
}

inline meta &rfl_L0_I7(const node *cls, branch_string &str, uint64_t value)
{
    if (0x32326f6f6f6f6f6f == value)
    { 
        return g_node_meta[e_node_oooooo22];
    }
    
    return g_meta;
}

inline meta &rfl_L0_I8(const node *cls, branch_string &str, uint64_t value)
{
    if (0x30326f6f6f6f == value)
    { 
        return g_node_meta[e_node_oooo20];
    }
    
    return g_meta;
}

static node_func g_node_L0[] = {
    rfl_L0_I0,
    rfl_L0_I1,
    rfl_L0_I2,
    rfl_L0_I3,
    rfl_L0_I4,
    rfl_L0_I5,
    rfl_L0_I6,
    rfl_L0_I7,
    rfl_L0_I8,

};

meta& get_meta(const node *cls, const std::string &tag)
{
    branch_string b(tag);
    auto count = countof(g_node_L0);
    return __meta(g_node_L0, count, cls, b);
}
void* get_value(const node *cls, const std::string &tag)
{
    return ((char *)cls + get_meta(cls, tag).m_offset);
}
void* get_value(const node *cls, const char* tag)
{ 
    return ((char *)cls + get_meta(cls, std::string(tag)).m_offset);
}
const char* get_type(const node *cls, const std::string &tag)
{
    return get_meta(cls, tag).m_type;
}
const char* get_type(const node *cls, const char* tag) 
{
    return get_meta(cls, std::string(tag)).m_type;    
}
const char *get_type(const node *cls)
{
    static const char _class[] = "node";
    return _class;
}
uint64_t get_field(const node *cls, const std::string &tag)
{
    return get_meta(cls, tag).m_field;  
}
uint64_t get_field(const node *cls, const char* tag)
{
    return get_meta(cls, std::string(tag)).m_field;  
}
uint64_t get_field_max(const node *cls)
{
    return countof(g_node_L0);
}
