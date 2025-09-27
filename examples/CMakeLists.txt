cmake_minimum_required(VERSION 3.10)

project(exe_node)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(GEN_RFL_DIR ${CMAKE_SOURCE_DIR}/gen_rfl)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE DEBUG)
endif()

file(GLOB ALL_CPP_FILES "*.cpp" "gen_rfl/*.cpp" "gen_rfl/**/*.cpp" "gen_rfl/**/**/*.cpp")
# list(FILTER ALL_CPP_FILES EXCLUDE REGEX "build/*.cpp$")

add_executable(${PROJECT_NAME}
    ${ALL_CPP_FILES}
)

link_directories(${GEN_RFL_DIR})

# message(STATUS "Linking ${GEN_RFL_DIR}/librfl.a")
# target_link_libraries(${PROJECT_NAME} ${GEN_RFL_DIR}/librfl.a)

target_include_directories(${PROJECT_NAME} PRIVATE ${GEN_RFL_DIR})

