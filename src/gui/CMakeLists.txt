add_library(gui src/gui.cpp src/gui_application.cpp)
target_include_directories(gui PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)
target_link_libraries(gui PUBLIC types solver Qt5::Widgets)