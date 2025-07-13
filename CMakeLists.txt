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

# Set SFML_DIR fxor Thor to find our built SFML
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML/install/lib/cmake/SFML" CACHE PATH "Path to SFML build")

# Add Thor
add_subdirectory(Thor)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui" CACHE PATH "Path to imgui")
file(GLOB IMGUI_SOURCES ${IMGUI_DIR}/*.cpp)
file(GLOB IMGUI_HEADERS ${IMGUI_DIR}/*.h)

add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_HEADERS})

add_subdirectory(imgui-sfml)

include_directories(SFML/include 
    ${CMAKE_HOME_DIRECTORY}/ComplexSolver
    ${CMAKE_HOME_DIRECTORY}/imgui
    ${CMAKE_HOME_DIRECTORY}/imgui-sfml
    ${CMAKE_HOME_DIRECTORY}/Thor/include
    ${CMAKE_HOME_DIRECTORY}/Aurora/include
    ${OPENGL_INCLUDE_DIRS}
    )

# Add main project
add_subdirectory(ComplexSolver)
add_subdirectory(Tests)

# Treat warnings as errors
add_compile_options(-Wall -Werror)