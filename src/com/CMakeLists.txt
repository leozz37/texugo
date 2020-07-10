add_library(com STATIC
        src/Connection.cpp
        src/Manager.cpp
        )

target_include_directories(com
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        src
        )

target_link_libraries(com
        log
        )