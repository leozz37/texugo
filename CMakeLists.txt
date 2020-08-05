cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(texugo
    VERSION 0.0.1
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "Texugo: Tests enabled")
enable_testing(true)
add_subdirectory(tests)

# Downloading CPM file
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/../cmake/CPM.cmake")
set(CPM_DOWNLOAD_VERSION 0.25.1)

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION} AND CPM_VERSION STREQUAL CPM_DOWNLOAD_VERSION))
  message(STATUS "Downloading CPM.cmake")
  file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

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
    spdlog
    nlohmann_json)