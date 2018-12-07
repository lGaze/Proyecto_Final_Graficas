#pragma once
#include <D3DX11.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "defines.h"

class CViewport
{
public:
	CViewport();
	~CViewport();

#ifdef DIRECTX

	HRESULT init(UINT width, UINT height);
	void SetUpViewport(UINT width, UINT height);
	D3D11_VIEWPORT vp;

#else

  void createViewport(int width, int height);

#endif
};

