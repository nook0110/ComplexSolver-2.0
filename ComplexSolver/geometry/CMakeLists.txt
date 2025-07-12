# Geometry library configuration
file(GLOB GEOMETRY_SOURCES *.cpp)
file(GLOB GEOMETRY_HEADERS *.h)

# Create Geometry library
add_library(ComplexSolverGeometry STATIC ${GEOMETRY_SOURCES} ${GEOMETRY_HEADERS})

target_link_libraries(ComplexSolverGeometry PUBLIC
    ComplexSolverObserver
    ComplexSolverCore
)

# Set include directories
target_include_directories(ComplexSolverGeometry PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OPENGL_INCLUDE_DIRS}
)

# Export target for parent scope
set(GEOMETRY_LIBRARY ComplexSolverGeometry PARENT_SCOPE)