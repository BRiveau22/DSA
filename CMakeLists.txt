cmake_minimum_required(VERSION 3.24)
project(multiplying_matrix)

set(CMAKE_CXX_STANDARD 11)

add_executable(multiplying_matrix application.cpp Sparse_Matrix.cpp sparse_matrix.h node.cpp node.h)