#pragma once
#include "Joe/Core/Core.h"
#include <SDL2/SDL_stdinc.h>

namespace Joe{
	class JOE_API Input{
	public:
		static inline bool IsKeyPressed(Sint32 keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		static inline bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		static inline std::pair<float, float>GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		static inline float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		static inline float GetMouseY() { return s_Instance->GetMouseYImpl(); }

    static inline bool IsGamePadButtonPressed(){ return s_Instance->IsGamePadButtonPressed();}
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(Sint32 button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
    
    virtual inline bool IsGamePadButtonPressedImpl() = 0;
	private:
		static Input* s_Instance;
	};
}
