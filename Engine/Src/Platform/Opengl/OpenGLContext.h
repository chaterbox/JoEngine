#pragma once
#include "Joe/Renderer/GraphicsContext.h"
//TODO: get rid of opengl
struct GLFWwindow;

namespace Joe{
	class JOE_API OpenglContext :public GraphicsContext{
	public:
		OpenglContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void Swapbuffers() override;

	private:
		GLFWwindow* m_WindowHandle;
	};
}
