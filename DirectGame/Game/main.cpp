#include <DX3D/All.h>

int main()
{
	try {
		dx3d::Game game{};
		game.run();
	}
	catch (const std::runtime_error&) 
	{
		return EXIT_FAILURE;
	}
	catch (const std::exception&)
	{
		return EXIT_FAILURE;
	}
	catch (...)
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}