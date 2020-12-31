project(com)

add_library(${PROJECT_NAME}
        src/ConnectionManager.cpp
        src/ReceiverConnection.cpp
        src/SenderConnection.cpp
        )

add_library(texugo::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
       )

target_link_libraries(${PROJECT_NAME}
        texugo::log
        texugo::message
        Boost::system
        Boost::thread
        )