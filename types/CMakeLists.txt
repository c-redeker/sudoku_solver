add_library(types src/cell.cpp)
target_include_directories(types PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)

if(BUILD_TESTS)
    add_executable(types_test test/cell_test.cpp)
    gtest_add_tests(TARGET types_test)
    target_link_libraries(types_test types gtest gtest_main)
endif()
