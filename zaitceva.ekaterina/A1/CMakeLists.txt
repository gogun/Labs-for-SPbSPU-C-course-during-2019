cmake_minimum_required(VERSION 3.13)
project(lab1_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab1_1
        base_types.hpp
        shape.hpp rectangle.cpp rectangle.hpp main.cpp circle.hpp circle.cpp)
