#include "pch.h"
#include "CRenderTarget.h"


CRenderTarget::CRenderTarget()
{
}


CRenderTarget::~CRenderTarget()
{
}
#ifdef DIRECTX


#else
void CRenderTarget::creteRenderTarget(GLFWwindow * window)
{
  glfwGetFramebufferSize(window, &width, &height);

  glGenTextures(1, &Backbuffer);
  glBindTexture(GL_TEXTURE_2D, Backbuffer);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA8, GL_UNSIGNED_BYTE, NULL);

  glBindTexture(GL_TEXTURE_2D, 0);
}
#endif // DIRECTX
