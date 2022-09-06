#include "Window.h"

#include <iostream>

#include "Core/Core.h"
#include <GLFW/glfw3.h>

#include "Events/WindowEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace FC
{
	bool Window::s_GLFWInitialized = false;

	Window::Window(const WindowProperties& props)
	{
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;

		// Only initialize GLFW if it hasn't already been initialized.
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			FC_ASSERT(success, "glfw failed to initialize!");
			s_GLFWInitialized = true;
		}

		// Window Hints
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		FC_ASSERT(m_Window, "Failed to create glfw window!");

		glfwMakeContextCurrent(m_Window);

		glfwSetWindowUserPointer(m_Window, &m_Data);

		// Set GLFW input callbacks
		// WindowMovedEvent
		glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos)
		{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				WindowMovedEvent e(xpos, ypos);
				data->EventFnCallback(e);
		});

		// WindowResizedEvent
		glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			WindowResizedEvent e(width, height);
			data->EventFnCallback(e);
		});

		// WindowClosedEvent
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			WindowClosedEvent e;
			data->EventFnCallback(e);
		});

		// KeyPressedEvent, KeyReleasedEvent
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS)
			{
				KeyPressedEvent e(key);
				data->EventFnCallback(e);
			}
			else if (action == GLFW_RELEASE)
			{
				KeyReleasedEvent e(key);
				data->EventFnCallback(e);
			}
		});

		// KeyTypedEvent
		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent e(codepoint);
			data->EventFnCallback(e);
		});

		// MouseButtonPressedEvent, MouseButtonReleasedEvent
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS)
			{
				MouseButtonPressedEvent e(button);
				data->EventFnCallback(e);
			}
			else if (action == GLFW_RELEASE)
			{
				MouseButtonReleasedEvent e(button);
				data->EventFnCallback(e);
			}
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent e(xpos, ypos);
			data->EventFnCallback(e);
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoff, double yoff)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent e(xoff, yoff);
			data->EventFnCallback(e);
		});
	}

	Window::~Window()
	{
		glfwTerminate();
		s_GLFWInitialized = false;
	}

	void Window::SetEventFnCallback(const std::function<void(const Event&)>& func)
	{
		m_Data.EventFnCallback = func;
	}

	ProcAddressGetter Window::GetGlfwGLProcAddress() const
	{
		return glfwGetProcAddress;
	}

	void* Window::GetNativeWindow() const
	{
		return (void*)m_Window;
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Update() const
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

}