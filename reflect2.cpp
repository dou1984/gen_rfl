// C++26 Native Reflection Example
// Replicating gen_rfl's Perfect Hash Algorithm with Flat Recursive Jump Table
// Private Static Member Implementation (Clean & Robust)

#include <algorithm>
#include <array>
#include <cassert>
#include <meta>
#include <print>
#include <ranges>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>
#include<map>

struct base
{
    int8_t a;
    int16_t b;
    int32_t c;
    int64_t d;
    uint8_t e;
    uint16_t f;
    uint32_t g;
    uint64_t h;
    float i;
    double j;
    std::string k;
    char *l;
    const char *m;
    std::map<int, int> n;
    std::vector<int> o;
    const char *ooooooooooooooooooooooooooool0;

    int64_t add(int64_t, int64_t);
};
struct priv_opts
{
    int opts = 0;
};
struct options : priv_opts
{
    bool status = true;
    bool is_running = true;
    bool is_stop = false;
    bool is_suspend = false;
};
struct config : options
{
    int64_t o0;
    int64_t o1;
    int64_t o2;
    int64_t o3;
};
struct func
{
    int _init();
    int _deinit();
    void _done();
};
struct node : base, config, func
{
    const char *oooooooooooooooooooooooooo0;
    char *oooooooooooooooooooooooooo1;
    char *oooooooooooooooooooooooooo2;
    char *oooooooooooooooooooooooooo3;
    char *oooooooooooooooooooooooooo4;
    char *oooooooooooooooooooooooooo5;
    char *ooooooooooooooooooooooo6;
    char *ooooooooooooooo7;
    char *oooooooooooooo8;
    char *ooooooooo9;
    char *oooooooo10;
    char *oooooooo11;
    char *oooooooooooooo12;
    char *ooooooooooooooooooooooooooo13;
    char *oooooooooooooooooooooooooo14;
    char *ooooooooooooooooooooooooooo15;
    char *ooooooooooooooooooooo16;
    char *ooooooooooooooo17;
    char *oooooooooooooo18;
    char *oooo19;
    char *oooo20;
    char *oooooo21;
    char *oooooo22;
    char *oooooo23;
    const char *oooooo24;
    static const char *oooooo25;
    int init(int, long long, const char *);
    int init(float, double, const char *);
    int init();
    int deinit();
    int lllllllllllllllllllllllllll0(const char *, const char *);
    int lllllllllllllllllllllllllll1(const char *, const char *);
    int lllllllllllllllllllllllllll2(const char *, const char *);
    int lllllllllllllllllllllllllll3(const char *, const char *);
    int lllllllllllllllllllllllllll4(const char *, const char *);
    int lllllllllllllllllllllllllll5(const std::string &, const std::string &);
    int lllllllllllllllllllllllllll6(std::string &, std::string &);
    int lllllllllllllllllllllllllll6(std::string &);

    int set(base *);
    int set(config &);
};

// C++26 Native Reflection Example
// Replicating gen_rfl's Perfect Hash Algorithm with Flat Recursive Jump Table
// Private Static Member Implementation (Clean & Robust)


namespace reflect {

    namespace impl {

        // Recursive helper to collect members in vector
        consteval auto get_members_of(std::meta::info type) -> std::vector<std::meta::info> {
            std::vector<std::meta::info> members;
            for (auto base: std::meta::bases_of(type, std::meta::access_context::current())) {
                members.append_range(get_members_of(std::meta::type_of(base)));
            }
            members.append_range(nonstatic_data_members_of(type, std::meta::access_context::current()));
            return members;
        }

        template<typename T>
        static constexpr auto members_of_t = std::define_static_array(get_members_of(^^T));

        constexpr uint64_t get_hash_u64(std::string_view sv) {
            uint64_t value = 0;
            size_t len = sv.size() < 8 ? sv.size() : 8;
            for (size_t i = 0; i < len; ++i) {
                value |= static_cast<uint64_t>(static_cast<uint8_t>(sv[i])) << (i * 8);
            }
            return value;
        }

