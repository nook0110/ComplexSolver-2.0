# Main application configuration
file(GLOB MAIN_SOURCES *.cpp)
file(GLOB MAIN_HEADERS *.h)

add_executable(ComplexSolver ${MAIN_SOURCES} ${MAIN_HEADERS})

target_include_directories(ComplexSolver PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ComplexSolver 
    ComplexSolverCore 
    ComplexSolverGui 
    ComplexSolverPlane
    ComplexSolverGui
    ComplexSolverGuiElements
    ComplexSolverGeometry
    ComplexSolverEvents
    ComplexSolverUtils
    imgui
    sfml-graphics
    sfml-window
    sfml-system
    ImGui-SFML
    thor
    ${OPENGL_LIBRARIES}
)