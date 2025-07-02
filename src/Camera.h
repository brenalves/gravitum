#pragma once

#include <glm/glm.hpp>

#include "Transform.h"

struct Camera
{
    Camera(float fov = 60.0f, float aspectRatio = 4.0f/3.0f, float nearPlane = 0.1f, float farPlane = 1000.0f);

    void update();

    Transform transform;

    float fov;
    float aspectRatio;
    float nearPlane;
    float farPlane;

    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
};