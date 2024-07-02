#pragma once
#include "Joe/Window.h"
#include "Joe/Renderer/GraphicsContext.h"

#include <SDL2/SDL.h>

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

		struct WindowData{
			const char* Title;
			int Width, Height;
			bool VSync;
		};
		WindowData m_Data;
	};
}
