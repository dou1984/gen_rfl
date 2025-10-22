
# gen_rfl

gen_rfl 是一个 C++ 反射代码生成工具，通过运行它可为 C++ 类自动生成反射函数。借助这些反射函数，能够快速读取或修改结构体的成员变量。

**gen_rfl生成的是O1复杂度的反射代码**


## gen_rfl优势

1. 所有元数据都在编译时生成和初始化，零运行时开销的编译时反射。
``` cpp
static meta<base> g_base_meta[] = {
    {
        .m_variant = "a",
        .m_type = "signed char",
        .m_flags = 0x80001,
        .m_field = e__base__a,
        .m_member = [](const base *c) -> const void * { 
            return std::addressof(static_cast<const base*>(c)->a);
        },
    },    
};
```

2. 连续内存存储所有元数据，缓存友好的内存布局。
``` cpp
static meta<base> g_base_meta[] = {    
    { /* a */ },
    { /* b */ },
    { /* c */ }, 
    ...
};
```

3. 智能的跳转表分发系统，无函数调用开销，O(1)时间复杂度的字段查找。
``` cpp
constexpr void *__meta_label[] = { &&label_0_0, &&label_0_1, ... };
auto value = tag();
auto index = value % count;
goto *__meta_label[index];  
label_0_0:
    return ...;
```

4. 运行时类型检查，类型安全的成员访问。
``` cpp
void *get_value(const base *cls, const std::string &_tag, const char *expected_type)
{    
    return (strcmp(expected_type, _meta.m_type) == 0) ? ... : nullptr;
}
```


5. 支持复杂数据结构，原生支持STL容器和自定义类型。
``` cpp
{
    .m_variant = "n",
    .m_type = "std::map<int, int>",
    .m_flags = 0x80001,
    .m_field = e__base__n,
    .m_member = [](const base *c) -> const void * { 
        return std::addressof(static_cast<const base*>(c)->n);
    },
}
```

# 适用场景
1. 高性能序列化/反序列化
2. 游戏引擎属性系统
3. 数据库ORM映射
4. 网络协议处理
5. 配置系统

## 运行环境

| lib              | version  |
| ---------------- | -------- |
| libctemplate-dev | 2.4-1    |
| libctemplate3    | 2.4-1    |
| llvm-15-dev      | 1:15.0.7 |
| llvm-15          | 1:15.0.7 |

# 构建与安装

执行./build.sh

