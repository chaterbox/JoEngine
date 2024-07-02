#include "Joepch.h"
#include <SDL2/SDL_events.h>
#include <functional>
#include "Event.h"

namespace Joe{
  bool Event::PollEvent(SDL_Event event){
  SDL_PollEvent(&event);
  }
}
