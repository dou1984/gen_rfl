cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_FIND_LIBRARY_SUFFIXES .a .so)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CXX_FLAGS}")

option(ALPINE "Enable ALPINE support" OFF)

if (ALPINE)
set(LLVM_DIR /usr/lib/llvm18/lib/cmake/llvm)
set(Clang_DIR /usr/lib/llvm18/lib/cmake/clang)
set(CMAKE_IGNORE_IMPORT_LIBRARY ON)
set(LLVM_NO_STATIC_LIBRARIES ON)
set(LLVM_INCLUDE_TESTS OFF)
set(LLVM_BUILD_TESTS OFF)
add_definitions(-DALPINE=1)
else ()
set(LLVM_DIR /usr/lib/llvm-15/lib/cmake/llvm)
set(Clang_DIR /usr/lib/llvm-15/lib/cmake/clang)
set(CLANG_LIBRARY_DIRS
    "/usr/lib/llvm-15/lib"
    "/usr/lib/llvm-15/lib/x86_64-linux-gnu"
    "/usr/lib/x86_64-linux-gnu/llvm-15/lib"
)
endif()

project(gen_rfl)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)
find_package(GTest REQUIRED)
find_package(gflags REQUIRED)
find_package(yaml-cpp REQUIRED)

include_directories(
    ${LLVM_INCLUDE_DIRS}
    ${CLANG_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDE_DIR}
)

link_directories(${LLVM_LIBRARY_DIRS})
link_directories(${CLANG_LIBRARY_DIRS})

file(GLOB ALL_CPP_FILES "*.cpp" "tpl/*.cpp")
list(FILTER ALL_CPP_FILES EXCLUDE REGEX "_test\\.cpp$")
# list(FILTER ALL_CPP_FILES EXCLUDE REGEX "build\/.*.cpp$")

add_executable(${PROJECT_NAME}
    ${ALL_CPP_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ctemplate
    clangTooling    
    yaml-cpp
    gflags  
)

if (!ALPINE)

enable_testing()
add_executable(unit_test
    gen_rfl.cpp
    license.cpp
    branch_string_test.cpp
    analyzer_test.cpp
    analyzer.cpp
    branch_test.cpp
    branch.cpp
    format_tpl_test.cpp
    format_tpl.cpp
    filter.cpp
    config.cpp
    sys.cpp
    sys_test.cpp
)
target_link_libraries(unit_test PRIVATE
    GTest::GTest
    GTest::Main
    ctemplate
    clangTooling
    yaml-cpp
)
add_test(NAME unit_test COMMAND branch)

endif()

install(
FILES
    reflect.h
    branch_string.h
    set_variant.h
    set_value.h
    setter.h
    value.h
    arguments.h  
    config_src.h 
    DESTINATION include/gen_rfl
)
install(
    FILES
    tpl/header.tpl
    tpl/func.tpl
    tpl/meta.tpl
    tpl/get_meta.tpl
    tpl/rfl.tpl
    tpl/invoke.tpl
    tpl/invoke_field.tpl
    tpl/invoke_layer.tpl
    tpl/base_types_source.tpl
    tpl/base_types.tpl
    DESTINATION include/gen_rfl/tpl
)
install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
