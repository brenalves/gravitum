#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, float aspectRatio, float nearPlane, float farPlane)
    : fov(fov), aspectRatio(aspectRatio), nearPlane(nearPlane), farPlane(farPlane), projectionMatrix(1.0f), viewMatrix(1.0f)
{
}

void Camera::update()
{
    transform.update();

    projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
    viewMatrix = glm::lookAt(transform.position, transform.position + transform.forward, transform.up);
}