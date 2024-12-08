#pragma once 
#include <Joe.h>

 class Editor : public Joe::Layer
 {
 public:
    Editor();

    virtual void OnImGuiRender() override;

    void OnUpdate() override;
 };
