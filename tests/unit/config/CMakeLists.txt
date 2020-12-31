add_executable(texugo_test_settings SettingsTest.cpp)

target_link_libraries(texugo_test_settings
        texugo::config
        Catch2
        )

add_test(NAME texugo_test_settings COMMAND texugo_test_settings)
