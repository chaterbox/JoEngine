#include "Joepch.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_video.h>
#include "SdlWindow.h"

#include "Joe/Input/KeyCodes/KeyCode.h"
#include "Joe/Core/Application.h"
//SDL
#include "Platform/Sdl/SdlInput.h"
//RHISDL3
#include "Platform/RHI/SDL3/SDL3Context.h"
//RHIVulkan
#include "Platform/RHI/Vulkan/VulkanContext.h"
#include "Platform/RHI/Vulkan/VulkanSwapchain.h"
#include "Platform/RHI/Vulkan/VulkanShader.h"
#include "Platform/RHI/Vulkan/VulkanPipeline.h"

#include "Joe/Renderer/RHI.h"

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

      const int SDLversion = SDL_GetVersion();

      if(!s_SdlInitialized){
        if(SDL_Init(SDL_INIT_VIDEO)){
          JOE_ENGINE_INFO("SDL::INIT");
          JOE_ENGINE_INFO("SDL::VERSION::{0}.{1}.{2}",SDL_VERSIONNUM_MAJOR(SDLversion),SDL_VERSIONNUM_MINOR(SDLversion),SDL_VERSIONNUM_MICRO(SDLversion));
        }else{
          JOE_ENGINE_FATAL("SDL::ERROR::{0}", SDL_GetError());
        }
        s_SdlInitialized = true;
      }

      SdlInput::InitGamepad();    

      SDL_WindowFlags windowFlags = {};
    
      switch (RHI::GetAPI()) {
        case RHI::BACKEND::None:
          break;
        case RHI::BACKEND::SDL3:
          windowFlags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE);
          break;
        case RHI::BACKEND::Vulkan_WIP:
          windowFlags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
          break;
      }

      m_Window = SDL_CreateWindow(props.Title, props.Width, props.Height, windowFlags);

      if(m_Window != NULL){
        JOE_ENGINE_INFO("SDL::WINDOW::CREATION::SUCCESS:TITLE:{0} WIDTH:{1} HEIGHT:{2}\n", props.Title, props.Width, props.Height);
      }else{
        JOE_ENGINE_FATAL("SDL::ERROR::{0}\n", SDL_GetError());
      }
    
      SDL_SetWindowMinimumSize(m_Window,300,300);

      switch (RHI::GetAPI()){        
        case RHI::BACKEND::None:
        case RHI::BACKEND::SDL3:
          m_Context = new SDL3Context(m_Window);
          JOE_ENGINE_INFO("RHI::SDL3\n");
          m_Context->Init();
          break;
        case RHI::BACKEND::Vulkan_WIP:
          m_Context = new VulkanContext(m_Window);
          JOE_ENGINE_INFO("RHI::VULKAN");
          JOE_ENGINE_INFO("RHIvulkan::Is Work In Process");
          m_Context->Init();
          break;
      }

      SetVSync(true);
    
      if(RHI::GetAPI() == RHI::BACKEND::Vulkan_WIP){
        VulkanSwapchain::Create(VulkanContext::GetPhyDeviceHandle(), VulkanContext::GetLogicalDeviceHandle(), VulkanContext::GetSurfaceHandle(),IsVSync(), m_Data.Width, m_Data.Height);

        m_VertexShader = VulkanShader::Create("../../../Assets/Shaders/glsl/triangleVert.glsl",ShaderType::Vert);
        m_FragmentShader = VulkanShader::Create("../../../Assets/Shaders/glsl/triangleFrag.glsl", ShaderType::Frag);

        pipeline = VulkanPipeline::Create(PipelineType::Rasterisation);
      }else if (RHI::GetAPI() == RHI::BACKEND::SDL3) {

      }
	}

    void SdlWindow::Shutdown(){
      SDL_DestroyWindow(m_Window);
      SDL_Quit();
    }

	void SdlWindow::OnUpdate(){
      //TODO: SDL:: add a controller connected check
      if(RHI::GetAPI() == RHI::BACKEND::SDL3 ){
        SDL3Context::Render();
      }
      if(SDL_WaitEvent(&event)){
        if(event.type == SDL_EVENT_QUIT){
          Application::Quit();
        }
        if(event.key.key == KEYS::JOE_KEY_ESCAPE){
          Application::Quit();
        }
          if(event.window.type == SDL_EVENT_WINDOW_RESIZED){
            m_Data.Width = event.window.data1;
            m_Data.Height = event.window.data2;
            
            JOE_ENGINE_INFO("SDL::WINDOW::RESIZED::WIDTH:{0} HEIGHT:{1}",m_Data.Width,m_Data.Height);

            vkDestroySwapchainKHR(VulkanContext::GetLogicalDeviceHandle(), VulkanSwapchain::GetSwapchainKHRHandle(), nullptr);

            VulkanSwapchain::Create(VulkanContext::GetPhyDeviceHandle(), VulkanContext::GetLogicalDeviceHandle(), VulkanContext::GetSurfaceHandle(), IsVSync(), m_Data.Width, m_Data.Height);
          }
      }
  }

	void SdlWindow::SetVSync(bool enabled){
		m_Data.VSync = enabled;
	}

	bool SdlWindow::IsVSync() const{
		return m_Data.VSync;
	}
}

