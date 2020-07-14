cmake_minimum_required(VERSION 3.9)

project(texugo
        VERSION 0.0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "Texugo: Tests enabled")
enable_testing(true)
add_subdirectory(tests)

set(TEXUGO_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TEXUGO_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(TEXUGO_GEN_BINARY_DIR ${texugo_BINARY_DIR}/gen)

find_package(spdlog REQUIRED)
find_package(prometheus-cpp REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(texugo
        src/com/Connection.cpp
        src/com/Manager.cpp
        src/config/Settings.cpp
        src/log/Logger.cpp
        src/main/main.cpp
        src/metrics/MetricsExporter.cpp)

target_include_directories(texugo
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${TEXUGO_GEN_BINARY_DIR}/src)

target_link_libraries(texugo
        spdlog::spdlog
        prometheus-cpp::pull
        nlohmann_json::nlohmann_json)

enable_testing()
