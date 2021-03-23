cmake_minimum_required(VERSION 3.17)
project(IF2210_TubesOOP1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(IF2210_TubesOOP1
        Battle.cpp
        Engimon.cpp
        Engimon.hpp
        main.cpp
        Maps.cpp
        Maps.h)
