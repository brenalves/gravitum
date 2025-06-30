#pragma once

#include <cstdint>

class VertexBuffer
{
public:
    VertexBuffer();
    VertexBuffer(const void* data, uint32_t size);
    ~VertexBuffer();

    void pushData(const void* data, uint32_t size);

    void bind();
    void unbind();

private:
    uint32_t m_id;
};