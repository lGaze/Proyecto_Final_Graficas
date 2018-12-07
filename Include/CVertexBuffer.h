#pragma once
#include <D3DX11.h>

class CVertexBuffer
{
public:
	CVertexBuffer();
	~CVertexBuffer();
	UINT flag = D3D11_BIND_VERTEX_BUFFER;
};

