add_library(GLAD src/glad.c)

target_include_directories(
    GLAD
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

list(APPEND EXTERNAL_LIBS GLAD)
set(EXTERNAL_LIBS ${EXTERNAL_LIBS} PARENT_SCOPE)
