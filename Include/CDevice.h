#pragma once
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <D3Dcommon.h>


class CDevice
{
public:

	CDevice();
	~CDevice();

	HRESULT Init();

	void ReleaseDevice();

	HRESULT CreateRenderTargetView(
		ID3D11Resource *pResource,
		const D3D11_RENDER_TARGET_VIEW_DESC *pDesc,
		ID3D11RenderTargetView **ppRTView);

	HRESULT CreateTexture2D(
		const D3D11_TEXTURE2D_DESC *pDesc,
		const D3D11_SUBRESOURCE_DATA *pInitialData,
		ID3D11Texture2D **ppTexture2D);

	HRESULT CreateDepthStencilView(
		ID3D11Resource *pResource,
		const D3D11_DEPTH_STENCIL_VIEW_DESC *pDesc,
		ID3D11DepthStencilView **ppDepthStencilView);

	HRESULT CreateVertexShader(
		const void *pShaderBytecode,
		SIZE_T BytecodeLength,
		ID3D11ClassLinkage *pClassLinkage,
		ID3D11VertexShader **ppVertexShader);

	HRESULT CreateInputLayout(
		const D3D11_INPUT_ELEMENT_DESC *pInputElementDescs,
		UINT NumElements,
		const void *pShaderBytecodeWithInputSignature,
		SIZE_T BytecodeLength,
		ID3D11InputLayout **ppInputLayout);

	HRESULT CreatePixelShader(
		const void *pShaderBytecode,
		SIZE_T BytecodeLength,
		ID3D11ClassLinkage *pClassLinkage,
		ID3D11PixelShader **ppPixelShader);

	HRESULT CreateBuffer(
		const D3D11_BUFFER_DESC *pDesc,
		const D3D11_SUBRESOURCE_DATA *pInitialData,
		ID3D11Buffer **ppBuffer);

	HRESULT CreateSamplerState(
		const D3D11_SAMPLER_DESC *pSamplerDesc,
		ID3D11SamplerState **ppSamplerState);

	inline ID3D11Device ** getDevicePointer() { return &m_pd3dDevice; };
	inline D3D_DRIVER_TYPE * getDriverType() { return &m_driverType; };
	inline D3D_FEATURE_LEVEL * getFeatureLevel() { return &m_featureLevel; };

	D3D_DRIVER_TYPE driverTypes[3] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};

	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevels[3] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	UINT deviceFlags;
	int sdk;

private:
	ID3D11Device *		m_pd3dDevice = nullptr;
	D3D_DRIVER_TYPE		m_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL	m_featureLevel = D3D_FEATURE_LEVEL_11_0;
};

