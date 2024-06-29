#include "Actor.h" 
#include "Joe/Events/Event.h"
#include "Joe/Input.h"
#include "Joe/Log.h"

Actor::Actor() : Layer("Actor"){
  JOE_INFO("ACTOR::INIT");
}

void Actor::OnImGuiRender(){

}

void Actor::OnUpdate(){
  if(Joe::Input::IsKeyPressed(KEYS::JOE_KEY_W))
  {
    JOE_INFO("ACTOR::MOVE::UP");
  }
}

void Actor::OnEvent(Joe::Event& event){

}
