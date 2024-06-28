#include "Joepch.h"
#include "SdlInput.h"

#include "Joe/Application.h"

#include <SDL2/SDL.h>
#include <unistd.h>

//TODO: implement sdl input
namespace Joe{
	Input* Input::s_Instance = new SdlInput();

  //TODO: implement key pressed input
	bool SdlInput::IsKeyPressedImpl(int keycode){
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
