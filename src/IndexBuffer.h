#pragma once

#include <cstdint>

class IndexBuffer
{
public:
    IndexBuffer();
    IndexBuffer(const uint32_t* data, uint32_t size);
    ~IndexBuffer();

    void pushData(const uint32_t* data, uint32_t size);

    void bind();
    void unbind();

private:
    uint32_t m_id;
};