#pragma once
#include "CDevice.h"
#include "CDeviceContext.h"
#include "CSwapChain.h"
#include "CViewport.h"
#include "CInputLayout.h"
#include "CBuffer.h"
#include "CShader.h"



class CManager
{
private:

	CViewport viewport;
	CDevice device;
	CDeviceContext deviceContext;
	CSwapChain swapChain;
	CInputLayout layout;
	CBuffer buffer;
	CShader shader;
	ID3D11Buffer* m_pVertexBuffer = NULL;
	ID3D11Buffer* m_pIndexBuffer = NULL;
	ID3D11Buffer* m_pCBNeverChanges = NULL;
	ID3D11Buffer* m_pCBChangeOnResize = NULL;
	ID3D11Buffer* m_pCBChangesEveryFrame = NULL;

public:
	CManager();
	~CManager();

	void CleanupDevice();

	//HRESULT InitDevice();

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
		//const void *pShaderBytecode,
		//SIZE_T BytecodeLength,
		ID3D11ClassLinkage *pClassLinkage);
		//ID3D11VertexShader **ppVertexShader);

	HRESULT CreateInputLayout(/*const void *pShaderBytecodeWithInputSignature,SIZE_T BytecodeLength*/);

	HRESULT CreatePixelShader(
		//const void *pShaderBytecode,
		//SIZE_T BytecodeLength,
		ID3D11ClassLinkage *pClassLinkage);
		//ID3D11PixelShader **ppPixelShader);

	HRESULT CreateBuffer(
		//const D3D11_BUFFER_DESC *pDesc,
		const D3D11_SUBRESOURCE_DATA *pInitialData,
		std::string type);
		//ID3D11Buffer ** ppBuffer);

	HRESULT CreateSamplerState(
		const D3D11_SAMPLER_DESC *pSamplerDesc,
		ID3D11SamplerState **ppSamplerState);

	HRESULT GetBuffer(
		UINT Buffer,
		REFIID riid,
		void **ppSurface);

	HRESULT Present(
		UINT SyncInterval,
		UINT Flags);

	void OMSetRenderTargets(
		UINT NumViews,
		ID3D11RenderTargetView *const *ppRenderTargetViews,
		ID3D11DepthStencilView *pDepthStencilView);

	void RSSetViewports(
		UINT NumViewports);

	void IASetInputLayout();

	void IASetVertexBuffers(
		UINT StartSlot,
		UINT NumBuffers,
		//ID3D11Buffer *const *ppVertexBuffers,
		const UINT *pStrides,
		const UINT *pOffsets);

	void IASetIndexBuffer(
		//ID3D11Buffer *pIndexBuffer,
		DXGI_FORMAT Format,
		UINT Offset);

	void IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

	void UpdateSubresource(
		std::string type,
		UINT DstSubresource,
		const D3D11_BOX *pDstBox,
		const void *pSrcData,
		UINT SrcRowPitch,
		UINT SrcDepthPitch);

	void ClearRenderTargetView(
		ID3D11RenderTargetView *pRenderTargetView,
		const FLOAT ColorRGBA[4]);

	void ClearDepthStencilView(
		ID3D11DepthStencilView *pDepthStencilView,
		UINT ClearFlags,
		FLOAT Depth,
		UINT8 Stencil);

	void VSSetShader(
	//	ID3D11VertexShader *pVertexShader,
		ID3D11ClassInstance *const *ppClassInstances,
		UINT NumClassInstances);

	void VSSetConstantBuffers(
		UINT StartSlot,
		UINT NumBuffers,
		std::string type);

	void PSSetShader(
		//ID3D11PixelShader *pPixelShader,
		ID3D11ClassInstance *const *ppClassInstances,
		UINT NumClassInstances);

	void PSSetConstantBuffers(
		UINT StartSlot,
		UINT NumBuffers);
		//ID3D11Buffer *const *ppConstantBuffers);

	void PSSetShaderResources(
		UINT StartSlot,
		UINT NumViews,
		ID3D11ShaderResourceView *const *ppShaderResourceViews);

	void PSSetSamplers(
		UINT StartSlot,
		UINT NumSamplers,
		ID3D11SamplerState *const *ppSamplers);

	void DrawIndexed(
		UINT IndexCount,
		UINT StartIndexLocation,
		INT BaseVertexLocation);

	HRESULT CreateDeviceAndSwapChain(
		//IDXGIAdapter* pAdapter,
		//D3D_DRIVER_TYPE DriverType,
		//HMODULE Software,
		//UINT Flags,
		//CONST D3D_FEATURE_LEVEL* pFeatureLevels,
		//UINT FeatureLevels,
		//UINT SDKVersion,
		//CONST DXGI_SWAP_CHAIN_DESC* pSwapChainDesc
		//IDXGISwapChain** ppSwapChain,
		//ID3D11Device** ppDevice
		//D3D_FEATURE_LEVEL* pFeatureLevel
		//ID3D11DeviceContext** ppImmediateContext
	);

	HRESULT Init(UINT width, UINT height, HWND  g_hWnd);

	void CreateDescBuffer(
		std::string usage,
		UINT bytewidth,
		std::string buffertype,
		UINT cpuflags);

	HRESULT CompileShaderFromFile(
		WCHAR* szFileName,
		LPCSTR szEntryPoint,
		LPCSTR szShaderModel);

	void releasePS();
	void releaseVS();

	inline D3D_DRIVER_TYPE & GetDriverTypePointer() { return *device.getDriverType(); };
	inline IDXGISwapChain ** GetSwapChainPointer() { return swapChain.getSwapChainPointer(); };
	inline ID3D11Device ** GetDevicePointer() { return device.getDevicePointer(); };
};