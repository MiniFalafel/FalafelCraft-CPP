#pragma once

#include "Event.h"
#include "MouseCodes.h"

namespace FC
{
	class MouseButtonEvent : public Event
	{
	private:
		MouseButtonCode m_MouseCode;

	public:
		MouseButtonEvent(MouseButtonCode mouseCode)
			: m_MouseCode(mouseCode) {}
		~MouseButtonEvent() = default;

		MouseButtonCode GetMouseCode() const { return m_MouseCode; }
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(MouseButtonCode mouseCode)
			: MouseButtonEvent(mouseCode) {}

		EVENT_TYPE_METHODS(EventType::MouseButtonPressed);
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(MouseButtonCode mouseCode)
			: MouseButtonEvent(mouseCode) {}

		EVENT_TYPE_METHODS(EventType::MouseButtonReleased);
	};

	class MouseMovedEvent : public Event
	{
	private:
		double m_MouseX, m_MouseY;

	public:
		MouseMovedEvent(double mouseX, double mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		double GetMouseX() const { return m_MouseX; }
		double GetMouseY() const { return m_MouseY; }

		EVENT_TYPE_METHODS(EventType::MouseMoved);
	};

	class MouseScrolledEvent : public Event
	{
	private:
		double m_ScrollX, m_ScrollY;

	public:
		MouseScrolledEvent(double scrollX, double scrollY)
			: m_ScrollX(scrollX), m_ScrollY(scrollY) {}

		double GetMouseScrollX() const { return m_ScrollX; }
		double GetMouseScrollY() const { return m_ScrollY; }

		EVENT_TYPE_METHODS(EventType::MouseScrolled);
	};
}
