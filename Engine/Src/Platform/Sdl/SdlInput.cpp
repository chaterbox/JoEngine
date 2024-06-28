#include "Joe/KeyCode.h"
#include "Joepch.h"
#include "SdlInput.h"

#include "Joe/Application.h"

#include <SDL2/SDL.h>
#include <unistd.h>

//TODO: implement sdl input
namespace Joe{
	Input* Input::s_Instance = new SdlInput();

	bool SdlInput::IsKeyPressedImpl(Sint32 keycode){
		while(SDL_PollEvent(&event) != 0){
			if(event.key.keysym.sym == keycode){
			return true;
			break;
			}
		}
		return false;
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
}
