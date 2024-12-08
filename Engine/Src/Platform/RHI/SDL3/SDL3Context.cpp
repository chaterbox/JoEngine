#include "Joepch.h"
#include "Platform/Sdl/SdlWindow.h"
#include "Platform/RHI/SDL3/SDL3Context.h"

namespace Joe{
  void SDL3Context::Init(){
    m_Renderer = SDL_CreateRenderer(m_WindowHandle, nullptr);        
  }

  void SDL3Context::Render(){
    //set clear color
    SDL_SetRenderDrawColor(m_Renderer, 0,0,100,SDL_ALPHA_OPAQUE); 
    SDL_RenderClear(m_Renderer);
    //set line color
    //line color red
    SDL_SetRenderDrawColor(m_Renderer, 255,0,0,SDL_ALPHA_OPAQUE);
    //add line to render
    SDL_RenderLine(m_Renderer,5,5,100,120);
    //present image to window
    SDL_RenderPresent(m_Renderer);  
  }

	SDL3Context::SDL3Context(SDL_Window* window)
  : m_WindowHandle(window){
	}

	SDL3Context::~SDL3Context(){

	}
}
