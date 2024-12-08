#pragma once
#include "Joepch.h"

#include "Core.h"
#include <Joe/Renderer/RHI.h>

namespace Joe{
	struct WindowProps{
		const char* Title;
		int Width;
		int Height;
		
		WindowProps(const char* title = "JoEngine",
			int width = 1280,
			int height = 720)
			: Title(title), Width(width), Height(height){
			#ifdef JOE_DEBUG
			if (RendererAPI::GetAPI() == RendererAPI::API::Vulkan){
				Title = "JoEngine: DEBUG: RendererAPI: Vulkan";
			}
			#endif
		}
	};

	class JOE_API Window{
	public:
		virtual ~Window(){}

		virtual void OnUpdate() = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
