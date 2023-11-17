cmake_minimum_required(VERSION 3.26)
project(td08)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(td08
        common_defs.h
        main_list_copy.cpp)
