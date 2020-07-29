add_library(solver
        src/solver_simple_exclude.cpp
        src/solver_unique_candidates.cpp
        src/free_functions_solver.cpp
        src/solver_naked_pairs.cpp
        src/solver_block_row_column_interaction.cpp
        src/solver_hidden_pairs.cpp)
target_include_directories(solver PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)
target_link_libraries(solver PUBLIC types)

if (BUILD_TESTS)
    add_executable(solver_test test/solver_test.cpp)
    gtest_add_tests(TARGET solver_test)
    target_link_libraries(solver_test solver gtest gtest_main)
endif ()