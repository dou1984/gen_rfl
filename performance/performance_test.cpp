// Copyright (c) 2023-2025 Zhao Yun Shan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include <iostream>
#include <chrono>

#include "node.h"
#include "gen_rfl/rfl.h"

using namespace reflect;
using namespace std::chrono;

int performance_test()
{
    std::cout << "\n=== Performance Test ===" << std::endl;

    // Test set_value performance
    {
        node b = {0};
        const int iterations = 1000000;
        const char *test_str = "test";

        auto start = high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i)
        {
            set_value(&b, "oooo19", test_str);
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start).count();
        std::cout << "set_value performance: " << iterations << " iterations in " << duration << "ms" << std::endl;
    }

    // Test get_value performance
    {
        node b = {0};
        const int iterations = 1000000;

        auto start = high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i)
        {
            auto value = get_value(&b, "oooo19");
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start).count();
        std::cout << "get_value performance: " << iterations << " iterations in " << duration << "ms" << std::endl;
    }

    // Test invoke performance
    {
        node n;
        const int iterations = 1000000;

        auto start = high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i)
        {
            invoke(&n, "init");
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start).count();
        std::cout << "invoke performance: " << iterations << " iterations in " << duration << "ms" << std::endl;
    }

    // Test for_each performance
    {
        node n = {0};
        const int iterations = 100000;

        auto start = high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i)
        {
            for_each(&n, [](auto &base, auto &key, auto &value)
                     {
                         // Do nothing, just iterate
                     });
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start).count();
        std::cout << "for_each performance: " << iterations << " iterations in " << duration << "ms" << std::endl;
    }

    return 0;
}

int main()
{
    performance_test();
    return 0;
}
