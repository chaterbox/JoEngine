#include "Actor.h" 
#include "Platform/Sdl/SdlWindow.h"

Actor::Actor() : Layer("Actor"){
  JOE_INFO("ACTOR::INIT");
}

void Actor::OnImGuiRender(){

}

void Actor::OnUpdate(){
  while (SDL_PollEvent(&event) != 0) {
    Joe::SdlWindow::SdlQuitEvent(event);

    if(event.key.keysym.sym == KEYS::JOE_KEY_W){
      JOE_INFO("W::PRESSED");
    }
  }
}
