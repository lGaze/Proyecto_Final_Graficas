#pragma once
#include <D3DX11.h>

class CVertexShader
{
public:
	CVertexShader();
	~CVertexShader();

	inline ID3D11VertexShader ** getInterface() { return &m_pVertexShader; };
	void release();

private:
	ID3D11VertexShader *  m_pVertexShader = NULL;
};

