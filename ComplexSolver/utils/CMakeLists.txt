# Utils library configuration
file(GLOB UTILS_SOURCES *.cpp)
file(GLOB UTILS_HEADERS *.h)

# Create Utils library
add_library(ComplexSolverUtils STATIC ${UTILS_SOURCES} ${UTILS_HEADERS})

target_link_libraries(ComplexSolverUtils PUBLIC
    ComplexSolverGeometry
)

# Set include directories
target_include_directories(ComplexSolverUtils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
