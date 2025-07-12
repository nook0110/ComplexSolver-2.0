# Plane library configuration
file(GLOB OBSERVER_SOURCES *.cpp)
file(GLOB OBSERVER_HEADERS *.h)

# Create Plane library
add_library(ComplexSolverObserver STATIC ${OBSERVER_SOURCES} ${OBSERVER_HEADERS})

# Set include directories
target_include_directories(ComplexSolverObserver PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)