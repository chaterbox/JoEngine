#include "Joe/Input/KeyCodes/KeyCode.h"
#include "Joe/Core/Log.h"
#include "Joepch.h"
#include "SdlInput.h"

#include "Joe/Core/Application.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>

//TODO: SDL::Implement sdl input
namespace Joe{
	Input* Input::s_Instance = new SdlInput();

	bool SdlInput::IsKeyPressedImpl(Sint32 keycode){
		SDL_Event event;
		if(SDL_WaitEvent(&event)){
			if(event.type == SDL_EVENT_KEY_DOWN){
				if(event.key.key == keycode){
					return true;
				}
				else{
					SDL_PumpEvents();
					return false;
				}
			}
		}
	}

	//TODO: SDL::Implement mouse button pressed input
	bool SdlInput::IsMouseButtonPressedImpl(int button){
		return false;
	}

	//TODO: SDL::Implement mouse position
	std::pair<float, float> SdlInput::GetMousePositionImpl(){
		double xpos, ypos;

		return{ (float)xpos,(float)ypos };
	}

	float SdlInput::GetMouseXImpl(){
		auto[x,y] = GetMousePositionImpl();
		return x;
	}

	float SdlInput::GetMouseYImpl(){
		auto [x, y] = GetMousePositionImpl();
		return y;
	}

	void SdlInput::InitGamepad(){
		SDL_InitSubSystem(SDL_INIT_GAMEPAD);
    //TODO: SDL3::fix connecting and opening gamepad
		if(SDL_HasGamepad()){
			//m_GamePad = SDL_OpenGamepad(i);
			if(SDL_GamepadConnected(m_GamePad)){
				std::string ControllerString = SDL_GetGamepadName(m_GamePad);
				JOE_CORE_INFO("SDL::INPUT::GAMEPAD::FOUND");
				JOE_CORE_INFO("SDL::INPUT::GAMEPAD::{0}", ControllerString);
			}
		}
	}

	bool SdlInput::IsGamePadButtonPressedImpl(){
    	return false;
	}
}
