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

}

void Actor::OnEvent(Joe::Event& event){

}
