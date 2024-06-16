#pragma once
#include "Joepch.h"

#include "Joe/Core.h"
#include "Joe/Events/Event.h"
#include "Renderer/RendererAPI.h"

namespace Joe{
	struct WindowProps{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		
		WindowProps(const std::string& title = "JoEngine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height){
			#ifdef JOE_DEBUG
			if(RendererAPI::GetAPI() == RendererAPI::API::OpenGL){
				Title = "JoEngine: DEBUG: RendererAPI: OpenGL";
			}
			if (RendererAPI::GetAPI() == RendererAPI::API::Vulkan){
				Title = "JoEngine: DEBUG: RendererAPI: Vulkan";
			}
			#endif
		}
	};

	class JOE_API Window{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallBack(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
