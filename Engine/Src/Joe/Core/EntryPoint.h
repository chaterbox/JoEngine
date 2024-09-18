#pragma once
#include "Log.h"
#include "Application.h"
#ifdef JOE_PLATFORM_LINUX
#include <sys/utsname.h>
#endif // LINUX

#if defined(JOE_PLATFORM_LINUX) || defined(JOE_PLATFORM_WINDOWS)

extern Joe::Application* Joe::CreateApplication();

int main(){
	Joe::Log::Init();

  JOE_CORE_INFO("JOENGINE::INIT");
  JOE_CORE_INFO("LOG::INIT\n");

  #ifdef JOE_PLATFORM_LINUX
    struct utsname details;
    int ret = uname(&details);

    if(ret == 0){
      JOE_CORE_INFO("OS::{0}",details.sysname);
      JOE_CORE_INFO("OS::DISTRO::{0}",details.nodename);
      JOE_CORE_INFO("OS::DISTRO::VERSION::{0}",details.version);
      JOE_CORE_INFO("OS::KERNEL::VERSION::{0}",details.release);
      JOE_CORE_INFO("OS::ARCHITECTURE::{0}",details.machine);
    }
  #endif // LINUX
  auto app = Joe::CreateApplication();
  app->Run();
  delete app;
}
#endif
 
#ifdef JOE_PLATFORM_WINDOWS
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	Joe::Log::Init();
	JOE_CORE_INFO("init log");
	auto app = Joe::CreateApplication();
	app->Run();
	delete app;
}
#endif // JOE_PLATFORM_WINDOWS
