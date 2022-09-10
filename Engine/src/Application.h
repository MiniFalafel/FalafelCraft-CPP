#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Renderer/Renderer.h"

#include "Core/Layer.h"
#include "Core/Time.h"

#include <chrono>

namespace FC
{
	class Application
	{
	private:
		Window* m_Window;

		static Application* s_ApplicationInstance;

		LayerStack m_LayerStack;

		TimePoint m_Time;

	public:
		Application();
		virtual ~Application();

		inline static Application* Get() { return s_ApplicationInstance; }

		Window* GetWindow() const;

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void Run();
		void OnEvent(const Event& e);
	};

	Application* CreateApplication();
}