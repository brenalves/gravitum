#version 330 core

layout (location = 0) in vec3 iPos;
layout (location = 1) in vec3 iNormal;
layout (location = 2) in vec2 iTexCoord;

out vec2 vTexCoord;

uniform mat4 uProjectionMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uWorldMatrix;

void main()
{
    gl_Position = uProjectionMatrix * uViewMatrix * uWorldMatrix * vec4(iPos, 1.0);
    vTexCoord = iTexCoord;
}