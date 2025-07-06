# Utility components configuration
file(GLOB UTILS_SOURCES *.cpp)
file(GLOB UTILS_HEADERS *.h)

# Export variables to parent scope
set(UTILS_SOURCES ${UTILS_SOURCES} PARENT_SCOPE)
set(UTILS_INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}
    PARENT_SCOPE)
set(UTILS_LIBRARIES "" PARENT_SCOPE)