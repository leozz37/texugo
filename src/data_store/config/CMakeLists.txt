add_library(config STATIC
        src/Settings.cpp
        )

target_include_directories(config
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        src
        )

target_link_libraries(config
        log
        )