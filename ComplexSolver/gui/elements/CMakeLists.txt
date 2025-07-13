# GUI Elements library configuration
file(GLOB GUI_ELEMENTS_SOURCES *.cpp)
file(GLOB GUI_ELEMENTS_HEADERS *.h)

# Create GUI Elements library
add_library(ComplexSolverGuiElements STATIC ${GUI_ELEMENTS_SOURCES} ${GUI_ELEMENTS_HEADERS})

# Set include directories
target_include_directories(ComplexSolverGuiElements PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ComplexSolverGuiElements PUBLIC
    ComplexSolverGuiUtils
)