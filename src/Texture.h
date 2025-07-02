#pragma once

#include <stb_image.h>
#include <cstdint>
#include <glad/glad.h>

class Texture
{
public:
    Texture(const char* path);
    ~Texture();

    void bind(uint32_t slot = 0);
    void unbind();

    void setFiltering(int32_t minFilter, int32_t magFilter);
    void setWrapping(int32_t wrapS, int32_t wrapT);

private:
    uint32_t m_id;
    int32_t m_width;
    int32_t m_height;
    int32_t m_channels;
};