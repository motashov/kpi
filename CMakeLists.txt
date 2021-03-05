cmake_minimum_required(VERSION 3.10)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(LIBNAME kpi)
string(ASCII 27 Esc)

FILE(GLOB COUNTERS_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/kpi/counters/*.cpp)

set(SRCLIST
    ${CMAKE_CURRENT_SOURCE_DIR}/src/kpi/counters.cpp
    ${COUNTERS_LIST}
    )

add_library(${LIBNAME}
    SHARED
    ${SRCLIST}
    )

target_include_directories(${LIBNAME} PRIVATE include)

target_compile_options(
    ${LIBNAME} PUBLIC "-Wall" "-Werror" "-o2" "-std=c++11"
    )



message(STATUS "${Esc}[36mCompile ${LIBNAME} library ${Esc}[m")
message(STATUS "${Esc}[36m${LIBNAME} library src list ${Esc}[m")
foreach (src ${SRCLIST})
    message (STATUS "${src}")
endforeach(src)
message(STATUS "${Esc}[36m${LIBNAME} library src list END ${Esc}[m")

