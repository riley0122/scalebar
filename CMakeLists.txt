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

add_custom_target(test COMMAND scalebar_test DEPENDS scalebar_test tags)

# MAIN
include(./CMakeRC.cmake)

add_executable(scalebar ${sources})

# Tags
file(REMOVE_RECURSE tags)
add_custom_target(tags COMMAND npx --yes apriltag-bundler ${APRILTAG_FAMILY})
add_dependencies(scalebar tags)
add_dependencies(scalebar_test tags)
file(GLOB_RECURSE tags target/tags/*.png)
cmrc_add_resource_library(tag-resources ALIAS tags::rc NAMESPACE tags ${tags})

target_link_libraries(scalebar PRIVATE tags::rc)
target_link_libraries(scalebar_test PRIVATE tags::rc)
