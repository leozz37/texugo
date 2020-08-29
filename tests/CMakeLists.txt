# Including CPM
include(${CPM_DOWNLOAD_LOCATION})

# Gtest
#CPMAddPackage(
#  NAME googletest
#  GITHUB_REPOSITORY google/googletest
#  GIT_TAG release-1.8.1
#  VERSION 1.8.1
#  OPTIONS
#      "INSTALL_GTEST OFF"
#      "gtest_force_shared_crt"
#)

add_executable(unit_tests
        main/main.cpp
        com/ConnectionTest.cpp
        com/ManagerTest.cpp
        config/SettingsTest.cpp)

target_link_libraries(unit_tests
        texugo
        gtest
        gmock)

add_test(NAME unit_tests COMMAND unit_tests)
