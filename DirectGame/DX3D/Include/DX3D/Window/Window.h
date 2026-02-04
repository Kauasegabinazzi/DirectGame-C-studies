#pragma once
#include <DX3D/Core/Base.h>

namespace dx3d
{
	class Window : public Base
	{
	public:
		Window();
		virtual ~Window();

	private:
		void* m_handle{};
	};
}


