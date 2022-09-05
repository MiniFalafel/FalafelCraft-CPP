#include "Application.h"

#include <iostream>
#include <chrono>
#include <thread>

namespace FC
{
	Application::Application()
	{
		std::cout << "Created application.\n";
	}
	
	Application::~Application()
	{
		std::cout << "Destroyed application.\n";
	}

	void Application::Run()
	{
		using namespace std::literals::chrono_literals;
		std::this_thread::sleep_for(2s);
	}
}