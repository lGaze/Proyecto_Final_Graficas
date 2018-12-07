#include "pch.h"
#include "CViewport.h"


CViewport::CViewport()
{
}

CViewport::~CViewport()
{
}
#ifdef DIRECTX

HRESULT CViewport::init(UINT width, UINT height)
{
	HRESULT hr = S_OK;
	SetUpViewport(width, height);
	return hr;
}

void CViewport::SetUpViewport(UINT width, UINT height)
{

	vp.Width = (FLOAT)width;
	vp.Height = (FLOAT)height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

}

#else
void CViewport::createViewport(int width, int height)
{
  glViewport(0.0f, 0.0f, width, height);
}

#endif // DIRECTX