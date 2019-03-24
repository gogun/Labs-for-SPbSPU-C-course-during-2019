cmake_minimum_required(VERSION 3.13)
project(test)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp circle.cpp rectangle.cpp
        circle.hpp rectangle.hpp)
