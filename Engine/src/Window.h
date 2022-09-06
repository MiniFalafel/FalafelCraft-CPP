#pragma once

#include <string>
#include "Events/Event.h"
#include "Renderer/GLProc.h"

#include <functional>

struct GLFWwindow;

namespace FC
{
	struct WindowProperties
	{
		unsigned int Width, Height;
		std::string Title;
	};

	class Window
	{
	private:
		GLFWwindow* m_Window;
		static bool s_GLFWInitialized;

		struct WindowData
		{
			unsigned int Width, Height;
			std::string Title;

			std::function<void (const Event&)> EventFnCallback;
		};

		WindowData m_Data;


	public:
		Window(const WindowProperties& props);
		~Window();

		void SetEventFnCallback(const std::function<void(const Event&)>& func);

		ProcAddressGetter GetGlfwGLProcAddress() const;

		void* GetNativeWindow() const;

		bool ShouldClose() const;
		void Update() const;
	};

}