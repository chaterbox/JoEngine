#pragma once
#include "Joepch.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <functional>

namespace Joe{
  
	class JOE_API Event{
    static inline SDL_Event event;
  public:
    static bool PollEvent(SDL_Event event);
    static SDL_Event* GetEventHandle(){ return &event;}
  };
}
