#include "pch.h"
#include "CIndexBuffer.h"



CIndexBuffer::CIndexBuffer()
{
}


CIndexBuffer::~CIndexBuffer()
{
}

#ifdef DIRECTX

#else


void CIndexBuffer::createIndexBuffer(std::vector<short>& indices)
{

    glGenBuffers(1, &index_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
    glBindVertexArray(0);
}
#endif // DIRECTX