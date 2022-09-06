#pragma once

#include <string>

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

		WindowProperties m_Data;

	public:
		Window(const WindowProperties& props);
		~Window();

		bool ShouldClose();

		void Update();
	};

}