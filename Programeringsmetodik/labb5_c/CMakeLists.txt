cmake_minimum_required(VERSION 3.26)
project(labb5_c)

set(CMAKE_CXX_STANDARD 23)

add_executable(labb5_c main.cpp
        laptop.cpp
        laptop.h
        MyPrint.cpp
        MyPrint.h
        GreaterThan.cpp
        GreaterThan.h
        MyBinOp.cpp
        MyBinOp.h
        MyUnOp.cpp
        MyUnOp.h
        MyFunc.cpp
        MyFunc.h)
