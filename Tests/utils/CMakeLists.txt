# Test executable for utils module
add_executable(utils_tests utils_tests.cpp)

# Link with gtest and utils library
target_link_libraries(utils_tests
    PRIVATE
        gtest_main
        ComplexSolverUtils
)