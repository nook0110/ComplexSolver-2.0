cmake_minimum_required(VERSION 3.20)
project(HomoGebra)

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
add_subdirectory(HomoGebra)

# Create executable using exported sources
add_executable(Solver ${HOMOGEBRA_SOURCES})

# Apply configurations from HomoGebra and link SFML targets
target_link_libraries(Solver
    ${HOMOGEBRA_LIBRARIES}
    sfml-graphics
    sfml-window
    sfml-system
    thor
)
target_include_directories(Solver PRIVATE
    ${HOMOGEBRA_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/Thor/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Aurora/include
    ${CMAKE_CURRENT_SOURCE_DIR}/SFML/install/include
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui-sfml
)
target_compile_definitions(Solver PRIVATE ${HOMOGEBRA_DEFINITIONS})

# Add tests
add_subdirectory(HomoGebra Tests)
