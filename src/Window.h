#pragma once

#include <cstdint>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(uint16_t width, uint16_t height, const char* title);
    ~Window();

    void update();

    inline bool shouldClose() { return glfwWindowShouldClose(m_native); }

    inline GLFWwindow*  getNative()     { return m_native; }
    inline uint16_t     getWidth()      { return m_width; }
    inline uint16_t     getHeight()     { return m_height; }
    inline const char*  getTitle()      { return m_title; }
    
private:
    GLFWwindow* m_native;
    uint16_t m_width;
    uint16_t m_height;
    const char* m_title;
};