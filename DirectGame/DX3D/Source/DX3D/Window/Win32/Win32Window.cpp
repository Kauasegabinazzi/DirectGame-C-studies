#include <DX3D/Window/Window.h>
#include <Windows.h>
#include <stdexcept>

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return 0;
}




dx3d::Window::Window() : Base()
{
	auto registerWindowClassFunction = []()
		{
			WNDCLASSEX  wc{};

			wc.cbSize = sizeof(WNDCLASSEX);
			wc.lpszClassName = L"DX3DWindowClass";
			wc.lpfnWndProc = &WindowProcedure;
			return RegisterClassEx(&wc);
		};

	static const auto windowId = std::invoke(registerWindowClassFunction);

	if (!windowId)
		throw std::runtime_error("Failed to register window class.");

	RECT rc{ 0,0, 1280, 720 };
	AdjustWindowRect(
		&rc,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		false);

	m_handle = CreateWindowEx(
		NULL,
		MAKEINTATOM(windowId),
		L"C++ Tutorial",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rc.right - rc.left,
		rc.bottom - rc.top,
		NULL, NULL, NULL, NULL);

	if (!m_handle)
		throw std::runtime_error("Failed to create window.");

	ShowWindow(
		static_cast<HWND>(m_handle),
		SW_SHOW);
}

dx3d::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_handle));
}
