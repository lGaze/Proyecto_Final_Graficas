#pragma once
#include <D3DX11.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "defines.h"

class CVertexBuffer
{
public:
	CVertexBuffer();
	~CVertexBuffer();

#ifdef DIRECTX;
	UINT flag = D3D11_BIND_VERTEX_BUFFER;
#else

  GLuint vertex_buffer;
  void createVertexBuffer(std::vector<GLfloat> vertices);

#endif
};

