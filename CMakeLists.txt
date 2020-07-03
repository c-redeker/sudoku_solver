PROJECT(sudoku_solver)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")

set(BUILD_TESTS ON)
if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
endif()

add_subdirectory(types)
add_subdirectory(solver)
add_subdirectory(reader)

add_executable(sudoku_solver_main main.cpp)
target_link_libraries(sudoku_solver_main reader)
