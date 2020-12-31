add_library(metrics STATIC
        MetricsExporter.cpp
        MetricsMessage.cpp
        )

add_library(texugo::metrics ALIAS metrics)

target_include_directories(metrics
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
        )

target_link_libraries(metrics
        prometheus-cpp::pull
        )