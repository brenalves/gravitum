#include <iostream>
#include <glad/glad.h>

#include "Window.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

int main()
{
    if(!glfwInit())
    {
        // TODO: Handle failed to initialize glfw error
    }

    std::cout << "Hello World" << std::endl;

    Window window(800, 600, "Gravitum Window");

    if(!gladLoadGL())
    {
        // TODO: Handle failed to initialize glad error
    }

    {
        Shader shader("assets/shaders/basic.vert", "assets/shaders/basic.frag");

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f,
             0.5f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
        };
        VertexBuffer vb(vertices, sizeof(vertices));

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };
        IndexBuffer ib(indices, sizeof(indices));
    
        while(!window.shouldClose())
        {
            window.update();
    
            glClear(GL_COLOR_BUFFER_BIT);
    
            shader.bind();
            vb.bind();
            ib.bind();
    
            glfwSwapBuffers(window.getNative());
        }
    }

    glfwTerminate();

    return 0;
}