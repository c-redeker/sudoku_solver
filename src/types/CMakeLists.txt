add_library(types src/cell.cpp src/cell_container.cpp src/sudoku.cpp src/rectangle.cpp src/subset_generator.cpp)
target_include_directories(types PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)

if(BUILD_TESTS)
    add_executable(cell_test test/cell_test.cpp)
    gtest_add_tests(TARGET cell_test)
    target_link_libraries(cell_test types gtest gtest_main)

    add_executable(cell_container_test test/cell_container_test.cpp)
    gtest_add_tests(TARGET cell_container_test)
    target_link_libraries(cell_container_test types gtest gtest_main)

    add_executable(rectangle_test test/rectangle_test.cpp)
    gtest_add_tests(TARGET rectangle_test)
    target_link_libraries(rectangle_test types gtest gtest_main)

    add_executable(sudoku_test test/sudoku_test.cpp)
    gtest_add_tests(TARGET sudoku_test)
    target_link_libraries(sudoku_test types gtest gtest_main)

    add_executable(subset_generator_test test/subset_generator_test.cpp)
    gtest_add_tests(TARGET subset_generator_test)
    target_link_libraries(subset_generator_test types gtest gtest_main)
endif()
