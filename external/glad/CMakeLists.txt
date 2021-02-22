add_library(GLAD src/glad.c)

target_include_directories(
    GLAD
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(
    GLAD
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

list(APPEND EXTERNAL_LIBS GLAD)
list(APPEND EXTERNAL_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(EXTERNAL_LIBS ${EXTERNAL_LIBS} PARENT_SCOPE)
set(EXTERNAL_INCLUDES ${EXTERNAL_INCLUDES} PARENT_SCOPE)

message(STATUS "external/glad/CMakeLists.txt external_includes: ${EXTERNAL_INCLUDES}")
