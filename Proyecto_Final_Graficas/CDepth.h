#pragma once
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "defines.h"

class CDepth
{
public:

  CDepth();
  ~CDepth();

#ifdef DIRECTX

  void CreateDescDSV(D3D11_TEXTURE2D_DESC descDepth);

  ID3D11Texture2D*            m_pDepthStencil = NULL;
  ID3D11DepthStencilView*     m_pDepthStencilView = NULL;
  D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;

#else

  GLuint DepthTexture;
  void createDSV(int width, int height);

#endif
};

