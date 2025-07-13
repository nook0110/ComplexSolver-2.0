# GUI Utils library configuration
file(GLOB GUI_UTILS_SOURCES *.cpp)
file(GLOB GUI_UTILS_HEADERS *.h)

# Create GUI Utils library
add_library(ComplexSolverGuiUtils STATIC ${GUI_UTILS_SOURCES} ${GUI_UTILS_HEADERS})

# Set include directories
target_include_directories(ComplexSolverGuiUtils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)