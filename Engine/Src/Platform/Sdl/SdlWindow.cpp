#include "Joe/Log.h"
#include "Joepch.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include "SdlWindow.h"

#include "Joe/Events/ApplicationEvents.h"
#include "Joe/Events/MouseEvent.h"
#include "Joe/Events/KeyEvent.h"
#include "Joe/KeyCode.h"
#include "Joe/Application.h"
//Vulkan
#include "Platform/Sdl/SdlInput.h"
#include "Platform/Vulkan/VulkanContext.h"
#include "Platform/Vulkan/VulkanSwapchain.h"

#include "Joe/Renderer/RendererAPI.h"

namespace Joe {
	static bool s_SdlInitialized = false;

	Window* Window::Create(const WindowProps& props){
		return new SdlWindow(props);
	}

	SdlWindow::SdlWindow(const WindowProps& props){
		Init(props);
	}

	SdlWindow::~SdlWindow(){
		Shutdown();
	}

	void SdlWindow::Init(const WindowProps& props){
      m_Data.Title = props.Title;
      m_Data.Width = props.Width;
      m_Data.Height = props.Height;

      std::cout << "\n";

      if(!s_SdlInitialized){
        if(SDL_Init(SDL_INIT_VIDEO) != 0){
          JOE_CORE_FATAL("SDL::ERROR::{0}", SDL_GetError());
        }else{
          JOE_CORE_INFO("SDL::INIT");
        }
        s_SdlInitialized = true;
      }

      SdlInput::InitGamepad();    

      SDL_WindowFlags windowFlags = {};
    
      switch (RendererAPI::GetAPI()) {
        case Joe::RendererAPI::API::Vulkan:
          windowFlags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
          break;
        case Joe::RendererAPI::API::None:
          break;
      }

      m_Window = SDL_CreateWindow(props.Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, props.Width, props.Height, windowFlags);

      if(m_Window != NULL){
        JOE_CORE_INFO("SDL::WINDOW::CREATION::SUCCESS:TITLE:{0} WIDTH:{1} HEIGHT:{2}", props.Title, props.Width, props.Height);
      }else{
        JOE_CORE_FATAL("SDL::ERROR::{0}", SDL_GetError());
      }

      std::cout << "\n";
    
      SDL_SetWindowMinimumSize(m_Window,300,300);

      switch (RendererAPI::GetAPI()){
        case Joe::RendererAPI::API::Vulkan:
          m_Context = new VulkanContext(m_Window);
          break;
        case Joe::RendererAPI::API::None:
          m_Context = nullptr;
      }
		
      m_Context->Init();

      SetVSync(true);
    
      if(RendererAPI::GetAPI() == RendererAPI::API::Vulkan){
        VulkanSwapchain::Create(VulkanContext::GetPhyDeviceHandle(), VulkanContext::GetLogicalDeviceHandle(), VulkanContext::GetSurfaceHandle(),IsVSync(), m_Data.Width, m_Data.Height);
      }
	}

    void SdlWindow::Shutdown(){
      SDL_DestroyWindow(m_Window);
      SDL_Quit();
    }

	void SdlWindow::OnUpdate(){
    
	}

	void SdlWindow::SetVSync(bool enabled){
		m_Data.VSync = enabled;
	}

	bool SdlWindow::IsVSync() const{
		return m_Data.VSync;
	}
}

