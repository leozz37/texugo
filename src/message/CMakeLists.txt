add_library(metrics STATIC
    MetricsExporter.cpp
    MetricsMessage.cpp
)

target_include_directories(metrics
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    PRIVATE
        src
)