#include "Actor.h"  

Actor::Actor() : Layer("Actor"){
  JOE_INFO("ACTOR::INIT");
}

void Actor::OnImGuiRender(){

}

void Actor::OnUpdate(){
  if(Joe::Input::IsKeyPressed(KEYS::JOE_KEY_W)){
    JOE_INFO("W::PRESSED");
    }
}
