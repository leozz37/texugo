cmake_minimum_required(VERSION 3.12)

project(texugo
        VERSION 0.0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "Texugo: Tests enabled")
enable_testing(true)
add_subdirectory(tests)

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
