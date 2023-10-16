cmake_minimum_required(VERSION 3.26)
project(labb2_c)

set(CMAKE_CXX_STANDARD 23)

add_executable(labb2_c main.cpp
        geometry.h
        shape.cpp
        shape.h
        rectangle.cpp
        rectangle.h
        parallelepiped.cpp
        parallelepiped.h
        roundedRect.cpp
        roundedRect.h
        circle.cpp
        circle.h
        cylinder.cpp
        cylinder.h
)
