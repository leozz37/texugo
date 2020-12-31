add_library(config STATIC
    Settings.cpp
)

target_include_directories(config PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)