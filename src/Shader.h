#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <glad/glad.h>

class Shader
{
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void bind();
    void unbind();

    inline void setUniform1f(const char* name, float v)             { glUniform1f(getUniformLocation(name), v); }
    inline void setUniform1i(const char* name, int v)               { glUniform1i(getUniformLocation(name), v); }
    inline void setUniform3f(const char* name, float* v)            { glUniform3fv(getUniformLocation(name), 1, v); }
    inline void setUniform4f(const char* name, float* v)            { glUniform4fv(getUniformLocation(name), 1, v); }
    inline void setUniformMatrix4f(const char* name, float* v)      { glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, v); }

private:
    uint32_t createShader(const char* path, uint32_t type);
    int32_t getUniformLocation(const char* name);

private:
    uint32_t m_id;
    std::map<std::string, int32_t> m_uniforms;
};