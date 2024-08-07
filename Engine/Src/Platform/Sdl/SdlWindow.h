#pragma once
#include "Joe/Core/Window.h"
#include "Joe/Renderer/GraphicsContext.h"
#include "vulkan_core.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

namespace Joe{
	class SdlWindow : public Window{
	public:
		SdlWindow(const WindowProps& props);
		virtual ~SdlWindow();

		void OnUpdate() override;

		inline int GetWidth() const override { return m_Data.Width; }
		inline int GetHeight() const override { return m_Data.Height; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const override { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		SDL_Window* m_Window;
		SDL_Event event;
		GraphicsContext* m_Context;

    VkShaderModule m_VertexShader;
    VkShaderModule m_FragmentShader;

		struct WindowData{
			const char* Title;
			int Width, Height;
			bool VSync;
		};
		WindowData m_Data;
	};
}
