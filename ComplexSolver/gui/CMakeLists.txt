# GUI components configuration
file(GLOB GUI_SOURCES *.cpp)
file(GLOB GUI_HEADERS *.h)

# Export variables to parent scope
set(GUI_SOURCES ${GUI_SOURCES} PARENT_SCOPE)
set(GUI_INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${IMGUI_DIR}
    PARENT_SCOPE)
set(GUI_LIBRARIES "" PARENT_SCOPE)