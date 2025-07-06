# Main application configuration
file(GLOB MAIN_SOURCES *.cpp)
file(GLOB MAIN_HEADERS *.h)

# Export variables to parent scope
set(MAIN_SOURCES ${MAIN_SOURCES} PARENT_SCOPE)
set(MAIN_INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}
    PARENT_SCOPE)
set(MAIN_LIBRARIES "" PARENT_SCOPE)