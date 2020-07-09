add_library(metrics STATIC
        src/MetricsExporter.cpp
        )

target_include_directories(metrics
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        src
        )

target_link_libraries(metrics
        log
        )