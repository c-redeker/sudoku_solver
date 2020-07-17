add_library(printer src/printer.cpp)
target_include_directories(printer PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)
target_link_libraries(printer PUBLIC types)