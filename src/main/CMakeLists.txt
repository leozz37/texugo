add_library(main STATIC
        src/main.cpp
        )

target_include_directories(main
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        src
        )


target_link_libraries(main
        log
        metrics
        )