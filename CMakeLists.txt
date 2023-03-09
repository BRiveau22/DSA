cmake_minimum_required(VERSION 3.24)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DSA
        Node.cpp
        Node.h "Sparse_Matrix.h" "Sparse_Matrix.cpp")
