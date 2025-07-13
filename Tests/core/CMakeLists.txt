# Core module tests
add_executable(core_tests
    core_tests.cpp
)

target_link_libraries(core_tests
    PRIVATE
        ComplexSolverCore
        gtest_main
)

target_include_directories(core_tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/core
)

add_test(NAME core_tests COMMAND core_tests)