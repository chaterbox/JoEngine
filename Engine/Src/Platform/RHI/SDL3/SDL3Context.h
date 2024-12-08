#pragma once
#include "Joe/Renderer/GraphicsContext.h"
#include <SDL3/SDL.h>

struct SDLwindow;

namespace Joe{
	class JOE_API SDL3Context :public GraphicsContext{
	public:
		SDL3Context(SDL_Window* window);
		~SDL3Context();
		static SDL_Renderer* GetRenderHandle(){ return  m_Renderer;}
		virtual void Init() override;
		static void Render();
	private:
		SDL_Window* m_WindowHandle;
		static inline SDL_Renderer* m_Renderer;
	};
}
