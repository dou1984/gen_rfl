cmake_minimum_required(VERSION 3.10)

project(main)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# 设置 CMP0079 策略为 NEW，允许跨目录链接
cmake_policy(SET CMP0079 NEW)

# 编译 tree-sitter 和 tree-sitter-cpp 为静态库
set(BUILD_SHARED_LIBS OFF)

# 编译 tree-sitter 为静态库
add_subdirectory(third-party/tree-sitter)

# 编译 tree-sitter-cpp 为静态库
add_subdirectory(third-party/tree-sitter-cpp)

include_directories(
    third-party/tree-sitter/lib/include
    third-party/tree-sitter-cpp/src
    third-party/tree-sitter-cpp/bindings/c
)

add_subdirectory(src)
