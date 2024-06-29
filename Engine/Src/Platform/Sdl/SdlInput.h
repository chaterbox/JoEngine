#pragma once
#include "Joe/Input.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_gamecontroller.h>

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

		SDL_Event m_Event;
		static inline SDL_GameController* m_Controller;
	};
}
