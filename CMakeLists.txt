cmake_minimum_required(VERSION 3.17)
project(cpp_designpattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_designpattern main.cpp)

add_subdirectory(principles)
add_subdirectory(creativity)
add_subdirectory(structure_pattern)
add_subdirectory(behavior_pattern)