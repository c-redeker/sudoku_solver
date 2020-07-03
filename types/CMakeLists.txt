add_library(types src/cell.cpp src/cell_container.cpp)
target_include_directories(types PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)

if(BUILD_TESTS)
    add_executable(cell_test test/cell_test.cpp)
    gtest_add_tests(TARGET cell_test)
    target_link_libraries(cell_test types gtest gtest_main)

    add_executable(cell_container_test test/cell_container_test.cpp)
    gtest_add_tests(TARGET cell_container_test)
    target_link_libraries(cell_container_test types gtest gtest_main)
endif()
