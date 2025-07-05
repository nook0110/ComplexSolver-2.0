# Configuration for HomoGebra module

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

file(GLOB SOURCES "*.cpp")

# Export sources and configurations to parent scope
set(HOMOGEBRA_SOURCES ${SOURCES} ${IMGUI_SOURCES} PARENT_SCOPE)
set(HOMOGEBRA_INCLUDE_DIRS
    ${THOR_INCLUDE_PATH}
    ${IMGUI_DIR}
    ${OPENGL_INCLUDE_DIRS}
    PARENT_SCOPE)
set(HOMOGEBRA_LIBRARIES
    ${OPENGL_LIBRARIES}
    PARENT_SCOPE)
set(HOMOGEBRA_DEFINITIONS _DEBUG=1 PARENT_SCOPE)