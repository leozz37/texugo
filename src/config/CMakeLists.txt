project(config)

add_library(${PROJECT_NAME}
        src/Settings.cpp
        )

add_library(texugo::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME}
        nlohmann_json
        )