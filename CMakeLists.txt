cmake_minimum_required(VERSION 3.12)
project(goxx-std-all)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Werror")

add_subdirectory(goxx-std)

enable_testing()
add_subdirectory(tests)
