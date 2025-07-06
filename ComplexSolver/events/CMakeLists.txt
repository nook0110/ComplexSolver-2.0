# Event handling components configuration
file(GLOB EVENTS_SOURCES *.cpp)
file(GLOB EVENTS_HEADERS *.h)

# Export variables to parent scope
set(EVENTS_SOURCES ${EVENTS_SOURCES} PARENT_SCOPE)
set(EVENTS_INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}
    PARENT_SCOPE)
set(EVENTS_LIBRARIES "" PARENT_SCOPE)