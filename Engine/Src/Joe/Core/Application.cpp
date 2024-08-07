#include "Joepch.h"
#include "Application.h"

#include "Log.h"

#include "Joe/Renderer/Renderer.h"

#include <Joe/Input/Input.h>

namespace Joe{
	Application* Application::s_Instance = nullptr;

	Joe::Application::Application(){
		JOE_CORE_ASSERT(!s_Instance, "app already exist");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Joe::Application::~Application(){
    std::cout << "\n";
    JOE_CORE_INFO("JOENGINE::CLOSED");
	}

	void Application::PushLayer(Layer* Layer){
		m_LayerStack.PushLayer(Layer);
		Layer->OnAttach();
	}

	void Application::PushOverlay(Layer* Layer){
		m_LayerStack.PushOverlay(Layer);
		Layer->OnAttach();
	}

	void Application::Run(){
		while (m_running){

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	void Application::Quit(){
		m_running = false;
  }
}
