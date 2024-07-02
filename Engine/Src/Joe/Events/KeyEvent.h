#pragma once
#include "Event.h"
#include <SDL2/SDL_stdinc.h>

namespace Joe{
	class JOE_API KeyEvent : public Event{
	public:
		inline Sint32 GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(Sint32 keycode)
			: m_KeyCode(keycode){}

		Sint32 m_KeyCode;
	};

	class JOE_API KeyPressedEvent : public KeyEvent{
	public:
		KeyPressedEvent(Sint32 keycode,int repeatCount)
			:KeyEvent(keycode), m_RepeatCount(repeatCount){}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class JOE_API KeyReleasedEvent : public KeyEvent{
	public:
		KeyReleasedEvent(Sint32 keycode)
			: KeyEvent(keycode){}

		std::string ToString() const override{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};

	class JOE_API KeyTypedEvent : public KeyEvent{
	public:
		KeyTypedEvent(Sint32 keycode)
			:KeyEvent(keycode) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyTyped)
	private:
		int m_RepeatCount;
	};
}
