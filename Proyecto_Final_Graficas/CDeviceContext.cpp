#include "pch.h"
#include "CDeviceContext.h"


CDeviceContext::CDeviceContext()
{
}


CDeviceContext::~CDeviceContext()
{
}

void CDeviceContext::Init()
{
	m_pImmediateContext = nullptr;
}

void CDeviceContext::ReleaseDeviceContext()
{
	m_pImmediateContext->Release();
}

void CDeviceContext::OMSetRenderTargets(
	UINT NumViews, 
	ID3D11RenderTargetView * const * ppRenderTargetViews, 
	ID3D11DepthStencilView * pDepthStencilView)
{
	m_pImmediateContext->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
}

void CDeviceContext::RSSetViewports(
	UINT NumViewports, 
	const D3D11_VIEWPORT * pViewports)
{
	m_pImmediateContext->RSSetViewports(NumViewports, pViewports);
}

void CDeviceContext::IASetInputLayout(ID3D11InputLayout * pInputLayout)
{
	m_pImmediateContext->IASetInputLayout(pInputLayout);
}

void CDeviceContext::IASetVertexBuffers(
	UINT StartSlot, 
	UINT NumBuffers, 
	ID3D11Buffer * const * ppVertexBuffers, 
	const UINT * pStrides, 
	const UINT * pOffsets)
{
	m_pImmediateContext->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}

void CDeviceContext::IASetIndexBuffer(
	ID3D11Buffer * pIndexBuffer, 
	DXGI_FORMAT Format, 
	UINT Offset)
{
	m_pImmediateContext->IASetIndexBuffer(pIndexBuffer, Format, Offset);
}

void CDeviceContext::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology)
{
	m_pImmediateContext->IASetPrimitiveTopology(Topology);
}

void CDeviceContext::UpdateSubresource(
	ID3D11Resource * pDstResource, 
	UINT DstSubresource, 
	const D3D11_BOX * pDstBox, 
	const void * pSrcData, 
	UINT SrcRowPitch, 
	UINT SrcDepthPitch)
{
	m_pImmediateContext->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
}

void CDeviceContext::ClearRenderTargetView(
	ID3D11RenderTargetView * pRenderTargetView, 
	const FLOAT ColorRGBA[4])
{
	m_pImmediateContext->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
}

void CDeviceContext::ClearDepthStencilView(
	ID3D11DepthStencilView * pDepthStencilView, 
	UINT ClearFlags, 
	FLOAT Depth, 
	UINT8 Stencil)
{
	m_pImmediateContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
}

void CDeviceContext::VSSetShader(
	ID3D11VertexShader * pVertexShader, 
	ID3D11ClassInstance * const * ppClassInstances, 
	UINT NumClassInstances)
{
	m_pImmediateContext->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
}

void CDeviceContext::VSSetConstantBuffers(
	UINT StartSlot, 
	UINT NumBuffers, 
	ID3D11Buffer * const * ppConstantBuffers)
{
	m_pImmediateContext->VSSetConstantBuffers(
		StartSlot, 
		NumBuffers, 
		ppConstantBuffers);
}

void CDeviceContext::PSSetShader(
	ID3D11PixelShader * pPixelShader, 
	ID3D11ClassInstance * const * ppClassInstances, 
	UINT NumClassInstances)
{
	m_pImmediateContext->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
}

void CDeviceContext::PSSetConstantBuffers(
	UINT StartSlot, 
	UINT NumBuffers, 
	ID3D11Buffer * const * ppConstantBuffers)
{
	m_pImmediateContext->PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void CDeviceContext::PSSetShaderResources(
	UINT StartSlot, 
	UINT NumViews, 
	ID3D11ShaderResourceView * const * ppShaderResourceViews)
{
	m_pImmediateContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void CDeviceContext::PSSetSamplers(
	UINT StartSlot, 
	UINT NumSamplers, 
	ID3D11SamplerState * const * ppSamplers)
{
	m_pImmediateContext->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void CDeviceContext::DrawIndexed(
	UINT IndexCount, 
	UINT StartIndexLocation, 
	INT BaseVertexLocation)
{
	m_pImmediateContext->DrawIndexed(
		IndexCount, 
		StartIndexLocation, 
		BaseVertexLocation);
}
