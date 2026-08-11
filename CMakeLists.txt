cmake_minimum_required(VERSION 4.3)
project(cstd C)
set(CMAKE_C_STANDARD 99)
add_executable(cstd
        main.c
        cstd.h)

project(cppstd CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(cppstd
        main.cpp
        cstd.h)
