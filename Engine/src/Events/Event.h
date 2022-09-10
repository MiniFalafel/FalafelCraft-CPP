#pragma once

#define EVENT_TYPE_METHODS(type) EventType GetEventType() const override { return type; }\
								 const char* GetTypeName() const override { return #type; }

namespace FC
{
	// We want event types so that our application callback knows what to do with events.
	enum class EventType
	{
		WindowMoved, WindowResized, WindowClosed,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
	};

	class Event
	{
	public:
		Event() = default;
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetTypeName() const = 0;
	};

}