cmake_minimum_required(VERSION 3.26)
project(td05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(td05
        common_defs.h
        main_matrix.cpp
        MVector.cpp
        MVector.h
        Matrix.cpp)
