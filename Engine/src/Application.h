#pragma once

#include "Window.h"

namespace FC
{
	class Application
	{
	private:
		Window* m_Window;

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}