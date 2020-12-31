add_library(com STATIC
        ConnectionManager.cpp
        ReceiverConnection.cpp
        SenderConnection.cpp
        )

add_library(texugo::com ALIAS com)

target_include_directories(com
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
       )

target_link_libraries(com
        texugo::log
        texugo::message
        Boost::system
        Boost::thread
        )