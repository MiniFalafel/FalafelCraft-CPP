#pragma once

#include "Window.h"
#include "Events/Event.h"

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

		void OnEvent(const Event& e);
	};

	Application* CreateApplication();
}