#pragma once
#include <D3DX11.h>

class CViewport
{
public:
	CViewport();
	~CViewport();
	HRESULT init(UINT width, UINT height);
	void SetUpViewport(UINT width, UINT height);
	D3D11_VIEWPORT vp;
};

