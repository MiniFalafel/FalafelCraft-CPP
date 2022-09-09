#include "Engine.h"
#include "EntryPoint.h"

#include <iostream>

class MyLayer : public FC::Layer
{
public:
	void OnAttach() override
	{
		FC_TRACE("Attached MyLayer!");
	}

	void OnDetach() override
	{
		FC_TRACE("Detached MyLayer!");
	}

	void OnUpdate(double dt) override
	{
		// Update the layer
	}

	bool OnEvent(const FC::Event& e) override
	{
		if (e.GetEventType() == FC::EventType::KeyPressed)
		{
			FC_TRACE("A key(%i) has been pressed!", ((FC::KeyPressedEvent*)(&e))->GetKeyCode());
		}
		return false;
	}
};

class FalafelCraft : public FC::Application
{
public:
	FalafelCraft()
	{
		PushLayer(new MyLayer());
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