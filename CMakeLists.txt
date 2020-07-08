cmake_minimum_required(VERSION 3.16)
project(message_switch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src/main)

add_executable(message_switch src/main/src/main.cpp)