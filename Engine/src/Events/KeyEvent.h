#pragma once

#include "Event.h"

#include "KeyCodes.h"

namespace FC
{
	class KeyEvent : public Event
	{
	private:
		KeyCode m_KeyCode;

	public:
		KeyEvent(const KeyCode& keyCode)
			: m_KeyCode(keyCode) {}
		~KeyEvent() = default;

		inline KeyCode GetKeyCode() const { return m_KeyCode; }

	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keyCode) : KeyEvent(keyCode) {}

		EVENT_TYPE_METHODS(EventType::KeyPressed);
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode keyCode) : KeyEvent(keyCode) {}

		EVENT_TYPE_METHODS(EventType::KeyReleased);
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(KeyCode keyCode)
			: KeyEvent(keyCode) {}

		EVENT_TYPE_METHODS(EventType::KeyTyped);
	};
}