add_library(GLAD STATIC src/glad.c)

target_include_directories(
    GLAD
    SYSTEM
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(GLAD PRIVATE "-w")

list(APPEND EXTERNAL_LIBS GLAD)
set(EXTERNAL_LIBS ${EXTERNAL_LIBS} PARENT_SCOPE)
