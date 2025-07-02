#include <iostream>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferLayout.h"
#include "VertexArray.h"
#include "Camera.h"
#include "Texture.h"

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

        BufferLayout layout;
        layout.push<float>(3, false);
        layout.push<float>(3, false);
        layout.push<float>(2, false);

        float cubeVertices[] = {
            // positions          // normals           // texture coords
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
        };
        VertexBuffer cubeVB(cubeVertices, sizeof(cubeVertices));

        VertexArray cubeVA;
        cubeVA.setBuffer(cubeVB, layout);

        unsigned int cubeIndices[] = {
            0, 1, 2, 3, 4, 5,
            6, 7, 8, 9, 10, 11,
            12, 13, 14, 15, 16, 17,
            18, 19, 20, 21, 22, 23,
            24, 25, 26, 27, 28, 29,
            30, 31, 32, 33, 34, 35
        };
        IndexBuffer cubeIB(cubeIndices, sizeof(cubeIndices));

        Texture cubeTexture("assets/textures/box.jpg");

        float quadVertices[] = {
            -2.5f, -2.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            -2.5f,  2.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
             2.5f,  2.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
             2.5f, -2.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f
        };
        VertexBuffer quadVB(quadVertices, sizeof(quadVertices));

        VertexArray quadVA;
        quadVA.setBuffer(quadVB, layout);

        unsigned int quadIndices[] = {
            0, 1, 2,
            2, 3, 0
        };
        IndexBuffer quadIB(quadIndices, sizeof(quadIndices));

        Texture quadTexture("assets/textures/wall.jpg");

        Camera camera;
        Transform cubeTransform;
        Transform quadTransform;

        camera.transform.position.z = 10.0f;
        quadTransform.position.y = -3.0f;
        quadTransform.rotation.x = 90.0f;

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glEnable(GL_DEPTH_TEST);
    
        while(running)
        {
            running = !window.shouldClose();

            window.update();

            camera.update();
            cubeTransform.update();
            quadTransform.update();

            cubeTransform.rotation.x += 1.0f;
            cubeTransform.rotation.y += 0.75f;

            cubeTransform.position.x = sin(glfwGetTime());
            cubeTransform.position.y = cos(glfwGetTime());
    
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);            

            shader.bind();
            shader.setUniformMatrix4f("uProjectionMatrix", glm::value_ptr(camera.projectionMatrix));
            shader.setUniformMatrix4f("uViewMatrix", glm::value_ptr(camera.viewMatrix));
            
            shader.bind();
            shader.setUniformMatrix4f("uWorldMatrix", glm::value_ptr(cubeTransform.worldMatrix));
            cubeTexture.bind();
            shader.setUniform1i("uTexture", 0);
            cubeVA.bind();
            cubeIB.bind();
            glDrawElements(GL_TRIANGLES, cubeIB.getCount(), GL_UNSIGNED_INT, nullptr);

            shader.bind();
            shader.setUniformMatrix4f("uWorldMatrix", glm::value_ptr(quadTransform.worldMatrix));
            quadTexture.bind();
            shader.setUniform1i("uTexture", 0);
            quadVA.bind();
            quadIB.bind();
            glDrawElements(GL_TRIANGLES, quadIB.getCount(), GL_UNSIGNED_INT, nullptr);
    
            glfwSwapBuffers(window.getNative());
        }
    }

    glfwTerminate();

    return 0;
}