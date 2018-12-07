#pragma once
#include <windows.h>
#include <d3d11.h>


class CSwapChain
{
public:
	CSwapChain();
	~CSwapChain();

	HRESULT Init(UINT width, UINT height, HWND  g_hWnd);
	void ReleaseSwapChain();
	HRESULT GetBuffer(UINT Buffer, REFIID riid, void **ppSurface);
	HRESULT Present(UINT SyncInterval, UINT Flags);
	inline IDXGISwapChain ** getSwapChainPointer() { return &m_pSwapChain; };
	DXGI_SWAP_CHAIN_DESC createSwapChainDesc(UINT Width, UINT Height, HWND hWnd);


	DXGI_SWAP_CHAIN_DESC sd;

private:
	IDXGISwapChain * m_pSwapChain = nullptr;
};

