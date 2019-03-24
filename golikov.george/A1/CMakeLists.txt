cmake_minimum_required(VERSION 3.13)
project(Task_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Task_1
        .idea/.name
        .idea/encodings.xml
        .idea/misc.xml
        .idea/modules.xml
        ".idea/Task 1.iml"
        .idea/workspace.xml
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/Project.cbp
        cmake-build-debug/Task_1.cbp
        cmake-build-debug/Task_1.exe
        base-types.hpp
        circle.cpp
        circle.hpp
        CMakeLists.txt
        main.cpp
        rectangle.cpp
        rectangle.hpp
        shape.hpp)
