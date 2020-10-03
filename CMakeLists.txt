cmake_minimum_required(VERSION 3.10)

project(rgla VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g")
add_compile_options(
    "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
    "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

configure_file(include/rgla_config.h.in rgla_config.h)

add_executable(
    rgla
    src/glad.c
    src/main.cpp
    src/window.cpp
    src/rgla_application.cpp
    src/mesh.cpp
    src/shader.cpp
    src/texture.cpp
    src/math.cpp
)
set_target_properties(rgla PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
target_link_libraries(
    rgla
    glfw
    dl
    glm
    OpenGL::GL
)

target_include_directories(
    rgla
    PUBLIC
    "${PROJECT_BINARY_DIR}"
    "include"
)

add_custom_command(
    TARGET rgla POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/shaders
            ${CMAKE_BINARY_DIR}/shaders
)

add_custom_command(
    TARGET rgla POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/res
            ${CMAKE_BINARY_DIR}/res
)
