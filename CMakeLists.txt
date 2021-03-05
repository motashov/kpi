cmake_minimum_required(VERSION 3.10)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(LIBNAME kpi)

file(GLOB_RECURSE SRCLIST
    ${CMAKE_CURRENT_SOURCE_DIR}/src/kpi/*.cpp
    )

add_library(${LIBNAME}
    SHARED
    ${SRCLIST}
    )

target_include_directories(${LIBNAME} PRIVATE include)

target_compile_options(
    ${LIBNAME} PUBLIC "-Wall" "-Werror" "-o2" "-std=c++11"
    )