        constexpr uint64_t get_hash_and_remove_prefix(std::string_view& sv) {
            uint64_t value = get_hash_u64(sv);
            size_t len = sv.size() < 8 ? sv.size() : 8;
            sv.remove_prefix(len);
            return value;
        }

        struct Node {
            uint64_t value = 0;
            int member_index = -1;
            int next_offset = 0;
            size_t next_modulus = 0;
        };

        // MetaTable: The Single Source of Truth
        template<class T>
        struct MetaTable {
            static constexpr auto members = std::define_static_array(get_members_of(^^T));

            static consteval auto get_initial_items() {
                // Returns a range of identifier strings
                return members_of_t<T> | std::views::transform(std::meta::identifier_of) |
                       std::ranges::to<std::vector>();
            }

            static consteval auto get_initial_items_with_idx() {
                return std::views::zip(std::views::iota(0), get_initial_items()) | std::ranges::to<std::vector>();
            }

            // Helper: Find perfect modulus for a set of unique hashes
            static constexpr size_t find_perfect_modulus(const std::vector<uint64_t>& unique_hashes) {
                size_t modulus = (unique_hashes.size() / 5) | 1;
                while (true) {
                    bool col = false;
                    for (size_t i = 0; i < unique_hashes.size(); ++i)
                        for (size_t j = i + 1; j < unique_hashes.size(); ++j)
                            if (unique_hashes[i] % modulus == unique_hashes[j] % modulus) {
                                col = true;
                                break;
                            }
                    if (!col || modulus > 100000)
                        return modulus > 100000 ? 100000 : modulus;
                    modulus += 2;
                }
            }

            // --- Internal Recursive Logic (Hidden from global scope) ---

            static constexpr size_t ROOT_MODULUS = []() {
                auto items = get_initial_items();
                if (items.empty())
                    return (size_t) 1;
                std::vector<uint64_t> hashes;
                for (auto sv: items) {
                    if (!sv.empty())
                        hashes.push_back(get_hash_u64(sv));
                }
                std::sort(hashes.begin(), hashes.end());
                hashes.erase(std::unique(hashes.begin(), hashes.end()), hashes.end());
                return MetaTable<T>::find_perfect_modulus(hashes);
            }();

            static consteval size_t count_recursive(auto&& current_items) {
                if (current_items.empty())
                    return 0;

                std::vector<std::tuple<uint64_t, std::string_view>> hashed_items;
                std::vector<uint64_t> unique_hashes;

                for (auto sv: current_items) {
                    if (sv.empty())
                        continue;
                    uint64_t h = get_hash_u64(sv);
                    hashed_items.push_back({h, sv});
                    unique_hashes.push_back(h);
                }

                if (unique_hashes.empty())
                    return 0;
                std::sort(unique_hashes.begin(), unique_hashes.end());
                unique_hashes.erase(std::unique(unique_hashes.begin(), unique_hashes.end()), unique_hashes.end());

                size_t modulus = find_perfect_modulus(unique_hashes);
                size_t total = modulus;

                std::vector<std::vector<std::string_view>> buckets(modulus);
                for (const auto& [h, sv]: hashed_items) {
                    std::string_view next_sv = sv;
                    size_t len = next_sv.size() < 8 ? next_sv.size() : 8;
                    next_sv.remove_prefix(len);
                    buckets[h % modulus].push_back(next_sv);
                }

                for (const auto& bucket: buckets) {
                    if (!bucket.empty())
                        total += count_recursive(bucket);
                }
                return total;
            }

