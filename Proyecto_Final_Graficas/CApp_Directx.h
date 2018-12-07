#pragma once
#include "CApp.h"
#include "CManager.h"
#include <windows.h>
#include <xnamath.h>
#include "defines.h"



#ifdef DIRECTX


class CApp_Directx : public CApp
{
public:
	CApp_Directx();
	~CApp_Directx();

	bool Init();
	bool InitWindow();
	int run();
	static LRESULT CALLBACK WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
	void Render();
	void cleanupDevice();


private:

	/************************************************************************/
	/* Structures                                                            /
	/************************************************************************/
	struct SimpleVertex
	{
		XMFLOAT3 Pos;
		XMFLOAT2 Tex;
	};

	struct CBNeverChanges
	{
		XMMATRIX mView;
	};

	struct CBChangeOnResize
	{
		XMMATRIX mProjection;
	};

	struct CBChangesEveryFrame
	{
		XMMATRIX mWorld;
		XMFLOAT4 vMeshColor;
	};

  struct DescTex
  {
    UINT Width  = 0;
    UINT Height = 0;
    DXGI_FORMAT Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    D3D11_USAGE Usage = D3D11_USAGE_DEFAULT;
  };


	/************************************************************************/
	/* Member Variables                                                      /
	/************************************************************************/
	HWND						            m_hWnd = NULL;
	XMMATRIX                    m_World;
	XMMATRIX                    m_View;
	XMMATRIX                    m_Projection;
	XMFLOAT4                    m_vMeshColor = { 0.7f, 0.7f, 0.7f, 1.0f };
	CManager					          m_Manager;
  UINT width = 0;
  UINT height = 0;
  DescTex desctext;
};

#endif // DIRECTX
