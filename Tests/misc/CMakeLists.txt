# Test executable for misc module
add_executable(misc_tests misc_tests.cpp)

# Link with gtest and misc library
target_link_libraries(misc_tests
    PRIVATE
        gtest_main
        ComplexSolverUtils
)