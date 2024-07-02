#include "Joepch.h"
#include <SDL2/SDL_events.h>
#include "KeyboardEvent.h"

namespace Joe{
  void KeyboardEvent::Update(SDL_Event event){
    if(event.type == SDL_KEYDOWN){

    }
  }

  bool KeyboardEvent::IsKeyPressed(Sint32 key){
    SDL_Event event;
    if(SDL_WaitEvent(&event)){
      if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == key){
          return true;
        }
        else{
          SDL_PumpEvents();
          return false;
        }
      }
    }
  }
}
