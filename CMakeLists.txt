cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(texugo
    VERSION 0.0.1
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "Texugo: Tests enabled")
enable_testing(true)
add_subdirectory(tests)

# Downloading dependencies
include(cmake/CPM.cmake)

# Nlohmann Json
CPMAddPackage(
        NAME nlohmann_json
        GITHUB_REPOSITORY nlohmann/json
        VERSION 3.7.0)

# spdlog
CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    VERSION 1.7.0)

# Google Test

    
add_executable(texugo_process
    src/main/main.cpp)

add_library(texugo STATIC
        src/com/Connection.cpp
        src/com/Manager.cpp
        src/config/Settings.cpp
        src/log/Logger.cpp)

target_include_directories(texugo
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${TEXUGO_GEN_BINARY_DIR}/src)

target_link_libraries(texugo_process
    texugo
    spdlog::spdlog
    nlohmann_json::nlohmann_json)