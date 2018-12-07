#include "pch.h"
#include "CApp_Directx.h"
#include "Graphics.h"

#ifdef DIRECTX



CApp_Directx::CApp_Directx()
{
}


CApp_Directx::~CApp_Directx()
{
}

bool CApp_Directx::Init()
{


	HRESULT hr = S_OK;

	RECT rc;
	GetClientRect(m_hWnd, &rc);
   width = rc.right - rc.left;
   height = rc.bottom - rc.top;
   desctext.Width = width;
   desctext.Height = height;
	 m_Manager.Init(width, height, m_hWnd);

	// Create a render target view

	hr = m_Manager.GetBuffer(0);
	if (FAILED(hr))
		return false;

	hr = m_Manager.CreateRenderTargetView();
	if (FAILED(hr))
		return false;

	// Create depth stencil texture

  m_Manager.CreateDescTexture(desctext.Width, desctext.Height, desctext.Format, desctext.Usage);
	hr = m_Manager.CreateTexture2D();
	if (FAILED(hr))
		return false;

	// Create the depth stencil view

  m_Manager.CreateDescDSV();
	hr = m_Manager.CreateDepthStencilView();
	if (FAILED(hr))
		return false;

	m_Manager.OMSetRenderTargets(1);

	// Setup the viewport
	m_Manager.RSSetViewports(1);

	// Compile the vertex shader

	hr = m_Manager.CompileShaderFromFile(L"Tutorial07.fx", "VS", "vs_4_0");
	if (FAILED(hr))
	{
		MessageBox(NULL,
			L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK);
		return false;
	}

	// Create the vertex shader
	hr = m_Manager.CreateVertexShader();
	if (FAILED(hr))
	{
		m_Manager.releaseVS();
		return false;
	}

	// Create the input layout
	hr = m_Manager.CreateInputLayout();

	m_Manager.releaseVS();
	if (FAILED(hr))
		return false;

	// Set the input layout
	m_Manager.IASetInputLayout();

	// Compile the pixel shader

	hr = m_Manager.CompileShaderFromFile(L"Tutorial07.fx", "PS", "ps_4_0");
	if (FAILED(hr))
	{
		MessageBox(NULL,
			L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK);
		return false;
	}

	// Create the pixel shader
	hr = m_Manager.CreatePixelShader();
	m_Manager.releasePS();
	if (FAILED(hr))
		return false;

	// Create vertex buffer
	SimpleVertex vertices[] =
	{
		{ XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT2(0.0f, 0.0f) },
		{ XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
		{ XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT2(1.0f, 1.0f) },
		{ XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },

		{ XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT2(0.0f, 0.0f) },
		{ XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
		{ XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT2(1.0f, 1.0f) },
		{ XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },

		{ XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT2(0.0f, 0.0f) },
		{ XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
		{ XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT2(1.0f, 1.0f) },
		{ XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },

		{ XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT2(0.0f, 0.0f) },
		{ XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
		{ XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT2(1.0f, 1.0f) },
		{ XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },

		{ XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT2(0.0f, 0.0f) },
		{ XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
		{ XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT2(1.0f, 1.0f) },
		{ XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT2(0.0f, 1.0f) },

		{ XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT2(0.0f, 0.0f) },
		{ XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT2(1.0f, 0.0f) },
		{ XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT2(1.0f, 1.0f) },
		{ XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },
	};


	m_Manager.CreateDescBuffer("default", sizeof(SimpleVertex) * 24, "vertex", 0);
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	hr = m_Manager.CreateBuffer(&InitData, "vertex");
	if (FAILED(hr))
		return false;

	// Set vertex buffer
	UINT stride = sizeof(SimpleVertex);
	UINT offset = 0;
	m_Manager.IASetVertexBuffers(0, 1, &stride, &offset);

	// Create index buffer
	// Create vertex buffer
	WORD indices[] =
	{
		3,1,0,
		2,1,3,

		6,4,5,
		7,4,6,

		11,9,8,
		10,9,11,

		14,12,13,
		15,12,14,

		19,17,16,
		18,17,19,

		22,20,21,
		23,20,22
	};
	m_Manager.CreateDescBuffer("default", sizeof(WORD) * 36, "index", 0);
	InitData.pSysMem = indices;
	hr = m_Manager.CreateBuffer(&InitData, "index");
	if (FAILED(hr))
		return false;

	// Set index buffer
	m_Manager.IASetIndexBuffer(DXGI_FORMAT_R16_UINT, 0);

	// Set primitive topology
	m_Manager.IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// Create the constant buffers
	m_Manager.CreateDescBuffer("default", sizeof(CBNeverChanges), "constant", 0);
	hr = m_Manager.CreateBuffer(NULL, "NC");
	if (FAILED(hr))
		return false;

	m_Manager.CreateDescBuffer("default", sizeof(CBChangeOnResize), "constant", 0);
	hr = m_Manager.CreateBuffer(NULL, "COR");
	if (FAILED(hr))
		return false;

	m_Manager.CreateDescBuffer("default", sizeof(CBChangesEveryFrame), "constant", 0);
	hr = m_Manager.CreateBuffer(NULL, "CEF");
	if (FAILED(hr))
		return false;

	// Load the Texture
  hr = m_Manager.loadTexture(L"texturagorda.jpg");
	if (FAILED(hr))
		return false;

	// Create the sample state
  m_Manager.CreateSamplerDesc();
	hr = m_Manager.CreateSamplerState();
	if (FAILED(hr))
		return false;

	// Initialize the world matrices
	m_World = XMMatrixIdentity();

	// Initialize the view matrix
	XMVECTOR Eye = XMVectorSet(0.0f, 3.0f, -6.0f, 0.0f);
	XMVECTOR At = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	m_View = XMMatrixLookAtLH(Eye, At, Up);

	CBNeverChanges cbNeverChanges;
	cbNeverChanges.mView = XMMatrixTranspose(m_View);
	m_Manager.UpdateSubresource("NC", 0, NULL, &cbNeverChanges, 0, 0);

	// Initialize the projection matrix
	m_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, width / (FLOAT)height, 0.01f, 100.0f);

	CBChangeOnResize cbChangesOnResize;
	cbChangesOnResize.mProjection = XMMatrixTranspose(m_Projection);
	m_Manager.UpdateSubresource("COR", 0, NULL, &cbChangesOnResize, 0, 0);

	return true;
}

bool CApp_Directx::InitWindow()
{

	//register class
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = GetModuleHandle(0);
	wndclass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(0, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = L"Proyecto_Final";
	wndclass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	if (!RegisterClassEx(&wndclass))
		return false;

	//Create window
	RECT rc = { 0, 0, 640, 480 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	m_hWnd = CreateWindowEx(0, L"Proyecto_Final", L"Proyecto_Final",

		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,

		CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, GetModuleHandle(0), 0);

	if (!m_hWnd)
		return E_FAIL;

	ShowWindow(m_hWnd, SW_SHOWDEFAULT);

	return true;
}

int CApp_Directx::run()
{


	if (!InitWindow())
	{
		std::cout << "InitWindow Failed!" << std::endl;
	}

	if (!Init())
	{
		std::cout << "Init Failed!" << std::endl;
	}
	
	// Main message loop
	MSG msg = { 0 };

	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Render();
		}
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK CApp_Directx::WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{


	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(window, &ps);
		EndPaint(window, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(window, message, wParam, lParam);
	}


	return 0;
}

void CApp_Directx::Render()
{

	// Update our time
	static float t = 0.0f;
	if (m_Manager.GetDriverTypePointer() == D3D_DRIVER_TYPE_REFERENCE)
	{
		t += (float)XM_PI * 0.0125f;
	}
	else
	{
		static DWORD dwTimeStart = 0;
		DWORD dwTimeCur = GetTickCount();
		if (dwTimeStart == 0)
			dwTimeStart = dwTimeCur;
		t = (dwTimeCur - dwTimeStart) / 1000.0f;
	}

	// Rotate cube around the origin
	m_World = XMMatrixRotationY(t);

	// Modify the color
	m_vMeshColor.x = (sinf(t * 1.0f) + 1.0f) * 0.5f;
	m_vMeshColor.y = (cosf(t * 3.0f) + 1.0f) * 0.5f;
	m_vMeshColor.z = (sinf(t * 5.0f) + 1.0f) * 0.5f;

	//
	// Clear the back buffer
	//
	float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // red, green, blue, alpha
	m_Manager.ClearRenderTargetView(ClearColor);

	//
	// Clear the depth buffer to 1.0 (max depth)
	//
	m_Manager.ClearDepthStencilView(D3D11_CLEAR_DEPTH, 1.0f, 0);

	//
	// Update variables that change once per frame
	//
	CBChangesEveryFrame cb;
	cb.mWorld = XMMatrixTranspose(m_World);
	cb.vMeshColor = m_vMeshColor;
	m_Manager.UpdateSubresource("CEF", 0, NULL, &cb, 0, 0);

	//
	// Render the cube
	//
	m_Manager.VSSetShader(NULL, 0);
	m_Manager.VSSetConstantBuffers(0, 1, "NC");
	m_Manager.VSSetConstantBuffers(1, 1, "COR");
	m_Manager.VSSetConstantBuffers(2, 1, "CEF");
	m_Manager.PSSetShader(NULL, 0);
	m_Manager.PSSetConstantBuffers(2, 1);
	m_Manager.PSSetShaderResources(0, 1);
	m_Manager.PSSetSamplers(0, 1);
	m_Manager.DrawIndexed(36, 0, 0);

	//
	// Present our back buffer to our front buffer
	//
	m_Manager.Present(0, 0);


}

void CApp_Directx::cleanupDevice()
{
	m_Manager.CleanupDevice();
}


#endif // DirectX