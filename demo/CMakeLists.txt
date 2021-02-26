add_executable(
    rgla_demo
    src/main.cpp
    src/rgla_application.cpp
)

target_link_libraries(
    rgla_demo
    rgla
)

target_include_directories(
    rgla_demo
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_custom_command(
    TARGET rgla_demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/res
            ${CMAKE_CURRENT_BINARY_DIR}/res
)

add_custom_command(
    TARGET rgla_demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${RGLA_SHADERS_PATH}
            ${CMAKE_CURRENT_BINARY_DIR}/shaders
)
