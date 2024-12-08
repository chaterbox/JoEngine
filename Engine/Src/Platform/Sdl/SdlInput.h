#pragma once
#include "Joe/Input/Input.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_gamepad.h>

namespace Joe{
	class SdlInput : public Input{
	public:
		static void InitGamepad();
	protected:
		virtual bool IsKeyPressedImpl(Sint32 keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button)override;
		virtual std::pair<float, float> GetMousePositionImpl()override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;

    virtual bool IsGamePadButtonPressedImpl() override;

		SDL_Event m_Event;
		static inline SDL_Gamepad* m_GamePad;
	};
}
