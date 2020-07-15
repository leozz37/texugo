find_package(GTest REQUIRED)

add_executable(unit_tests
        main/main.cpp com/ConnectionTest.cpp)

target_link_libraries(unit_tests
        texugo
        ${GTEST_LIBRARIES}
        pthread)

add_test(NAME unit_tests COMMAND unit_tests)
