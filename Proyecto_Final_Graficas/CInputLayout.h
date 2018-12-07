#pragma once
#include <D3DX11.h>

class CInputLayout
{
public:
	CInputLayout();
	~CInputLayout();
	HRESULT Init();
	void defineInputLayout();
	UINT numElements;

	D3D11_INPUT_ELEMENT_DESC * lay;

	ID3D11InputLayout * m_pVertexLayout;
};

