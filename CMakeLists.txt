cmake_minimum_required(VERSION 3.10)

add_subdirectory(src)


set(TEST_NAME testApp)
add_executable(${TEST_NAME} test.cpp)
target_link_libraries(${TEST_NAME} kpi)