            template<size_t N>
            static consteval void fill_recursive(auto&& current_items, std::array<Node, N>& arr, size_t& alloc_ptr,
                                                 int parent_node_idx) {
                if (current_items.empty())
                    return;

                // Use tuple<Hash, Index, StringView>
                std::vector<std::tuple<uint64_t, int, std::string_view>> hashed_items;
                std::vector<uint64_t> unique_hashes;

                for (const auto& [idx, sv]: current_items) {
                    if (sv.empty())
                        continue;
                    uint64_t h = get_hash_u64(sv);
                    hashed_items.push_back({h, idx, sv});
                    unique_hashes.push_back(h);
                }

                if (unique_hashes.empty())
                    return;
                std::sort(unique_hashes.begin(), unique_hashes.end());
                unique_hashes.erase(std::unique(unique_hashes.begin(), unique_hashes.end()), unique_hashes.end());

                size_t modulus = find_perfect_modulus(unique_hashes);

                size_t my_offset = alloc_ptr;
                alloc_ptr += modulus;
                if (parent_node_idx != -1) {
                    arr[parent_node_idx].next_offset = static_cast<int>(my_offset);
                    arr[parent_node_idx].next_modulus = modulus;
                }

                // Recursion buckets: vector of tuple<int, string_view>
                std::vector<std::vector<std::tuple<int, std::string_view>>> buckets(modulus);

                for (const auto& [h, idx, sv]: hashed_items) {
                    size_t slot = h % modulus;
                    size_t node_idx = my_offset + slot;

                    arr[node_idx].value = h;
                    if (sv.size() <= 8)
                        arr[node_idx].member_index = idx;

                    std::string_view next_sv = sv;
                    size_t len = next_sv.size() < 8 ? next_sv.size() : 8;
                    next_sv.remove_prefix(len);
                    buckets[slot].push_back({idx, next_sv});
                }

                for (size_t i = 0; i < modulus; ++i) {
                    if (!buckets[i].empty())
                        fill_recursive(buckets[i], arr, alloc_ptr, static_cast<int>(my_offset + i));
                }
            }

            static constexpr size_t TABLE_SIZE = count_recursive(get_initial_items());

            static constexpr std::array<Node, TABLE_SIZE> table = []() {
                std::array<Node, TABLE_SIZE> arr{};
                size_t alloc_ptr = 0;
                fill_recursive(get_initial_items_with_idx(), arr, alloc_ptr, -1);
                return arr;
            }();

            static constexpr auto names = []() {
                std::array<std::string_view, members.size()> arr;
                for (size_t i = 0; i < members.size(); ++i)
                    arr[i] = identifier_of(members[i]);
                return arr;
            }();
        };

        template<class T>
        int find_member_impl(std::string_view name) {
            using Table = MetaTable<T>;
            std::string_view current_sv = name;
            int current_offset = 0;
            size_t current_modulus = Table::ROOT_MODULUS;

            while (true) {
                uint64_t val = get_hash_and_remove_prefix(current_sv);
                size_t slot = val % current_modulus;
                if (current_offset + slot >= Table::TABLE_SIZE)
                    return -1;

                const auto& node = Table::table[current_offset + slot];
                if (node.value != val)
                    return -1;

                if (node.next_offset != 0) {
                    current_offset = node.next_offset;
                    current_modulus = node.next_modulus;
                    continue;
                } else if (node.member_index != -1) {
                    if (Table::names[node.member_index] == name)
                        return node.member_index;
                    return -1;
                } else {
                    return -1;
                }
            }
        }

    } // namespace impl

    // ... Public API ...

    template<class T>
    int find_member(std::string_view name) {
        return impl::find_member_impl<T>(name);
    }

    template<class T>
    consteval std::size_t get_fields_count() {
        return impl::members_of_t<T>.size();
    }

    template<class T>
    auto get_value(T& obj, std::string_view name) {
        std::string result;
        int idx = find_member<T>(name);
        if (idx != -1) {
            int i = 0;
            template for (constexpr auto member: impl::members_of_t<T>) {
                if (i == idx) {
                    using MemberType = [:std::meta::type_of(member):];
                    if constexpr (std::is_arithmetic_v<MemberType>)
                        result = std::to_string(obj.[:member:]);
                    else if constexpr (std::is_same_v<MemberType, std::string>)
                        result = obj.[:member:];
                    else if constexpr (std::is_same_v<MemberType, const char*> || std::is_same_v<MemberType, char*>)
                        if (obj.[:member:])
                            result = obj.[:member:];
                }
                ++i;
            }
        }
        return result;
    }

