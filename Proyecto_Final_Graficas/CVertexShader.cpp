#include "pch.h"
#include "CVertexShader.h"



CVertexShader::CVertexShader()
{
}


CVertexShader::~CVertexShader()
{
}

void CVertexShader::release()
{
	m_pVertexShader->Release();
}
