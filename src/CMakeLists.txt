cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(LLVM_DIR /usr/lib/llvm-15/lib/cmake/llvm)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CXX_FLAGS}")
set(CLANG_LIBRARY_DIRS
    "/usr/lib/llvm-15/lib"
    "/usr/lib/llvm-15/lib/x86_64-linux-gnu"
    "/usr/lib/x86_64-linux-gnu/llvm-15/lib"
)
set(Clang_DIR /usr/lib/llvm-15/lib/cmake/clang)

project(gen_rfl)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)
find_package(GTest REQUIRED)
find_package(gflags REQUIRED)

include_directories(
    ${LLVM_INCLUDE_DIRS}
    ${CLANG_INCLUDE_DIRS}
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
    gflags
    ${LLVM_LIBRARIES}
)

enable_testing()

add_executable(unit_test
    gen_rfl.cpp
    branch_string_test.cpp
    analyzer_test.cpp
    analyzer.cpp
    branch_test.cpp
    branch.cpp
    format_tpl_test.cpp
    format_tpl.cpp
    filter.cpp
    tpl/base_types.cpp
    tpl/header.tpl.cpp
    tpl/func.tpl.cpp
    tpl/meta.tpl.cpp
    tpl/get_meta.tpl.cpp
    tpl/rfl.tpl.cpp
    tpl/invoke.tpl.cpp
    config.cpp
    sys.cpp
    sys_test.cpp

)

target_link_libraries(unit_test PRIVATE
    GTest::GTest
    GTest::Main
    ctemplate
    clangTooling
)

add_test(NAME unit_test COMMAND branch)

install(
    FILES
    reflect.h
    branch_string.h
    DESTINATION include/gen_rfl

)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
