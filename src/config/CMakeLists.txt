add_library(log STATIC
    Logger.cpp
)

target_include_directories(log PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)