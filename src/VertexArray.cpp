#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_id);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_id);
}

void VertexArray::setBuffer(VertexBuffer &vb, BufferLayout &layout)
{
    bind();
    vb.bind();

    auto& elements = layout.getElements();
    uint32_t offset = 0;
    
    for(int i = 0; i < elements.size(); i++)
    {
        auto& e = elements[i];
        glVertexAttribPointer(i, e.count, e.type, e.normalized, layout.getStride(), (void**)(offset));
        glEnableVertexAttribArray(i);
        offset += e.count * e.size;
    }
}

void VertexArray::bind()
{
    glBindVertexArray(m_id);
}

void VertexArray::unbind()
{
    glBindVertexArray(0);
}
