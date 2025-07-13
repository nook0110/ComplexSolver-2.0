# GUI module tests
add_executable(gui_tests
    gui_tests.cpp
)

target_link_libraries(gui_tests
    PRIVATE
        ComplexSolverGui
        ComplexSolverGuiElements
        ComplexSolverGuiUtils
        gtest_main
)

add_test(NAME gui_tests COMMAND gui_tests)