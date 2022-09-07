#include "Application.h"
#include "EntryPoint.h"
#include "Core/Core.h"

#include <iostream>

class FalafelCraft : public FC::Application
{
public:
	FalafelCraft()
	{
		FC_INFO("Created FalafelCraft Application.");
	}

	~FalafelCraft()
	{
		FC_INFO("Destroyed FalafelCraft Application.");
	}
};

FC::Application* FC::CreateApplication()
{
	return new FalafelCraft();
}