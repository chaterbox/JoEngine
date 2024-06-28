#include "Joepch.h"
#include "Application.h"

#include "Joe/Log.h"

#include "Joe/Renderer/Renderer.h"

#include "Input.h"

namespace Joe{
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Joe::Application::Application(){
		JOE_CORE_ASSERT(!s_Instance, "app already exist");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));

		//m_ImGuiLayer = new ImGuiLayer();
		//PushOverlay(m_ImGuiLayer);
		
	}

	Joe::Application::~Application(){
    JOE_CORE_INFO("JOENGINE::CLOSED");
	}

	void Application::OnEvent(Event& e){
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();){
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* Layer){
		m_LayerStack.PushLayer(Layer);
		Layer->OnAttach();
	}

	void Application::PushOverlay(Layer* Layer){
		m_LayerStack.PushOverlay(Layer);
		Layer->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e){
		m_running = false;
		return true;
	}

	void Application::Run(){
		while (m_running){
			//m_ImGuiLayer->Begin();
			//for (Layer* layer : m_LayerStack)
				//layer->OnImGuiRender();
			//m_ImGuiLayer->End();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	void Application::SetRunning(bool run){
		if(run){
			m_running = true;
		}else{
			m_running = false;
    }
  }
}
