#include "pch.h"
#include "CInputLayout.h"


CInputLayout::CInputLayout()
{
}


CInputLayout::~CInputLayout()
{
}

HRESULT CInputLayout::Init()
{
	HRESULT hr = S_OK;
	m_pVertexLayout = NULL;
	lay = new D3D11_INPUT_ELEMENT_DESC[2];
	defineInputLayout();
	return hr;
}

void CInputLayout::defineInputLayout()
{


	D3D11_INPUT_ELEMENT_DESC layout1 = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 };
	D3D11_INPUT_ELEMENT_DESC layout2 = { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 };
	lay[0] = layout1;
	lay[1] = layout2;

	numElements = 2;
}
