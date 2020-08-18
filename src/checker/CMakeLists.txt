add_library(checker src/checker.cpp)
target_include_directories(checker PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)
target_link_libraries(checker PUBLIC types)

if(BUILD_TESTS)
    add_executable(checker_test test/checker_test.cpp)
    gtest_add_tests(TARGET checker_test)
    target_link_libraries(checker_test checker gtest gtest_main)
endif()