PROJECT(sudoku_solver)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -std=c++14 -pthread -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(BUILD_TESTS ON)
if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(types)
add_subdirectory(solver)
add_subdirectory(reader)
add_subdirectory(printer)
add_subdirectory(checker)
add_subdirectory(gui)

add_executable(sudoku_solver_main main.cpp)
target_link_libraries(sudoku_solver_main reader solver printer checker gui)

file(COPY data/sudokus.txt DESTINATION ${CMAKE_BINARY_DIR})
