# Events module tests
add_executable(events_tests
    events_tests.cpp
)

target_link_libraries(events_tests
    PRIVATE
        ComplexSolverEvents
        gtest_main
)

add_test(NAME events_tests COMMAND events_tests)