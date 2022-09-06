#include "Window.h"

#include <iostream>

#include "Core.h"
#include <GLFW/glfw3.h>

namespace FC
{
	bool Window::s_GLFWInitialized = false;

	Window::Window(const WindowProperties& props)
		: m_Data(props)
	{
		// Only initialize GLFW if it hasn't already been initialized.
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			FC_ASSERT(success);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);

	}

	Window::~Window()
	{
		glfwTerminate();
		s_GLFWInitialized = false;
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

}