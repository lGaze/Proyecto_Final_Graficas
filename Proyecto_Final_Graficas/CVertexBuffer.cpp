#include "pch.h"
#include "CVertexBuffer.h"




CVertexBuffer::CVertexBuffer()
{
}


CVertexBuffer::~CVertexBuffer()
{
}
#ifdef DIRECTX


#elif defined( OPENGL)

void CVertexBuffer::createVertexBuffer(std::vector<GLfloat> vertices)
{

  glGenBuffers(1, &vertex_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);
  glBindVertexArray(0);
}

#endif