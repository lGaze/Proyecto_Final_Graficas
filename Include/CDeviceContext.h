#pragma once
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>

class CDeviceContext
{
public:
	CDeviceContext();
	~CDeviceContext();

	void Init();
	
	void ReleaseDeviceContext();

	void OMSetRenderTargets(
		UINT NumViews, 
		ID3D11RenderTargetView *const *ppRenderTargetViews, 
		ID3D11DepthStencilView *pDepthStencilView);

	void RSSetViewports(
		UINT NumViewports, 
		const D3D11_VIEWPORT *pViewports);

	void IASetInputLayout(ID3D11InputLayout *pInputLayout);

	void IASetVertexBuffers(
		UINT StartSlot, 
		UINT NumBuffers, 
		ID3D11Buffer *const *ppVertexBuffers, 
		const UINT *pStrides, 
		const UINT *pOffsets);

	void IASetIndexBuffer(
		ID3D11Buffer *pIndexBuffer, 
		DXGI_FORMAT Format, 
		UINT Offset);

	void IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

	void UpdateSubresource(
		ID3D11Resource *pDstResource, 
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
		ID3D11VertexShader *pVertexShader, 
		ID3D11ClassInstance *const *ppClassInstances, 
		UINT NumClassInstances);

	void VSSetConstantBuffers(
		UINT StartSlot, 
		UINT NumBuffers, 
		ID3D11Buffer *const *ppConstantBuffers);

	void PSSetShader(
		ID3D11PixelShader *pPixelShader, 
		ID3D11ClassInstance *const *ppClassInstances, 
		UINT NumClassInstances);

	void PSSetConstantBuffers(
		UINT StartSlot, 
		UINT NumBuffers, 
		ID3D11Buffer *const *ppConstantBuffers);

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

	inline ID3D11DeviceContext ** getDeviceContext() {return &m_pImmediateContext;};

private:
	ID3D11DeviceContext * m_pImmediateContext;
};

