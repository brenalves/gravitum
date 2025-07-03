#version 330 core

layout (location = 0) in vec3 iPos;
layout (location = 1) in vec3 iNormal;
layout (location = 2) in vec2 iTexCoord;

out vec2 vTexCoord;
out vec3 vFragPos;
out vec3 vNormal;

uniform mat4 uProjectionMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uWorldMatrix;

void main()
{
    vTexCoord = iTexCoord;

    vFragPos = vec3(uWorldMatrix * vec4(iPos, 1.0));
    vNormal = mat3(transpose(inverse(uWorldMatrix))) * iNormal;

    gl_Position = uProjectionMatrix * uViewMatrix * vec4(vFragPos, 1.0);
}