    template<class T, class V>
    int set_value(T& obj, std::string_view name, V&& value) {
        int idx = find_member<T>(name);
        if (idx != -1) {
            int i = 0;
            template for (constexpr auto member: impl::members_of_t<T>) {
                if (i == idx) {
                    using MemberType = [:std::meta::type_of(member):];
                    if constexpr (std::is_assignable_v<MemberType&, V>) {
                        obj.[:member:] = std::forward<V>(value);
                        return 0;
                    }
                }
                ++i;
            }
        }
        return -1;
    }

    template<class T, class F>
    void for_each(T& obj, F&& callback) {
        template for (constexpr auto member: impl::members_of_t<T>) {
            callback(std::string_view(identifier_of(member)), get_value(obj, identifier_of(member)));
        }
    }

} // namespace reflect

// ============================================================
// Tests
// ============================================================

void test_set_base() {
    using namespace reflect;
    // std::println("=== test_set_base (using node) ===");
    node b{};
    set_value(b, "a", static_cast<int8_t>(10));
    set_value(b, "b", static_cast<int16_t>(20));
    set_value(b, "c", static_cast<int32_t>(30));
    set_value(b, "d", static_cast<int64_t>(40));
    assert(b.a == 10);
    assert(b.b == 20);
    assert(b.c == 30);
    assert(b.d == 40);
    // std::println("  b.a = {} (expected 10)", b.a);
    // std::println("  All assertions passed!");
}

void test_get_value() {
    using namespace reflect;
    // std::println("=== test_get_value (using node) ===");
    node b{};
    b.a = 1;
    b.k = "hello";
    // std::println("  find_member(a) index: {}", find_member<node>("a"));
    // std::println("  get_value(b, \"a\") = {}", get_value(b, "a"));
    // std::println("  get_value(b, \"k\") = {}", get_value(b, "k"));
    volatile auto v1 = get_value(b, "a");
    volatile auto v2 = get_value(b, "k");
    (void) v1;
    (void) v2;
}

void test_for_each() {
    using namespace reflect;
    // std::println("=== test_for_each (using node) ===");
    node b{};
    b.a = 100;
    b.b = 200;
    int count = 0;
    for_each(b, [&](std::string_view name, std::string value) {
        if (!value.empty() && value != "0") {
            // std::println("  {} = {}", name, value);
            count++;
        }
    });
}

void test_fields_count() {
    using namespace reflect;
    // std::println("=== test_fields_count (using node) ===");
    constexpr auto count = get_fields_count<node>();
    (void) count;
    // std::println("  node has {} fields (base + own)", count);
}

void test_dump_table() {
    // using namespace reflect;
    // std::println("=== test_dump_table (node) ===");
    // using Table = impl::MetaTable<node>;

    // std::println("Table Size: {} nodes", Table::TABLE_SIZE);
    // std::println("Root Modulus: {}", Table::ROOT_MODULUS);

    // for (size_t i = 0; i < Table::TABLE_SIZE; ++i) {
    //     const auto& node = Table::table[i];
    //     if (node.value == 0 && node.member_index == -1 && node.next_offset == 0) {
    //         continue;
    //     }

    //     std::print("[{:3}] Hash:{:016x} ", i, node.value);

    //     if (node.next_offset != 0) {
    //         std::println("-> JUMP offset={} mod={}", node.next_offset, node.next_modulus);
    //     } else if (node.member_index != -1) {
    //         std::println("-> LEAF member='{}' (idx={})", Table::names[node.member_index], node.member_index);
    //     } else {
    //         std::println("-> EMPTY/UNKNOWN");
    //     }
    // }
}

int main() {
    // std::println("C++26 Native Reflection Test (Single File, Inlined Lambda)\n");
    test_set_base();
    // std::println("");
    test_get_value();
    // std::println("");
    test_for_each();
    // std::println("");
    test_fields_count();
    // std::println("");
    test_dump_table(); // Now does nothing
    // std::println("\nAll tests passed!");
    return 0;
}
