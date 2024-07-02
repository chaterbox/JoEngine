#include "Joe/KeyCode.h"
#include "Joe/Log.h"
#include "Joepch.h"
#include "SdlInput.h"

#include "Joe/Application.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_gamecontroller.h>
#include <unistd.h>

//TODO: implement sdl input
namespace Joe{
	Input* Input::s_Instance = new SdlInput();

	bool SdlInput::IsKeyPressedImpl(Sint32 keycode){
    SDL_Event event;
    if(SDL_WaitEvent(&event)){
      if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == keycode){
          return true;
        }
        else{
          SDL_PumpEvents();
          return false;
        }
      }
    }
	}

  //TODO: implement mouse button pressed input
	bool SdlInput::IsMouseButtonPressedImpl(int button){
		return false;
	}

  //TODO: implement mouse position
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
		SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
    
		for(int i = 0; i < SDL_NumJoysticks();i++){
			if(SDL_IsGameController(i)){
				m_Controller = SDL_GameControllerOpen(i);
        
				std::string ControllerString = SDL_GameControllerName(m_Controller);
				JOE_CORE_INFO("SDL::INPUT::GAMEPAD::FOUND");
				JOE_CORE_INFO("SDL::INPUT::GAMEPAD::{0}", ControllerString);
			}
		}
	}
}
