cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_FIND_LIBRARY_SUFFIXES .a .so)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

project(gen_rfl)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

find_package(GTest REQUIRED)
find_package(gflags REQUIRED)
find_package(yaml-cpp REQUIRED)

include_directories(
    ${YAML_CPP_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/third-party/tree-sitter/lib/include
    ${CMAKE_SOURCE_DIR}/third-party/tree-sitter-cpp/src
    ${CMAKE_SOURCE_DIR}/third-party/tree-sitter-cpp/bindings/c
)

file(GLOB ALL_CPP_FILES "*.cpp")
list(FILTER ALL_CPP_FILES EXCLUDE REGEX "_test\.cpp$")
list(FILTER ALL_CPP_FILES EXCLUDE REGEX "tree_sitter_api_stub\.cpp$")

add_executable(${PROJECT_NAME}
    ${ALL_CPP_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ctemplate
    yaml-cpp
    gflags
    tree-sitter
    tree-sitter-cpp
)

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
    yaml-cpp
    ctemplate
)
add_test(NAME unit_test COMMAND branch)

install(
    FILES
    reflect.h
    reflect_def.h
    branch_string.h
    set_variant.h
    set_value.h
    setter.h
    value.h
    item.h
    invoke.h
    arguments.h
    config_src.h 
    DESTINATION include/gen_rfl
)
install(
    FILES
    tpl/header.tpl
    tpl/header.hpp.tpl
    tpl/func.tpl
    tpl/meta.tpl
    tpl/get_meta.tpl
    tpl/rfl.tpl
    tpl/invoke.tpl
    tpl/invoke_field.tpl
    tpl/base_types_source.tpl
    tpl/base_types.tpl
    DESTINATION include/gen_rfl/tpl
)
install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
