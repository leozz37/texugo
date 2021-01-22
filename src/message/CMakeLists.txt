add_library(message STATIC
        MessageParser.cpp
        ProcessMessage.cpp
        )

add_library(texugo::message ALIAS message)

target_include_directories(message
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
        )

target_link_libraries(message
        texugo::com
        texugo::log
        nlohmann_json
        )