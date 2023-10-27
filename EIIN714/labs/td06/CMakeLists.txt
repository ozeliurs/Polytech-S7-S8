cmake_minimum_required(VERSION 3.26)
project(td06)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(td06
        common_defs.h
        main_squarematrix.cpp
        Matrix.cpp
        Matrix.h
        SquareMatrix.cpp
        DiagonalMatrix.cpp
        ScalarMatrix.cpp
        MVector.cpp)
