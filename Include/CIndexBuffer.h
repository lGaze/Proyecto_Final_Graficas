#pragma once
#include <D3DX11.h>

class CIndexBuffer
{
public:
	CIndexBuffer();
	~CIndexBuffer();
	UINT flag = D3D11_BIND_INDEX_BUFFER;
};

