cmake_minimum_required(VERSION 3.5)
project(c LANGUAGES CXX)

add_subdirectory(variables_and_basic_types)
add_subdirectory(class_lib)

set(CMAKE_CXX_STANDARD 17) # specify the C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(main main.cpp)

