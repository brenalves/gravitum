#pragma once

#include "VertexBuffer.h"
#include "BufferLayout.h"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void setBuffer(VertexBuffer& vb, BufferLayout& layout);

    void bind();
    void unbind();

private:
    uint32_t m_id;
};