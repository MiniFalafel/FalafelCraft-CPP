#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Renderer/Renderer.h"

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