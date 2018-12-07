#pragma once
#include <D3DX11.h>

class CConstantBuffer
{
public:
	CConstantBuffer();
	~CConstantBuffer();
	UINT flag = D3D11_BIND_CONSTANT_BUFFER;
};

