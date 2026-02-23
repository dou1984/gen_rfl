cmake_minimum_required(VERSION 3.10)

project(performance_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(GEN_RFL_DIR ${CMAKE_SOURCE_DIR}/gen_rfl)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(${PROJECT_NAME}
    performance_test.cpp
    node.cpp
    gen_rfl/base_types.cpp
    gen_rfl/node_rfl/node.cpp
)

link_directories(${GEN_RFL_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${GEN_RFL_DIR})
