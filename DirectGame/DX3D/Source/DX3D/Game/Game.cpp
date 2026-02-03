#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>

dx3d::Game::Game()
{
	m_display = new Window();
}

dx3d::Game::~Game()
{
	delete m_display;
}
