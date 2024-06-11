#include "Joepch.h"
#include "GlfwInput.h"

#include "Joe/Application.h"

#include <GLFW/glfw3.h>
#include <unistd.h>

namespace Joe{
	Input* Input::s_Instance = new GlfwInput();
	bool GlfwInput::IsKeyPressedImpl(int keycode){
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window,keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool GlfwInput::IsMouseButtonPressedImpl(int button){
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> GlfwInput::GetMousePositionImpl(){
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return{ (float)xpos,(float)ypos };
	}

	float GlfwInput::GetMouseXImpl(){
		auto[x,y] = GetMousePositionImpl();
		return x;
	}

	float GlfwInput::GetMouseYImpl(){
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
}
