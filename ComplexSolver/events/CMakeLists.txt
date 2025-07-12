# Events library configuration
file(GLOB EVENTS_SOURCES *.cpp)
file(GLOB EVENTS_HEADERS *.h)

# Create Events library
add_library(ComplexSolverEvents STATIC ${EVENTS_SOURCES} ${EVENTS_HEADERS})

# Set include directories
target_include_directories(ComplexSolverEvents PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OPENGL_INCLUDE_DIRS}
)