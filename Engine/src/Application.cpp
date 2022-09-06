#include "Application.h"

#include <iostream>

namespace FC
{
	Application::Application()
		: m_Window(new Window( { 1280, 720, "App Window" } ))
	{
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
}