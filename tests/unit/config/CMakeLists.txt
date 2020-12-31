add_executable(SettingsTest SettingsTest.cpp)

target_link_libraries(SettingsTest
    texugo_tests
    nlohmann_json
    Catch2
)

add_test(NAME SettingsTest COMMAND SettingsTest)
