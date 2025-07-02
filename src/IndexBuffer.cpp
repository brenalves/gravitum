#include "IndexBuffer.h"

#include <glad/glad.h>

IndexBuffer::IndexBuffer()
    : m_count(0)
{
    glGenBuffers(1, &m_id);
}

IndexBuffer::IndexBuffer(const uint32_t* data, uint32_t size)
    : m_count(0)
{
    glGenBuffers(1, &m_id);
    pushData(data, size);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_id);
}

void IndexBuffer::pushData(const uint32_t *data, uint32_t size)
{
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    m_count = size / sizeof(uint32_t);
}

void IndexBuffer::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void IndexBuffer::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
