cmake_minimum_required(VERSION 3.9)
project(message_switch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

find_package(spdlog REQUIRED)
find_package(prometheus-cpp REQUIRED)
find_package(nlohmann_json REQUIRED)

add_subdirectory(src/com)
add_subdirectory(src/data_store)
add_subdirectory(src/main)
add_subdirectory(src/management)

add_executable(message_switch
        src/main/src/main.cpp
        )

target_link_libraries(message_switch
        com
        config
        log
        metrics


        spdlog::spdlog
        prometheus-cpp::pull
        nlohmann_json::nlohmann_json
        )