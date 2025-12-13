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
#include <string>
#include <string_view>
#include <typeinfo>
#include <cassert>
#include <functional>
#include <gen_rfl/value.h>
#include <gen_rfl/branch_string.h>
#include <gen_rfl/reflect.h>
#include "../base_types.h"
#include "priv_opts.h"

namespace reflect
{
    using ::priv_opts;
    using ::options;
    namespace details
    {
        meta<options> &get_meta(const options *cls, branch_string& tag);    
        meta<options> &get_func(const options *cls, branch_string& tag, const std::list<Item> &argu_item);
        int get_base_func(const options *cls, const std::string_view& tag, const Arguments *_, ...);
    }
    Value get_value(const options *cls, const char *tag);
    Value get_value(const options *cls, const std::string &tag);
    Value get_field_value(const options *cls, uint32_t field);
    const std::string &get_type(const options *cls, const std::string &tag);
    const std::string &get_type(const options *cls, const char *tag);
    const std::string &get_type(options *cls);
    const std::string &get_type(const options *cls);
    const std::string &get_type(options **cls);
    const std::string &get_type(const options **cls);
    const std::string &get_typeid(const options *cls, const std::string &tag);
    const std::string &get_typeid(const options *cls);
    const std::string &get_field_type(const options *cls, uint32_t field);
    uint64_t get_field(const options *cls, const std::string &tag);
    uint64_t get_field(const options *cls, const char *tag);
    const uint64_t get_fields_count(const options *cls);
    const std::string &get_name(const options *cls, uint32_t field);
    
    int for_each(const options *cls, const std::function<void(const std::string &, const std::string &, const Value &)> &);
   
}
