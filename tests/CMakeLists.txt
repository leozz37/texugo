find_package(GTest REQUIRED)
add_executable(unit_tests
        main/main.cpp
        )

target_link_libraries(unit_tests
        ${GTEST_LIBRARIES}
        pthread)

add_test(
        NAME
            unit_tests
        COMMAND
            ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/tests/unit_tests)