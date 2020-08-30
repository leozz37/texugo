# Including CPM
include(${CPM_DOWNLOAD_LOCATION})

# Catch2
CPMAddPackage(
    NAME Catch2
    GITHUB_REPOSITORY catchorg/Catch2
    VERSION 2.5.0)

add_executable(texugo_tests
        com/ConnectionTest.cpp
        com/ManagerTest.cpp
        config/SettingsTest.cpp
        main/main.cpp)

target_link_libraries(texugo_tests
        texugo
        Catch2)

enable_testing()
target_link_libraries(texugo_tests --coverage)
add_test(NAME texugo_tests COMMAND texugo_tests)


