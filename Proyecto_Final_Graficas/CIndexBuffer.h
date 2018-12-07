#pragma once
#include <D3DX11.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "defines.h"

class CIndexBuffer
{
public:
	CIndexBuffer();
	~CIndexBuffer();
#ifdef DIRECTX

	UINT flag = D3D11_BIND_INDEX_BUFFER;
#else

  GLuint index_buffer;
  void createIndexBuffer(std::vector<short>& indices);
  
#endif // DIRECTX
};

