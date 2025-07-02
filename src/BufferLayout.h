#pragma once

#include <cstdint>
#include <vector>
#include <glad/glad.h>

struct BufferElement
{
    int32_t count;
    int32_t type;
    bool normalized;
    uint32_t size;
};

class BufferLayout
{
public:
    BufferLayout() : m_stride(0) {}
    ~BufferLayout() {}

    template <typename T>
    void push(int32_t count, bool normalized);

    inline std::vector<BufferElement>&  getElements()    { return m_elements; }
    inline uint32_t                     getStride()      { return m_stride; }

private:
    std::vector<BufferElement> m_elements;
    uint32_t m_stride;
};

template <typename T>
inline void BufferLayout::push(int32_t count, bool normalized)
{
}

template <>
inline void BufferLayout::push<float>(int32_t count, bool normalized)
{
    m_elements.push_back({ count, GL_FLOAT, normalized, sizeof(float) });
    m_stride += count * sizeof(float);
}
