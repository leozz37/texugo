cmake_minimum_required(VERSION 3.16)
project(message_switch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

find_package(spdlog REQUIRED)

add_subdirectory(src/main)
add_subdirectory(src/management)

add_executable(message_switch src/main/src/main.cpp src/management/metrics/include/metrics/MetricsExporter.hpp)

target_link_libraries(message_switch
        log
        spdlog::spdlog
        )