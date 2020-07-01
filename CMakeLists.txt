PROJECT(sudoku_solver)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-std=c++14")

find_package(GTest REQUIRED)

add_subdirectory(solver)

add_executable(sudoku_solver main.cpp)
