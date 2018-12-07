#pragma once
#include <D3D11.h>

class CPixelShader
{
public:

	CPixelShader();
	~CPixelShader();

	inline ID3D11PixelShader ** getInterface() { return &m_pPixelShader; };
	void release();
private:
	ID3D11PixelShader  *   m_pPixelShader = NULL;
};

