#include "pch.h"
#include "CDepth.h"


CDepth::CDepth()
{
}


CDepth::~CDepth()
{
}

#ifdef DIRECTX
void CDepth::CreateDescDSV(D3D11_TEXTURE2D_DESC descDepth)
{
  ZeroMemory(&descDSV, sizeof(descDSV));
  descDSV.Format = descDepth.Format;
  descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
  descDSV.Texture2D.MipSlice = 0;

}

#elif defined(OPENGL)

void CDepth::createDSV(int width , int height)
{
  glGenTextures(1, &DepthTexture);
  glBindTexture(GL_TEXTURE_2D, DepthTexture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);

  glBindTexture(GL_TEXTURE_2D, 0);
}
#else

#endif