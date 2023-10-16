cmake_minimum_required(VERSION 3.26)
project(labb2_c)

set(CMAKE_CXX_STANDARD 23)

add_executable(labb2_c main.cpp
        dataGenerator.cpp
        dataGenerator.h
        insertionSort.cpp
        insertionSort.h
        quickSort.cpp
        quickSort.h
        saveData.cpp
        saveData.h
        selectionSort.cpp
        selectionSort.h
        sorting.h)
