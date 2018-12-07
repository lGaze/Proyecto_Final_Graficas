#include "pch.h"
#include "CDevice.h"


CDevice::CDevice()
{
}

CDevice::~CDevice()
{
}

HRESULT CDevice::Init()
{
	HRESULT hr = S_OK;

	deviceFlags = 0;
#ifdef _DEBUG
	deviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	sdk = D3D11_SDK_VERSION;

	return hr;
}

void CDevice::ReleaseDevice()
{
	m_pd3dDevice->Release();
}

HRESULT CDevice::CreateRenderTargetView(
	ID3D11Resource * pResource, 
	const D3D11_RENDER_TARGET_VIEW_DESC * pDesc, 
	ID3D11RenderTargetView ** ppRTView)
{
	return m_pd3dDevice->CreateRenderTargetView(pResource, pDesc, ppRTView);
}

HRESULT CDevice::CreateTexture2D(
	const D3D11_TEXTURE2D_DESC * pDesc, 
	const D3D11_SUBRESOURCE_DATA * pInitialData, 
	ID3D11Texture2D ** ppTexture2D)
{
	return m_pd3dDevice->CreateTexture2D(pDesc, pInitialData, ppTexture2D);
}

HRESULT CDevice::CreateDepthStencilView(
	ID3D11Resource * pResource, 
	const D3D11_DEPTH_STENCIL_VIEW_DESC * pDesc, 
	ID3D11DepthStencilView ** ppDepthStencilView)
{
	return m_pd3dDevice->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView);
}

HRESULT CDevice::CreateVertexShader(
	const void * pShaderBytecode, 
	SIZE_T BytecodeLength, 
	ID3D11ClassLinkage * pClassLinkage, 
	ID3D11VertexShader ** ppVertexShader)
{
	return m_pd3dDevice->CreateVertexShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppVertexShader);
}

HRESULT CDevice::CreateInputLayout(
	const D3D11_INPUT_ELEMENT_DESC * pInputElementDescs, 
	UINT NumElements, 
	const void * pShaderBytecodeWithInputSignature, 
	SIZE_T BytecodeLength, 
	ID3D11InputLayout ** ppInputLayout)
{
	return m_pd3dDevice->CreateInputLayout(pInputElementDescs, NumElements, pShaderBytecodeWithInputSignature, BytecodeLength, ppInputLayout);
}

HRESULT CDevice::CreatePixelShader(
	const void * pShaderBytecode, 
	SIZE_T BytecodeLength, 
	ID3D11ClassLinkage * pClassLinkage, 
	ID3D11PixelShader ** ppPixelShader)
{
	return m_pd3dDevice->CreatePixelShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppPixelShader);
}

HRESULT CDevice::CreateBuffer(
	const D3D11_BUFFER_DESC * pDesc, 
	const D3D11_SUBRESOURCE_DATA * pInitialData, 
	ID3D11Buffer ** ppBuffer)
{
	return m_pd3dDevice->CreateBuffer(pDesc, pInitialData, ppBuffer);
}

HRESULT CDevice::CreateSamplerState(
	const D3D11_SAMPLER_DESC * pSamplerDesc, 
	ID3D11SamplerState ** ppSamplerState)
{
	return m_pd3dDevice->CreateSamplerState(pSamplerDesc, ppSamplerState);
}