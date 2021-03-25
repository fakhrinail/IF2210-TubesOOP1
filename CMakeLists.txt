cmake_minimum_required(VERSION 3.17)
project(IF2210_TubesOOP1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(IF2210_TubesOOP1
        Element.hpp
        Element.cpp
        Engimon.cpp
        Engimon.hpp
        Inventory.hpp
        Inventory.cpp
        Maps.cpp
        Maps.h
        main.cpp
        Player.hpp
        Player.cpp
        point.h
        point.cpp
        Skill.hpp
        Skill.cpp
        Species.hpp
        Species.cpp)
