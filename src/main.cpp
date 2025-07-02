#include <iostream>
#include <glad/glad.h>

#include "Window.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferLayout.h"
#include "VertexArray.h"
#include "Camera.h"

int main()
{
    if(!glfwInit())
    {
        // TODO: Handle failed to initialize glfw error
    }

    std::cout << "Hello World" << std::endl;

    bool running = true;

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

        BufferLayout layout;
        layout.push<float>(3, false);

        VertexArray va;
        va.setBuffer(vb, layout);

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };
        IndexBuffer ib(indices, sizeof(indices));

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
        while(running)
        {
            running = !window.shouldClose();

            window.update();
    
            glClear(GL_COLOR_BUFFER_BIT);
    
            shader.bind();
            va.bind();
            ib.bind();
            glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
    
            glfwSwapBuffers(window.getNative());
        }
    }

    glfwTerminate();

    return 0;
}