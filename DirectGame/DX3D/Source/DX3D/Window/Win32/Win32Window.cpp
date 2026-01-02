#include <DX3D/Window/Window.h>
#include <Windows.h>
dx3d::Window::Window(): Base()
{
	WNDCLASSEX  wc{};

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"DX3DWindowClass";
	wc.lpfnWndProc = DefWindowProc;
	auto windowId = RegisterClassEx(&wc);

	RECT rc{ 0,0, 1280, 720 };
	AdjustWindowRect(
		&rc,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		false);

	CreateWindowEx(
		NULL, 
		MAKEINTATOM(windowId),
		L"C++ Tutorial", 
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		rc.right - rc.left,
		rc.bottom - rc.top,
		NULL, NULL, NULL, NULL);
}

dx3d::Window::~Window()
{
}
