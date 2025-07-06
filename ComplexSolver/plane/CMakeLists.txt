# Plane components configuration
file(GLOB PLANE_SOURCES *.cpp)
file(GLOB PLANE_HEADERS *.h)

# Export variables to parent scope
set(PLANE_SOURCES ${PLANE_SOURCES} PARENT_SCOPE)
set(PLANE_INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}
    PARENT_SCOPE)
set(PLANE_LIBRARIES "" PARENT_SCOPE)