cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME} game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/backend/backend.cpp
    src/api/gl_backend.cpp
    src/api/gl_renderer.cpp
    src/core/asset_manager.cpp
    src/types/shader.cpp
    vendor/glad/glad.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb_image
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/dll/libglfw3dll.a
)

target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/vendor/dll/glfw3.dll
    ${CMAKE_CURRENT_BINARY_DIR}/glfw3.dll
)