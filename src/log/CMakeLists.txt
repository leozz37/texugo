add_library(message STATIC
    MessageParser.cpp
    ProcessMessage.cpp
)

target_include_directories(message PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)