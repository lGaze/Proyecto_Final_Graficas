#include "pch.h"
#include "CSwapChain.h"


CSwapChain::CSwapChain()
{
}


CSwapChain::~CSwapChain()
{
}

HRESULT CSwapChain::Init(UINT width, UINT height, HWND  g_hWnd)
{
	HRESULT hr = S_OK;
	sd = createSwapChainDesc(width, height, g_hWnd);
	return hr;
}

void CSwapChain::ReleaseSwapChain()
{
	m_pSwapChain->Release();
}

HRESULT CSwapChain::GetBuffer(UINT Buffer, REFIID riid, void ** ppSurface)
{
	return m_pSwapChain->GetBuffer(Buffer, riid, ppSurface);
}

HRESULT CSwapChain::Present(UINT SyncInterval, UINT Flags)
{
	return m_pSwapChain->Present(SyncInterval, Flags);
}

DXGI_SWAP_CHAIN_DESC CSwapChain::createSwapChainDesc(UINT Width, UINT Height, HWND hWnd)
{
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = Width;
	sd.BufferDesc.Height = Height;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	return sd;
}

