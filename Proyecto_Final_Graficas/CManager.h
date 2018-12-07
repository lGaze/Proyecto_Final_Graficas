#pragma once
#include "CDevice.h"
#include "CDeviceContext.h"
#include "CSwapChain.h"
#include "CViewport.h"
#include "CInputLayout.h"
#include "CBuffer.h"
#include "CShader.h"
#include "CDepth.h"
#include "CTexture.h"
#include "CRenderTarget.h"
#include "CSampler.h"
#include "defines.h"
#include "CShaderProgram.h"

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
  CDepth depth;
  CTexture texture;
  CSampler sampler;
  CRenderTarget renderTarget;
  CShaderProgram shaderprogram;


public:
	CManager();
	~CManager();

#ifdef DIRECTX



	void CleanupDevice();

  HRESULT CreateRenderTargetView();

  HRESULT CreateTexture2D();

  HRESULT CreateDepthStencilView();

	HRESULT CreateVertexShader();

	HRESULT CreateInputLayout();

	HRESULT CreatePixelShader();

	HRESULT CreateBuffer(const D3D11_SUBRESOURCE_DATA *pInitialData, std::string type);

  HRESULT CreateSamplerState();

  HRESULT GetBuffer( UINT Buffer );

	HRESULT Present(UINT SyncInterval,UINT Flags);

  void OMSetRenderTargets(UINT NumViews);

	void RSSetViewports(UINT NumViewports);

	void IASetInputLayout();

	void IASetVertexBuffers(
		UINT StartSlot,
		UINT NumBuffers,
		const UINT *pStrides,
		const UINT *pOffsets);

  //Mandar Strings
	void IASetIndexBuffer(
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

	void ClearRenderTargetView(const FLOAT ColorRGBA[4]);

	void ClearDepthStencilView(
		UINT ClearFlags,
		FLOAT Depth,
		UINT8 Stencil);

	void VSSetShader(
		ID3D11ClassInstance *const *ppClassInstances,
		UINT NumClassInstances);

	void VSSetConstantBuffers(
		UINT StartSlot,
		UINT NumBuffers,
		std::string type);

	void PSSetShader(
		ID3D11ClassInstance *const *ppClassInstances,
		UINT NumClassInstances);

	void PSSetConstantBuffers(
		UINT StartSlot,
		UINT NumBuffers);

  void PSSetShaderResources(
    UINT StartSlot,
    UINT NumViews);

  void PSSetSamplers(
    UINT StartSlot,
    UINT NumSamplers);

	void DrawIndexed(
		UINT IndexCount,
		UINT StartIndexLocation,
		INT BaseVertexLocation);

	HRESULT CreateDeviceAndSwapChain();

  //Mandar Strings
  void CreateDescTexture(
    UINT Width,
    UINT Height,
    DXGI_FORMAT Format,
    D3D11_USAGE Usage
  );

  void CreateDescDSV();

  void CreateSamplerDesc();

	HRESULT Init(UINT width, UINT height, HWND  g_hWnd);

	void CreateDescBuffer(
		std::string usage,
		UINT bytewidth,
		std::string buffertype,
		UINT cpuflags);

	HRESULT CompileShaderFromFile(
		const wchar_t * szFileName,
		LPCSTR szEntryPoint,
		LPCSTR szShaderModel);

	void releasePS();
	void releaseVS();

  HRESULT loadTexture(LPCWSTR pSrcFile);

	inline D3D_DRIVER_TYPE & GetDriverTypePointer() { return *device.getDriverType(); };
	inline IDXGISwapChain ** GetSwapChainPointer() { return swapChain.getSwapChainPointer(); };
	inline ID3D11Device ** GetDevicePointer() { return device.getDevicePointer(); };


#else
 
void createRenderTarget(GLFWwindow * window);
void CreateDSV();
void createViewport();
void createVertexBuffer(std::vector<GLfloat> vertices);
void createIndexBuffer(std::vector<short> indices);
HRESULT createShaderProgram(const std::string& _VSFilePath, const std::string& _PSFilePath);

#endif 

};