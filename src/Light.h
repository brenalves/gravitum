#pragma once

#include <glm/glm.hpp>

#include "Transform.h"

struct Light
{
    Light() : ambient(0.2f), diffuse(0.5f), specular(1.0f), constant(1.0f), linear(0.09f), quadratic(0.032f) {}

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

    float constant;
    float linear;
    float quadratic;
};