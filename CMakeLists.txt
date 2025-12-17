CMAKE_MINIMUM_REQUIRED(VERSION 3.31)

# Set CMAKE settings
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_STANDARD 20)

set(APRILTAG_FAMILY 25h9)
add_compile_definitions(TAG_FAMILY=\"${APRILTAG_FAMILY}\")

project(Scalebar)

# Get files
file(GLOB_RECURSE sources src/*.cpp src/*.hpp)
file(GLOB_RECURSE sources_test test/*.cpp test/*.hpp)

# TEST
add_executable(scalebar_test ${sources_test})
add_test(NAME scalebar_test COMMAND scalebar_test)

add_custom_target(test COMMAND scalebar_test DEPENDS scalebar_test)

# MAIN
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/vendored/SDL)
if(WIN32)
    execute_process(COMMAND cmd /c "git clone https://github.com/libsdl-org/SDL.git ../vendored/SDL")
elseif(UNIX)
    execute_process(COMMAND ${CMAKE_COMMAND} -E env bash -c "git clone https://github.com/libsdl-org/SDL.git ../vendored/SDL")
else()
    message(FATAL_ERROR Platform not supported.)
endif()
endif()
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

add_executable(scalebar ${sources})
target_link_libraries(scalebar PRIVATE SDL3::SDL3)
target_link_libraries(scalebar_test PRIVATE SDL3::SDL3)

# Tags
include(./CMakeRC.cmake)

if(WIN32)
    execute_process(COMMAND cmd /c "npx --yes apriltag-bundler 25h9")
elseif(UNIX)
    execute_process(COMMAND ${CMAKE_COMMAND} -E env bash -c "npx --yes apriltag-bundler 25h9")
else()
    message(FATAL_ERROR Platform not supported.)
endif()
file(GLOB_RECURSE tags target/tags/*.png)
cmrc_add_resource_library(tag-resources ALIAS tags::rc NAMESPACE tags WHENCE target/tags PREFIX tags ${tags})

target_link_libraries(scalebar PRIVATE tags::rc)
target_link_libraries(scalebar_test PRIVATE tags::rc)
