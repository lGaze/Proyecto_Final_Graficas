#pragma once
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "defines.h"

class CRenderTarget
{
public:
  CRenderTarget();
  ~CRenderTarget();

#ifdef DIRECTX
  ID3D11RenderTargetView* m_pRenderTargetView = NULL;
#else

  GLuint Backbuffer;
  int width;
  int height;
  void creteRenderTarget(GLFWwindow * window);

#endif // DIRECTX

 
};

