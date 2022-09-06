#pragma once

#include "Event.h"

namespace FC
{
	class WindowResizedEvent : public Event
	{
	private:
		int m_Width, m_Height;

	public:
		WindowResizedEvent(int width, int height)
			: m_Width(width), m_Height(height) {}

		int GetWidth() const { return m_Width; }
		int GetHeight() const { return m_Height; }

		EVENT_TYPE_METHODS(EventType::WindowResized);
	};

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		EVENT_TYPE_METHODS(EventType::WindowClosed);
	};

	class WindowMovedEvent : public Event
	{
	private:
		int m_XPos, m_YPos;

	public:
		WindowMovedEvent(int xpos, int ypos)
			: m_XPos(xpos), m_YPos(ypos) {}

		int GetXPos() const { return m_XPos; }
		int GetYPos() const { return m_YPos; }

		EVENT_TYPE_METHODS(EventType::WindowMoved);
	};
}
