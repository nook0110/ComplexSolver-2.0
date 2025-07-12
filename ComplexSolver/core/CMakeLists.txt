# Core library configuration
file(GLOB CORE_SOURCES *.cpp)
file(GLOB CORE_HEADERS *.h)

# Create core library
add_library(ComplexSolverCore STATIC ${CORE_SOURCES} ${CORE_HEADERS})

target_link_libraries(ComplexSolverCore PUBLIC
    ComplexSolverObserver
)

# Set include directories
target_include_directories(ComplexSolverCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
