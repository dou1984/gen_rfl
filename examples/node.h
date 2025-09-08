#pragma once
#include <stdint.h>
#include <string>
#include <map>
#include <vector>
#include <sys/types.h> // 定义 time_t
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
    char *oooooo24;
};

void init();