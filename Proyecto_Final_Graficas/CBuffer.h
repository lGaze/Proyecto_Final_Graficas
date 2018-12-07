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

  ID3D11Buffer* m_pVertexBuffer = NULL;
  ID3D11Buffer* m_pIndexBuffer = NULL;
  ID3D11Buffer* m_pCBNeverChanges = NULL;
  ID3D11Buffer* m_pCBChangeOnResize = NULL;
  ID3D11Buffer* m_pCBChangesEveryFrame = NULL;
	CVertexBuffer vertex;
	CIndexBuffer index;
	CConstantBuffer constant;


};

