cmake_minimum_required(VERSION 3.10)

project(exe_node)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(GEN_RFL_DIR ${CMAKE_SOURCE_DIR}/gen_rfl)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(EXAMPLE_SOURCES
    main.cpp
    node.cpp
)

set(GEN_RFL_GENERATED_SOURCES
    gen_rfl/base_types.cpp
    gen_rfl/base/common_rfl/common.cpp
    gen_rfl/node_rfl/node.cpp
    gen_rfl/node_rfl/func.cpp
    gen_rfl/node_rfl/config.cpp
    gen_rfl/node_rfl/options.cpp
    gen_rfl/node_rfl/priv_opts.cpp
    gen_rfl/node_rfl/base.cpp
)

add_executable(${PROJECT_NAME}
    ${EXAMPLE_SOURCES}    
    ${GEN_RFL_GENERATED_SOURCES}
)

link_directories(${GEN_RFL_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${GEN_RFL_DIR} ${CMAKE_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE )
