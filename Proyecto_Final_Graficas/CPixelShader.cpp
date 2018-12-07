#include "pch.h"
#include "CPixelShader.h"



CPixelShader::CPixelShader()
{
}


CPixelShader::~CPixelShader()
{
}

void CPixelShader::release()
{
	m_pPixelShader->Release();
}
