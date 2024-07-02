#pragma once
#include "Core.h"

#include "Window.h"
#include "LayerStack.h"

#include "Joe/ImGui/ImGuiLayer.h"

#include "Joe/Renderer/Shader.h"
#include "Renderer/Buffer.h"

namespace Joe{
	class JOE_API Application{
	public:
		Application();
		virtual ~Application();
		void Run();

		void PushLayer(Layer* Layer);
		void PushOverlay(Layer* Layer);
		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		static void SetRunning(bool run);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		static inline bool m_running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
