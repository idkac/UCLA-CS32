cmake_minimum_required(VERSION 3.26)
project(Project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project1 main.cpp
        utilities.cpp
        City.cpp
        Game.cpp
        History.cpp
        Player.cpp
        Tooter.cpp)
