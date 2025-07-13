# GUI library configuration
file(GLOB GUI_SOURCES *.cpp)
file(GLOB GUI_HEADERS *.h)

# Create GUI library
add_library(ComplexSolverGui STATIC ${GUI_SOURCES} ${GUI_HEADERS})

target_link_libraries(ComplexSolverGui PUBLIC
    ComplexSolverObserver
)

# Include elements subdirectory (will create its own target)
add_subdirectory(elements)
add_subdirectory(utils)

# Set include directories
target_include_directories(ComplexSolverGui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
