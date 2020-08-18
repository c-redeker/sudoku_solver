add_library(reader src/reader.cpp)
target_include_directories(reader PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)

if(BUILD_TESTS)
    add_executable(reader_test test/reader_test.cpp)
    gtest_add_tests(TARGET reader_test)
    target_link_libraries(reader_test reader gtest gtest_main)

    file(COPY test/testfile_empty.txt DESTINATION ${CMAKE_BINARY_DIR}/src/reader)
    file(COPY test/testfile_too_many_numbers.txt DESTINATION ${CMAKE_BINARY_DIR}/src/reader)
    file(COPY test/testfile_negative_number.txt DESTINATION ${CMAKE_BINARY_DIR}/src/reader)
    file(COPY test/testfile_valid.txt DESTINATION ${CMAKE_BINARY_DIR}/src/reader)
endif()
