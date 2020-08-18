add_subdirectory(types)
add_subdirectory(solver)
add_subdirectory(reader)
add_subdirectory(printer)
add_subdirectory(checker)
add_subdirectory(gui)

add_executable(sudoku_solver_main main.cpp)
target_link_libraries(sudoku_solver_main reader solver printer checker gui)
