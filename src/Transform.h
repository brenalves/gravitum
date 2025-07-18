#pragma once

#include <glm/glm.hpp>

struct Transform
{
    Transform(glm::vec3 position = glm::vec3(0.0f), glm::vec3 rotation = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f));

    void update();

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    glm::vec3 forward;
    glm::vec3 right;
    glm::vec3 up;

    glm::mat4 worldMatrix;
};