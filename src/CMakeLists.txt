add_subdirectory(com)
add_subdirectory(config)
add_subdirectory(log)
add_subdirectory(message)
add_subdirectory(metrics)

add_executable(texugo
        Texugo.cpp
        )

target_link_libraries(texugo
        texugo::com
        texugo::config
        texugo::log
        texugo::message
        texugo::metrics
        )