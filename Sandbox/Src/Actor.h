#pragma once 
#include <Joe.h>
#include <SDL2/SDL_events.h>

 class Actor : public Joe::Layer
 {
 public:
    Actor();

    virtual void OnImGuiRender() override;

    void OnUpdate() override;

    void OnEvent(Joe::Event& event)override;

 private:
    SDL_Event event;
 };
