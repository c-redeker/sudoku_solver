PROJECT(sudoku_solver)
cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "-std=c++14")

find_package(googletest REQUIRED CONFIG)

add_subdirectory(solver)

add_executable(sudoku_solver main.cpp)
