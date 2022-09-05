#include "Application.h"
#include "EntryPoint.h"

#include <iostream>

class FalafelCraft : public FC::Application
{
public:
	FalafelCraft()
	{
		std::cout << "Created FalafelCraft Application.\n";
	}

	~FalafelCraft()
	{
		std::cout << "Destroyed FalafelCraft Application.\n";
	}
};

FC::Application* FC::CreateApplication()
{
	return new FalafelCraft();
}