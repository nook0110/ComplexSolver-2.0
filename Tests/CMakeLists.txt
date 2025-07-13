cmake_minimum_required(VERSION 3.11)

# Enable testing
enable_testing()

# Download and build GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Include project directories
include_directories(
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/events
    ${CMAKE_SOURCE_DIR}/geometry
    ${CMAKE_SOURCE_DIR}/gui
    ${CMAKE_SOURCE_DIR}/misc
    ${CMAKE_SOURCE_DIR}/observer
    ${CMAKE_SOURCE_DIR}/plane
    ${CMAKE_SOURCE_DIR}/utils
    ${CMAKE_SOURCE_DIR}/tests
    ${googletest_SOURCE_DIR}/googletest/include
    ${googletest_SOURCE_DIR}/googlemock/include
)

add_subdirectory(core)
add_subdirectory(events)
add_subdirectory(geometry)
add_subdirectory(gui)
add_subdirectory(misc)
add_subdirectory(observer)
add_subdirectory(plane)
add_subdirectory(utils)

# Custom target to run all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS
        core_tests
        events_tests
        geometry_tests
        gui_tests
        misc_tests
        observer_tests
        plane_tests
        utils_tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all tests..."
)