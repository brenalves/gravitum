cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0072 NEW)

project(gravitum)

add_executable(gravitum
    src/main.cpp
    src/Window.cpp
    src/Shader.cpp
    src/VertexBuffer.cpp
    src/IndexBuffer.cpp
    src/VertexArray.cpp
    src/Camera.cpp
    src/Transform.cpp
    src/Texture.cpp
)

find_package(OpenGL REQUIRED)

target_link_directories(gravitum PUBLIC
    ${CMAKE_SOURCE_DIR}/deps/glfw/src
    ${CMAKE_SOURCE_DIR}/deps/glad/
    ${CMAKE_SOURCE_DIR}/deps/stb_image
)

target_link_libraries(gravitum
    glfw3
    glad
    stb_image
    GL
)

target_include_directories(gravitum PUBLIC
    ${CMAKE_SOURCE_DIR}/deps/glfw/include
    ${CMAKE_SOURCE_DIR}/deps/glad/include
    ${CMAKE_SOURCE_DIR}/deps/glm/include
    ${CMAKE_SOURCE_DIR}/deps/stb_image/include
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    ${CMAKE_CURRENT_BINARY_DIR}/assets
)