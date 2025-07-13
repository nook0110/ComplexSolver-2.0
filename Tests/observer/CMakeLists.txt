# Test executable for observer module
add_executable(observer_tests observer_tests.cpp)

# Link with gtest and observer library
target_link_libraries(observer_tests
    PRIVATE
        gtest_main
        ComplexSolverObserver
)