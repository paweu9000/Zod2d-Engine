cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME} game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game/game.cpp
    src/backend/backend.cpp
    src/api/gl_backend.cpp
    src/api/gl_renderer.cpp
    src/core/asset_manager.cpp
    src/game/player.cpp
    src/types/shader.cpp
    src/input/input.cpp
    src/engine.cpp
    vendor/glad/glad.c
)

add_executable(hello_test
    tests/math_test.cpp
)


target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb_image
)

target_include_directories(hello_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb_image
)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/dll/libglfw3dll.a
    )

    target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)

    target_link_libraries(hello_test PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/dll/libglfw3dll.a
        opengl32
        GTest::gtest_main
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/vendor/dll/glfw3.dll
        ${CMAKE_CURRENT_BINARY_DIR}/glfw3.dll
    )
elseif (UNIX)
	find_package(glfw3 REQUIRED)
	find_package(OpenGL REQUIRED)
	target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)
    target_link_libraries(hello_test glfw OpenGL::GL GTest::gtest_main)
endif()

include(GoogleTest)
gtest_discover_tests(hello_test)