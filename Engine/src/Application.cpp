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
		Logger::Init();
		// Make sure that no other instances have been made.
		FC_ASSERT(!s_ApplicationInstance, "An instance of Application already exists!");
		s_ApplicationInstance = this;

		// Initialize glad
		Renderer::Init(m_Window->GetGlfwGLProcAddress());
		//	Set m_Window event function callback.
		m_Window->SetEventFnCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		// Initialize m_Time
		m_Time = Time::GetTime();

		FC_INFO("Created Application.");
	}
	
	Application::~Application()
	{
		delete m_Window;
		m_LayerStack.Shutdown();
		s_ApplicationInstance = nullptr;
		FC_INFO("Destroyed application.\n");
	}

	Window* Application::GetWindow() const
	{
		return m_Window;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
	}

	void Application::Run()
	{

		while (!m_Window->ShouldClose())
		{
			// Update m_Time
			TimePoint now = Time::GetTime();
			double dt = std::chrono::duration<double>(now - m_Time).count();
			m_Time = now;

			// Update Layers
			m_LayerStack.OnUpdate(dt);

			// Do stuff
			Renderer::SetClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			Renderer::Clear();
			
			{
				if (Input::IsKeyPressed(FC_KEY_W))
					FC_TRACE("Input polling works! classic MiniFalafel W. B)");
			}

			m_Window->Update();
		}

	}

	void Application::OnEvent(const Event& e)
	{
		m_LayerStack.OnEvent(e);
	}
}