project(message)

add_library(${PROJECT_NAME}
        src/MessageParser.cpp
        src/ProcessMessage.cpp
        )

add_library(texugo::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME}
        texugo::com
        texugo::log
        nlohmann_json
        )