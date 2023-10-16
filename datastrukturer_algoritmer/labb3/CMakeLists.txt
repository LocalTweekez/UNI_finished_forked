cmake_minimum_required(VERSION 3.26)
project(labb3)

set(CMAKE_CXX_STANDARD 23)

add_executable(labb3 main.cpp
        searching.h
        searchLinear.cpp
        searchLinear.h
        searchBinary.cpp
        searchBinary.h
        BST_Search.cpp
        BST_Search.h
        Hash_Search.cpp
        Hash_Search.h
        saveData.cpp
        saveData.h)
