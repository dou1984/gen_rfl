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
#include <list>
#include <map>
#include <set>
#include <vector>
#include <array>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

const std::string &get_type(char * *);
const std::string &get_type(const char * *);
const std::string &get_type(const double *);
const std::string &get_type(const float *);
const std::string &get_type(const int *);
const std::string &get_type(const long *);
const std::string &get_type(const short *);
const std::string &get_type(const signed char *);
const std::string &get_type(const std::map<int, int> *);
const std::string &get_type(const std::string *);
const std::string &get_type(const std::vector<int> *);
const std::string &get_type(const unsigned char *);
const std::string &get_type(const unsigned int *);
const std::string &get_type(const unsigned long *);
const std::string &get_type(const unsigned short *);
const std::string &get_type(double *);
const std::string &get_type(float *);
const std::string &get_type(int *);
const std::string &get_type(long *);
const std::string &get_type(short *);
const std::string &get_type(signed char *);
const std::string &get_type(std::map<int, int> *);
const std::string &get_type(std::string *);
const std::string &get_type(std::vector<int> *);
const std::string &get_type(unsigned char *);
const std::string &get_type(unsigned int *);
const std::string &get_type(unsigned long *);
const std::string &get_type(unsigned short *);
void* get_field_value(std::map<int, int> *cls, uint32_t field);
void* get_field_value(std::vector<int> *cls, uint32_t field);

