cmake_minimum_required(VERSION 3.26)
project(td04)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(td04
        common_defs.h
        main_mvector.cpp
        MVector.cpp)
