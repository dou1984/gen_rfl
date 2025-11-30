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
#pragma once
#include <stdint.h>
#include <string>
#include <map>
#include <vector>
#include <sys/types.h>
#include <time.h>

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

struct config
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
};
