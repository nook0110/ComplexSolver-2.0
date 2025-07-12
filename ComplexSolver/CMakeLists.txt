cmake_minimum_required(VERSION 3.5)
project(ComplexSolver LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Include subdirectories (they will create their own libraries)
add_subdirectory(core)
add_subdirectory(events)
add_subdirectory(geometry)
add_subdirectory(gui)
add_subdirectory(main)
add_subdirectory(misc)
add_subdirectory(observer)
add_subdirectory(plane)
add_subdirectory(utils)
