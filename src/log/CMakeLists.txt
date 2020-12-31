add_library(log STATIC
        Logger.cpp
        )

add_library(texugo::log ALIAS log)

target_include_directories(log
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
        )

target_link_libraries(log
        spdlog
        )