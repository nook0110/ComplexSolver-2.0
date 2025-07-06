# MISC components configuration
file(GLOB MISC_SOURCES *.cpp)
file(GLOB MISC_HEADERS *.h)

# Export variables to parent scope
set(MISC_SOURCES ${MISC_SOURCES} PARENT_SCOPE)
set(MISC_INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}
    PARENT_SCOPE)
set(MISC_LIBRARIES "" PARENT_SCOPE)