cmake_minimum_required(VERSION 3.5)
project(ComplexSolver LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# ImGui submodule
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../imgui)
set(IMGUI_SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../imgui-sfml)

# Add ImGui source files
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/misc/cpp/imgui_stdlib.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_SFML_DIR}/imgui-SFML.cpp
)


# Include subdirectories (they export their own sources and configs)
add_subdirectory(core)
add_subdirectory(gui)
add_subdirectory(events)
add_subdirectory(geometry)
add_subdirectory(utils)
add_subdirectory(plane)
add_subdirectory(main)

# Aggregate all sources and configurations from subdirectories
set(COMPLEX_SOLVER_SOURCES
    ${CORE_SOURCES}
    ${GUI_SOURCES}
    ${EVENTS_SOURCES}
    ${GEOMETRY_SOURCES}
    ${UTILS_SOURCES}
    ${PLANE_SOURCES}
    ${MAIN_SOURCES}
    ${IMGUI_SOURCES}
    PARENT_SCOPE)
    
set(COMPLEX_SOLVER_INCLUDE_DIRS
    ${CORE_INCLUDE_DIRS}
    ${GUI_INCLUDE_DIRS}
    ${EVENTS_INCLUDE_DIRS}
    ${SFML_INCLUDE_DIRS}
    ${THOR_INCLUDE_PATH}
    ${IMGUI_DIR}
    ${OPENGL_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
    PARENT_SCOPE)
    
set(COMPLEX_SOLVER_LIBRARIES
    ${CORE_LIBRARIES}
    ${GUI_LIBRARIES}
    ${EVENTS_LIBRARIES}
    ${OPENGL_LIBRARIES}
    PARENT_SCOPE)
set(COMPLEX_SOLVER_DEFINITIONS _DEBUG=1 PARENT_SCOPE)