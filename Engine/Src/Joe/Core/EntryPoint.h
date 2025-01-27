#pragma once
#include "Log.h"
#include "Application.h"  
#include "Core.h"
#include <fstream>
#ifdef JOE_PLATFORM_LINUX
#include <sys/utsname.h>
#endif // LINUX

#if defined(JOE_PLATFORM_LINUX) || defined(JOE_PLATFORM_WINDOWS) || defined(JOE_PLATFORM_MACOS)

extern Joe::Application* Joe::CreateApplication();

int main(){
	Joe::Log::Init();

  JOE_ENGINE_INFO("JOENGINE::INIT");
  Joe::EngineConfig::Init();

  #ifdef JOE_PLATFORM_LINUX
    struct utsname details;
    int ret = uname(&details);

    std::string wProtocolName = std::getenv("XDG_SESSION_TYPE");
    std::string deName = std::getenv("XDG_SESSION_DESKTOP");

    std::ifstream os_release("/etc/os-release");
    std::stringstream osStringStream
  ;
    std::string distro;
    std::string distroVersion;

    osStringStream << os_release.rdbuf();
    distro = osStringStream.str();
    size_t FindID = distro.find("PRETTY_NAME");
    if(FindID != std::string::npos){
      distro.erase(0,FindID);
      size_t beginString = distro.find_first_of("=");
      distro.erase(0,beginString + 1);
      size_t endString = distro.find_first_of("\n");
      distro.erase(endString,distro.size());
    }

    distroVersion = osStringStream.str();
    FindID = distroVersion.find("VERSION_ID");
    if(FindID != std::string::npos){
      distroVersion.erase(0,FindID);
      size_t beginString = distroVersion.find_first_of("=");
      distroVersion.erase(0,beginString + 1);
      size_t endString = distroVersion.find_first_of("\n");
      distroVersion.erase(endString,distroVersion.size());
    }

    if(ret == 0){
      JOE_ENGINE_INFO("OS::{0}",details.sysname);
      JOE_ENGINE_INFO("OS::DISTRO::{0}",distro);
      if(FindID != std::string::npos)
        JOE_ENGINE_INFO("OS::DISTRO::VERSION::{0}",distroVersion);
      JOE_ENGINE_INFO("OS::KERNEL::VERSION::{0}",details.release);
      JOE_ENGINE_INFO("CPU::ARCHITECTURE::{0}\n",details.machine);
      JOE_ENGINE_INFO("OS::DISPLAY::PROTOCOL::{0}",wProtocolName);
      JOE_ENGINE_INFO("OS::DESKTOP_ENVIROMENT::{0}\n",deName);
    }
  #endif // LINUX
#ifdef JOE_PLATFORM_WINDOWS
    std::string arch = std::getenv("PROCESSOR_ARCHITECTURE");
    std::string os = std::getenv("OS");

    JOE_ENGINE_INFO("OS::{0}", os);
    JOE_ENGINE_INFO("CPU::ACHITECTURE::{0}\n", arch);
#endif // JOE_PLATFORM_WINDOWS

  auto app = Joe::CreateApplication();
  app->Run();
  delete app;
}
#endif
 
#ifdef JOE_PLATFORM_WINDOWS
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	Joe::Log::Init();
	JOE_ENGINE_INFO("init log");
	auto app = Joe::CreateApplication();
	app->Run();
	delete app;
}
#endif // JOE_PLATFORM_WINDOWS
