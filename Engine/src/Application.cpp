#include "Application.h"

#include <iostream>
#include <functional>

#include "Events/WindowEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace FC
{
	Application::Application()
		: m_Window(new Window( { 1280, 720, "App Window" } ))
	{
		m_Window->SetEventFnCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		std::cout << "Created application.\n";
	}
	
	Application::~Application()
	{
		delete m_Window;
		std::cout << "Destroyed application.\n";
	}

	void Application::Run()
	{

		while (!m_Window->ShouldClose())
		{
			// Do stuff
			m_Window->Update();
		}

	}

	void Application::OnEvent(const Event& e)
	{
		if (e.GetEventType() == EventType::WindowResized)
		{
			WindowResizedEvent* _event = (WindowResizedEvent*)&e;
			std::cout << "New Window Size: " << _event->GetWidth()  << ", " << _event->GetHeight() << '\n';
		}
		if (e.GetEventType() == EventType::KeyTyped)
		{
			KeyTypedEvent* _event = (KeyTypedEvent*)&e;
			std::cout << _event->GetKeyCode() << '\n';
		}
	}
}