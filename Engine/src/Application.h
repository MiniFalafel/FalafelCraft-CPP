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

		static Application* s_ApplicationInstance;

	public:
		Application();
		virtual ~Application();

		inline static Application* Get() { return s_ApplicationInstance; }

		Window* GetWindow() const;

		void Run();
		void OnEvent(const Event& e);
	};

	Application* CreateApplication();
}