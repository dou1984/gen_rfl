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
#include <cassert>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include "travel_src.tree_sitter.cpp"

using namespace reflect::tree_sitter_cpp;

bool create_test_file(const std::string &filename, const std::string &content)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to create test file: " << filename << std::endl;
        return false;
    }
    file << content;
    file.close();
    return true;
}

bool delete_test_file(const std::string &filename)
{
    return remove(filename.c_str()) == 0;
}

void test_basic_class_parsing()
{
    std::cout << "Testing basic class parsing..." << std::endl;

    std::string test_code = R"(
class TestClass {
public:
    int public_field;
    void public_method(int x, int y);
    
private:
    std::string private_field;
    void private_method();
    
protected:
    double protected_field;
};
)";

    std::string test_file = "/tmp/test_class.cpp";
    assert(create_test_file(test_file, test_code));

    Parser parser;
    assert(parser.parse_file(test_file));

    std::vector<ClassInfo> classes;
    parser.extract_classes(classes);

    assert(classes.size() == 1);
    assert(classes[0].name == "TestClass");
    assert(classes[0].raw_name == "class TestClass");
    assert(classes[0].fields.size() == 3);
    assert(classes[0].methods.size() == 2);

    std::cout << "  ✓ Class name: " << classes[0].name << std::endl;
    std::cout <<  "  ✓ Fields count: " << classes[0].fields.size() << std::endl;
    std::cout << "  ✓ Methods count: " << classes[0].methods.size() << std::endl;

    assert(delete_test_file(test_file));
    std::cout << "Basic class parsing test passed!" << std::endl;
}

void test_struct_parsing()
{
    std::cout << "Testing struct parsing..." << std::endl;

    std::string test_code = R"(
struct TestStruct {
    int x;
    int y;
    float value;
};
)";

    std::string test_file = "/tmp/test_struct.cpp";
    assert(create_test_file(test_file, test_code));

    Parser parser;
    assert(parser.parse_file(test_file));

    std::vector<ClassInfo> classes;
    parser.extract_classes(classes);

    assert(classes.size() == 1);
    assert(classes[0].name == "TestStruct");
    assert(classes[0].raw_name == "struct TestStruct");
    assert(classes[0].fields.size() == 3);

    std::cout << "  ✓ Struct name: " << classes[0].name << std::endl;
    std::cout << "  ✓ Fields count: " << classes[0].fields.size() << std::endl;

    assert(delete_test_file(test_file));
    std::cout << "Struct parsing test passed!" << std::endl;
}

void test_union_parsing()
{
    std::cout << "Testing union parsing..." << std::endl;

    std::string test_code = R"(
union TestUnion {
    int i;
    float f;
    double d;
};
)";

    std::string test_file = "/tmp/test_union.cpp";
    assert(create_test_file(test_file, test_code));

    Parser parser;
    assert(parser.parse_file(test_file));

    std::vector<ClassInfo> classes;
    parser.extract_classes(classes);

    assert(classes.size() == 1);
    assert(classes[0].name == "TestUnion");
    assert(classes[0].raw_name == "union TestUnion");

    std::cout << "  ✓ Union name: " << classes[0].name << std::endl;

    assert(delete_test_file(test_file));
    std::cout << "Union parsing test passed!" << std::endl;
}

void test_inheritance()
{
    std::cout << "Testing inheritance parsing..." << std::endl;

    std::string test_code = R"(
class Base {
    int base_field;
};

class Derived : public Base {
    int derived_field;
};
)";

    std::string test_file = "/tmp/test_inheritance.cpp";
    assert(create_test_file(test_file, test_code));

    Parser parser;
    assert(parser.parse_file(test_file));

    std::vector<ClassInfo> classes;
    parser.extract_classes(classes);

    assert(classes.size() == 2);
    
    auto derived = std::find_if(classes.begin(), classes.end(),
                                [](const ClassInfo &c) { return c.name == "Derived"; });
    assert(derived != classes.end());
    assert(derived->base_classes.size() == 1);
    assert(derived->base_classes[0] == "Base");

    std::cout << "  ✓ Derived class: " << derived->name << std::endl;
    std::cout << "  ✓ Base class: " << derived->base_classes[0] << std::endl;

    assert(delete_test_file(test_file));
    std::cout << "Inheritance parsing test passed!" << std::endl;
}

void test_method_parameters()
{
    std::cout << "Testing method parameters parsing..." << std::endl;

    std::string test_code = R"(
class TestClass {
public:
    void method1(int a, std::string b, double c);
    int method2(float x);
    void method3();
};
)";

    std::string test_file = "/tmp/test_methods.cpp";
    assert(create_test_file(test_file, test_code));

    Parser parser;
    assert(parser.parse_file(test_file));

    std::vector<ClassInfo> classes;
    parser.extract_classes(classes);

    assert(classes.size() == 1);
    assert(classes[0].methods.size() == 3);

    std::cout << "  ✓ Methods count: " << classes[0].methods.size() << std::endl;

    assert(delete_test_file(test_file));
    std::cout << "Method parameters parsing test passed!" << std::endl;
}

void test_type_extraction()
{
    std::cout << "Testing type extraction..." << std::endl;

    std::string type1 = "const std::string&";
    std::string result1 = extract_type_name(type1);
    assert(result1 == "std::string");
    std::cout << "  ✓ const std::string& -> " << result1 << std::endl;

    std::string type2 = "class MyClass";
    std::string result2 = extract_type_name(type2);
    assert(result2 == "MyClass");
    std::cout << "  ✓ class MyClass -> " << result2 << std::endl;

    std::string type3 = "struct MyStruct";
    std::string result3 = extract_type_name(type3);
    assert(result3 == "MyStruct");
    std::cout << "  ✓ struct MyStruct -> " << result3 << std::endl;

    std::string type4 = "int";
    std::string result4 = extract_type_name(type4);
    assert(result4 == "int");
    std::cout << "  ✓ int -> " << result4 << std::endl;

    std::cout << "Type extraction test passed!" << std::endl;
}

int main()
{
    std::cout << "=== Tree-sitter C++ Parser Tests ===" << std::endl;
    std::cout << std::endl;

    try
    {
        test_type_extraction();
        std::cout << std::endl;

        test_basic_class_parsing();
        std::cout << std::endl;

        test_struct_parsing();
        std::cout << std::endl;

        test_union_parsing();
        std::cout << std::endl;

        test_inheritance();
        std::cout << std::endl;

        test_method_parameters();
        std::cout << std::endl;

        std::cout << "=== All tests passed! ===" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
}
