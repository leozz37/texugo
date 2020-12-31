cmake_minimum_required(VERSION 3.16.3)
project(texugo)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Downloading CPM file
set(CPM_DOWNLOAD_VERSION 0.27.2)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION} AND CPM_VERSION STREQUAL CPM_DOWNLOAD_VERSION))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# Nlohmann Json
CPMAddPackage(
    NAME nlohmann_json
    GITHUB_REPOSITORY nlohmann/json
    VERSION 3.9.1)

# spdlog
CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    VERSION 1.7.0)

# Boost
CPMFindPackage(
    NAME Boost
    GITHUB_REPOSITORY Orphis/boost-cmake
    VERSION 1.67.0
    FIND_PACKAGE_ARGUMENTS "COMPONENTS system thread")

# Prometheus
CPMFindPackage(
    NAME prometheus
    GITHUB_REPOSITORY jupp0r/prometheus-cpp
    GIT_TAG v0.10.0
    VERSION 0.10.0)

add_executable(${PROJECT_NAME}
    src/Texugo.cpp
        )

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME}
    com
    config
    log
    message
    metrics
)

enable_testing()
add_subdirectory(tests/unit)