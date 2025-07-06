cmake_minimum_required(VERSION 3.20)
project(ComplexSolver)

# Generate compile_commands.json for tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

add_subdirectory(SFML)

# Build SFML from submodule with static libraries
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build SFML as static libraries")

# Set SFML_DIR for Thor to find our built SFML
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML/install/lib/cmake/SFML" CACHE PATH "Path to SFML build")


# Add Thor
add_subdirectory(Thor)

# Add main project
add_subdirectory(ComplexSolver)

# Create executable using exported sources
add_executable(Solver ${COMPLEX_SOLVER_SOURCES} )

# Apply configurations from ComplexSolver and link SFML targets
target_link_libraries(Solver
    ${COMPLEX_SOLVER_LIBRARIES}
    sfml-graphics
    sfml-window
    sfml-system
    thor
)
target_include_directories(Solver PRIVATE
    ${COMPLEX_SOLVER_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/Thor/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Aurora/include
    ${CMAKE_CURRENT_SOURCE_DIR}/SFML/install/include
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui-sfml
)
target_compile_definitions(Solver PRIVATE ${COMPLEX_SOLVER_DEFINITIONS})

