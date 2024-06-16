#pragma once
#include <sys/uio.h>
#include "Log.h"
#include "Application.h"

#if defined(JOE_PLATFORM_LINUX)

extern Joe::Application* Joe::CreateApplication();

int main(int argc,char** argv){
	Joe::Log::Init();
	JOE_CORE_INFO("JOENGINE::INIT");
	JOE_CORE_INFO("LOG::INIT");
	auto app = Joe::CreateApplication();
	app->Run();
	delete app;
}
#endif
 
#ifdef JOE_PLATFORM_WINDOWS
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	Joe::Log::Init();
	JOE_CORE_INFO("init log");
	auto app = Jovk::CreateApplication();
	app->Run();
	delete app;
}
#endif // JOE_PLATFORM_WINDOWS
