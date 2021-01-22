# Including CPM
include(${CPM_DOWNLOAD_LOCATION})

# Catch2
CPMAddPackage(
    NAME Catch2
    GITHUB_REPOSITORY catchorg/Catch2
    VERSION 2.5.0)

add_executable(texugo_unit_tests
        main.cpp
        config/SettingsTest.cpp
        )

target_link_libraries(texugo_unit_tests
        texugo::config
        Catch2
        )

target_compile_definitions(texugo_unit_tests
        PUBLIC
            TEXUGO_TEST_RES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/../resources"
        )

enable_testing()
add_test(NAME texugo_unit_tests COMMAND texugo_unit_tests)