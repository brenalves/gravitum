#include "Window.h"

#include <iostream>

Window::Window(uint16_t width, uint16_t height, const char *title)
    : m_width(width), m_height(height), m_title(title)
{
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    m_native = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

    if(!m_native)
    {
        // TODO: Handle failed window error
    }

    glfwMakeContextCurrent(m_native);
}

Window::~Window()
{
    glfwDestroyWindow(m_native);
}

void Window::update()
{
    glfwPollEvents();
}
