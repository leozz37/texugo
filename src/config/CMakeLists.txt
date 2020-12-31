add_library(config STATIC
        Settings.cpp
        )

add_library(texugo::config ALIAS config)

target_include_directories(config
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
        )

target_link_libraries(config
        nlohmann_json
        )