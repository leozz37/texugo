# Including CPM
include(${CPM_DOWNLOAD_LOCATION})

# Catch2
CPMAddPackage(
    NAME Catch2
    GITHUB_REPOSITORY catchorg/Catch2
    VERSION 2.5.0)

add_executable(unit_tests
        com/ConnectionTest.cpp
        com/ManagerTest.cpp
        config/SettingsTest.cpp
        main/main.cpp)

target_link_libraries(unit_tests
        texugo
        Catch2)

enable_testing()
add_test(NAME unit_tests COMMAND unit_tests)