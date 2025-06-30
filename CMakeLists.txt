cmake_minimum_required(VERSION 3.10)

project(gravitum)

add_executable(gravitum
    src/main.cpp
    src/Window.cpp
    src/Shader.cpp
    src/VertexBuffer.cpp
    src/IndexBuffer.cpp
)

find_package(OpenGL REQUIRED)

target_link_directories(gravitum PUBLIC
    ${CMAKE_SOURCE_DIR}/deps/glfw/src
    ${CMAKE_SOURCE_DIR}/deps/glad/
)
target_link_libraries(gravitum
    glfw3
    glad
    GL
)

target_include_directories(gravitum PUBLIC
    ${CMAKE_SOURCE_DIR}/deps/glfw/include
    ${CMAKE_SOURCE_DIR}/deps/glad/include
)