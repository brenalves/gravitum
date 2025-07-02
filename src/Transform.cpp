#include "Transform.h"

#include <glm/gtc/matrix_transform.hpp>

Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
    : position(position), rotation(rotation), scale(scale), worldMatrix(1.0f)
{
}

void Transform::update()
{
    forward.z = cos(glm::radians(rotation.x - 90.0f)) * cos(glm::radians(rotation.y));
    forward.y = sin(glm::radians(rotation.y));
    forward.z = sin(glm::radians(rotation.x - 90.0f)) * cos(glm::radians(rotation.y));
    forward = glm::normalize(forward);

    right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
    up = glm::normalize(glm::cross(right, forward));

    worldMatrix = glm::mat4(1.0f);
    worldMatrix = glm::translate(worldMatrix, position);
    worldMatrix = glm::rotate(worldMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    worldMatrix = glm::rotate(worldMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    worldMatrix = glm::rotate(worldMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    worldMatrix = glm::scale(worldMatrix, scale);
}