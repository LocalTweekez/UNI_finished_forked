cmake_minimum_required(VERSION 3.26)
project(labb1_c)

set(CMAKE_CXX_STANDARD 23)

add_executable(labb1_c main.cpp
        graph.cpp
        graph.h
        dijkstra.cpp
        dijkstra.h
        reader.cpp
        reader.h
        edges)
