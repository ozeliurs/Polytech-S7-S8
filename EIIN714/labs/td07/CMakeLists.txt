cmake_minimum_required(VERSION 3.26)
project(td07)

set(CMAKE_CXX_STANDARD 14)

add_executable(td07
        main_list_simple.cpp
        common_defs.h
        Cell.h
        List.cpp)
