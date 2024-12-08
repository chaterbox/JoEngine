#pragma once 
#include <Joe.h>

 class Actor : public Joe::Layer
 {
 public:
    Actor();

    virtual void OnImGuiRender() override;

    void OnUpdate() override;
 };
