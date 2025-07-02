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

    inline uint32_t getCount() { return m_count; }

private:
    uint32_t m_id;
    uint32_t m_count;
};