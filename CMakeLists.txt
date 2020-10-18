cmake_minimum_required(VERSION 3.17)
project(gfbstd)

set(CMAKE_CXX_STANDARD 11)

add_executable(gfbstd main.cpp)

enable_testing()
add_subdirectory(tests)