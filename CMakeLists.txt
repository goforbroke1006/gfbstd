cmake_minimum_required(VERSION 3.17)
project(goxx-std)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Werror")

set(CMAKE_CXX_STANDARD 11)

enable_testing()
add_subdirectory(tests)