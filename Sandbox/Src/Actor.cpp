#include "Actor.h" 

Actor::Actor() : Layer("Actor"){
  JOE_INFO("ACTOR::INIT");
}

void Actor::OnImGuiRender(){

}

void Actor::OnUpdate(){
  while (SDL_PollEvent(&event) != 0) {
    if(event.type == SDL_QUIT){
      Joe::Application::SetRunning(false);
    }
    if(event.key.keysym.sym == KEYS::JOE_KEY_ESCAPE){
      Joe::Application::SetRunning(false);
    }
    if(event.key.keysym.sym == KEYS::JOE_KEY_W){
      JOE_INFO("W::PRESSED");
    }
  }
}

void Actor::OnEvent(Joe::Event& event){

}
