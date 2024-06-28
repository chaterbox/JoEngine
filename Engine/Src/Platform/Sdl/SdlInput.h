#pragma once
#include "Joe/Input.h"
#include <SDL2/SDL_events.h>

namespace Joe{
	class SdlInput : public Input{
	protected:
		virtual bool IsKeyPressedImpl(Sint32 keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button)override;
		virtual std::pair<float, float> GetMousePositionImpl()override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;

		SDL_Event event;
	};
}
