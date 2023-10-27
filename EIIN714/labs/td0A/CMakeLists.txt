cmake_minimum_required(VERSION 3.26)
project(td0A)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(td0A
        image.cpp
        image.h
        main_image.cpp
        pixel.h)
