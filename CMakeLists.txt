cmake_minimum_required(VERSION 4.3)
project(cstd C)
set(CMAKE_C_STANDARD 99)
include_directories(.)
add_executable(cstd
        array.h
        strings.h
        main.c
        vec.h)

project(cppstd CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(cppstd
        array.h
        strings.h
        main.cpp
        vec.h)
