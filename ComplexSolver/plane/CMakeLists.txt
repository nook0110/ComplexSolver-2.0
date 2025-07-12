# Plane library configuration
file(GLOB PLANE_SOURCES *.cpp)
file(GLOB PLANE_HEADERS *.h)

# Create Plane library
add_library(ComplexSolverPlane STATIC ${PLANE_SOURCES} ${PLANE_HEADERS})

target_link_libraries(ComplexSolverPlane PUBLIC
    ComplexSolverObserver
)

# Set include directories
target_include_directories(ComplexSolverPlane PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)