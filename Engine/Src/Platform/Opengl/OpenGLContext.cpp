#include "Joepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Joe{
	OpenglContext::OpenglContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle){
		JOE_CORE_ASSERT(windowHandle,"window handle is null")
	}

	void OpenglContext::Init(){
		glfwMakeContextCurrent(m_WindowHandle);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		JOE_CORE_ASSERT(status, "failed to init GLAD!");

		JOE_CORE_INFO("OpenGL INFO:");
		JOE_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		JOE_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		JOE_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
	}

	void OpenglContext::Swapbuffers(){
		glfwSwapBuffers(m_WindowHandle);
	}
}
