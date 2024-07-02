#include "Actor.h" 
#include "Joe/KeyCode.h"
#include "Joe/Events/KeyboardEvent.h"

Actor::Actor() : Layer("Actor"){
  JOE_INFO("ACTOR::INIT");
}

void Actor::OnImGuiRender(){

}

void Actor::OnUpdate(){
  if(Joe::KeyboardEvent::IsKeyPressed(KEYS::JOE_KEY_W)){
    JOE_INFO("W::PRESSED");
    }
}
