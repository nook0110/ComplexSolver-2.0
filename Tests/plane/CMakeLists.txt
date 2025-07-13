# Test executable for plane module
add_executable(plane_tests plane_tests.cpp)

# Link with gtest and plane library
target_link_libraries(plane_tests
    PRIVATE
        gtest_main
        ComplexSolverPlane
)