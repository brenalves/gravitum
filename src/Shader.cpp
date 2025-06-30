#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    m_id = glCreateProgram();

    auto vertexShader = createShader(vertexPath, GL_VERTEX_SHADER);
    auto fragmentShader = createShader(fragmentPath, GL_FRAGMENT_SHADER);

    glAttachShader(m_id, vertexShader);
    glAttachShader(m_id, fragmentShader);
    glLinkProgram(m_id);

    int result;
    glGetProgramiv(m_id, GL_LINK_STATUS, &result);
    if(!result)
    {
        char log[512];
        glGetProgramInfoLog(m_id, 512, nullptr, log);
        std::cout << log << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    glDeleteShader(m_id);
}

void Shader::bind()
{
    glUseProgram(m_id);
}

void Shader::unbind()
{
    glUseProgram(0);
}

uint32_t Shader::createShader(const char *path, uint32_t type)
{
    uint32_t shader = glCreateShader(type);

    std::fstream shaderFile(path);

    if(!shaderFile.is_open())
    {
        // TODO: Handle invalid shader file error
    }

    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    std::string shaderString = shaderStream.str();
    const char* shaderSource = shaderString.c_str();

    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);

    int result;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if(!result)
    {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        std::cout << log << std::endl;
    }

    return shader;
}

int32_t Shader::getUniformLocation(const char *name)
{
    if(m_uniforms.find(name) == m_uniforms.end())
    {
        m_uniforms[name] = glGetUniformLocation(m_id, name);
    }

    return m_uniforms[name];
}
