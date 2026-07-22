cmake_minimum_required(VERSION 4.3)
project(cstd C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cstd
        array.h
        strings.h
        test.c)
