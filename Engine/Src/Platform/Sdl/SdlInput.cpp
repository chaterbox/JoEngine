#include "Joepch.h"
#include "SdlInput.h"

#include "Joe/Application.h"

#include <SDL2/SDL.h>
#include <unistd.h>

namespace Joe{
	Input* Input::s_Instance = new SdlInput();
	bool SdlInput::IsKeyPressedImpl(int keycode){
		return false;
	}

	bool SdlInput::IsMouseButtonPressedImpl(int button){
		return false;
	}

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
