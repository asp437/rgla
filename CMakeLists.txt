cmake_minimum_required(VERSION 3.10)

project(rgla VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_DEBUG_POSTFIX d)
set(OpenGL_GL_PREFERENCE "GLVND")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g")
add_compile_options(
    "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
    "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

add_subdirectory(external)

configure_file(include/rgla_config.h.in rgla_config.h)

add_library(
    rgla
    src/window.cpp
    src/mesh.cpp
    src/shader.cpp
    src/texture.cpp
    src/math.cpp
    src/logging.cpp
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
    ${EXTERNAL_LIBS}
)

target_include_directories(
    rgla
    PUBLIC
    ${EXTERNAL_INCLUDES}
    "include"
)

set(RGLA_SHADERS_PATH "${CMAKE_SOURCE_DIR}/shaders")
add_custom_command(
    TARGET rgla POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/shaders
            ${CMAKE_BINARY_DIR}/shaders
)

add_subdirectory(demo)
