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
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_custom_command(
    TARGET rgla_demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/res
            ${CMAKE_CURRENT_BINARY_DIR}/res
)
