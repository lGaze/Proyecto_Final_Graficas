#pragma once
#include <iostream>
#include <D3DX11.h>
#include "CConstantBuffer.h"
#include "CVertexBuffer.h"
#include "CIndexBuffer.h"

class CBuffer
{
public:
	CBuffer();
	~CBuffer();

	void CreateDescBuffer(
		std::string usage, 
		UINT bytewidth, 
		std::string buffertype, 
		UINT cpuflags);

	D3D11_BUFFER_DESC bd;

private:
	CConstantBuffer constant;
	CVertexBuffer vertex;
	CIndexBuffer index;
};

