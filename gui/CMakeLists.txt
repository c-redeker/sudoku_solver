add_library(gui src/gui.cpp)
target_include_directories(gui PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)
target_link_libraries(gui PUBLIC types Qt5::Widgets)