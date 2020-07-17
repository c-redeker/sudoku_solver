add_library(solver src/solver_simple_exclude.cpp src/free_functions_solver.cpp)
target_include_directories(solver PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)
target_link_libraries(solver PUBLIC types)