#pragma once
#include <stdint.h>
#include <string>
#include <map>
#include <vector>
#include <sys/types.h>
#include <time.h>

struct base
{
    uint64_t h;
    int8_t a;
    int16_t b;
    int32_t c;
    int64_t d;
    uint8_t e;
    uint16_t f;
    uint32_t g;
    float i;
    double j;
    std::string k;
    char *l;
    const char *m;
    std::map<int, int> n;
    std::vector<int> o;
    const char *ooooooooooooooooooooooooooooo0;
};

struct node : base
{

    char *oooooooooooooooooooooooooo0;
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
    static char *oooooo25;
    int init(int, const char *);
    int init(float, double, const char *);
    int init();
    int deinit();
    int lllllllllllllllllllllllllll0(const char *, const char *);
    int lllllllllllllllllllllllllll1(const char *, const char *);
    int lllllllllllllllllllllllllll2(const char *, const char *);
    int lllllllllllllllllllllllllll3(const char *, const char *);
    int lllllllllllllllllllllllllll4(const char *, const char *);
    int lllllllllllllllllllllllllll5(const std::string &, const std::string &);
};

struct func
{
    int init();
    int deinit();
    void done();
};