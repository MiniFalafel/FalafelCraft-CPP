#include "Core/Core.h"
#include "Application.h"

#include <iostream>
#include <functional>

#include "Events/WindowEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include "Core/Input.h"

namespace FC
{
	Application* Application::s_ApplicationInstance = nullptr;

	Application::Application()
		: m_Window(new Window( { 1280, 720, "Game Window" } ))
	{
		// Make sure that no other instances have been made.
		FC_ASSERT(!s_ApplicationInstance, "An instance of Application already exists!");
		s_ApplicationInstance = this;

		// Initialize glad
		Renderer::Init(m_Window->GetGlfwGLProcAddress());
		//	Set m_Window event function callback.
		m_Window->SetEventFnCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		std::cout << "Created application.\n";
	}
	
	Application::~Application()
	{
		delete m_Window;
		s_ApplicationInstance = nullptr;
		std::cout << "Destroyed application.\n";
	}

	Window* Application::GetWindow() const
	{
		return m_Window;
	}

	void Application::Run()
	{

		while (!m_Window->ShouldClose())
		{
			// Do stuff
			Renderer::SetClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			Renderer::Clear();
			
			{
				if (Input::IsKeyPressed(FC_KEY_W))
					std::cout << "Input polling works! classic MiniFalafel W. B)\n";
			}

			m_Window->Update();
		}

	}

	void Application::OnEvent(const Event& e)
	{
		// Handle Events
	}
}