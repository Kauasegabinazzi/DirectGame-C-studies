#include <DX3D/Game/Game.h>
#include <Windows.h>

void dx3d::Game::run()
{
	MSG msg{};

	while (m_isRunning)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) 
			{
				m_isRunning = false;
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(1);
	}
}