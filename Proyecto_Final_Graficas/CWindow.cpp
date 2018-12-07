#include "pch.h"
#include "CWindow.h"


CWindow::CWindow()
{
}


CWindow::~CWindow()
{
}


/*
long __stdcall CWindow::WindowProcedure(HWND window, unsigned int msg, WPARAM wp, LPARAM lp)
{

	switch (msg)

	{

	case WM_DESTROY:

		std::cout << "\ndestroying window\n";

		PostQuitMessage(0);

		return 0L;

	case WM_LBUTTONDOWN:

		std::cout << "\nmouse left button down at (" << LOWORD(lp)

			<< ',' << HIWORD(lp) << ")\n";

		// fall thru

	default:

		std::cout << '.';

		return DefWindowProc(window, msg, wp, lp);

	}
}


void CWindow::run()
{

	LPCWSTR myclass = (LPCWSTR)"myclass";

	WNDCLASSEX wndclass = { sizeof(WNDCLASSEX), CS_DBLCLKS, WindowProcedure,

							0, 0, GetModuleHandle(0), LoadIcon(0,IDI_APPLICATION),

							LoadCursor(0,IDC_ARROW), HBRUSH(COLOR_WINDOW + 1),

							0, myclass, LoadIcon(0,IDI_APPLICATION) };

	if (RegisterClassEx(&wndclass))

	{

		HWND window = CreateWindowEx(0, myclass, (LPCWSTR)"title",

			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,

			CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, GetModuleHandle(0), 0);

		if (window)

		{

			ShowWindow(window, SW_SHOWDEFAULT);

			MSG msg;

			while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);

		}

	}
}*/

