#include "pch.h"
#include "CApp_gen.h"


CApp_gen::CApp_gen()
{
}


CApp_gen::~CApp_gen()
{
}

bool CApp_gen::Init()
{
  return false;
}

bool CApp_gen::InitWindow()
{
  HWND m_hWnd = NULL;
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

int CApp_gen::run()
{
 
    InitWindow();
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

    }
  }
  return (int)msg.wParam;
}

LRESULT CApp_gen::WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
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

