#pragma once
#include <stdint.h>
#include <string>
#include <map>
#include <vector>

namespace ashan
{
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
    char* l;
    const char* m;
    std::map<int,int> n;
    std::vector<int> o;

};
struct node
{
    int x;
    float y;
    double z;    
    base h;
    
};
}