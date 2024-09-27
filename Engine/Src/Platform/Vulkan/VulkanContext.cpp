#include "Joe/Core/Log.h"
#include "Joepch.h"
#include "Platform/Sdl/SdlWindow.h"
#include "VulkanContext.h"
#include <vulkan/vulkan.h>
#include <VkBootstrap.h>
#include <SDL2/SDL_vulkan.h>
#include <iostream>

namespace Joe{
	void VulkanContext::Init(){
#ifdef JOE_DEBUG
  bool valdation = true;
#else 
  bool valdation = false;
#endif
		///////////////////////////////////////////
		////               instance            ////
		///////////////////////////////////////////
  vkb::InstanceBuilder builder;
  auto inst_ret = builder.set_app_name("JoEngine")
  .request_validation_layers(valdation)
  .add_debug_messenger_severity(VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
  .add_debug_messenger_severity(VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT)
  .add_debug_messenger_type(VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT)
  .add_debug_messenger_type(VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT)
  .use_default_debug_messenger()
  .require_api_version(1,2,0)
  .build();

  vkb::Instance vkb_inst = inst_ret.value();

  if(!inst_ret){
    JOE_CORE_FATAL("VULKAN::INSTANCE::CREATION::FAILED");
  }else{
    JOE_CORE_INFO("VULKAN::INSTANCE::CREATION::SUCCESS");
  }

  m_Instance = vkb_inst.instance;
  
  SDL_Vulkan_CreateSurface(m_WindowHandle, m_Instance, &m_Surface);

  vkb::PhysicalDeviceSelector selector{vkb_inst};

  vkb::PhysicalDevice physicalDevice;
  VkPhysicalDeviceFeatures features = {};
   
  physicalDevice = selector
    .set_minimum_version(1,2)
    .set_surface(m_Surface)
    .set_required_features(features)
    .select()
    .value();

  vkb::DeviceBuilder deviceBuilder{physicalDevice};
  vkb::Device vkbDevice = deviceBuilder.build().value();

  if(!vkbDevice){
    JOE_CORE_FATAL("VULKAN::DEVICE::CREATION::FAILED");
  }else{
    JOE_CORE_INFO("VULKAN::DEVICE::CREATION::SUCCESS");
  }
  m_PhysDevice = physicalDevice.physical_device;
  m_LogicalDevice = vkbDevice.device;

  m_GraphicsQueue = vkbDevice.get_queue(vkb::QueueType::graphics).value();

  m_GraphicsQueueFamily = vkbDevice.get_queue_index(vkb::QueueType::graphics).value();

  JOE_CORE_INFO("VULKAN::QUEUEFAMILY::GRAPHICS::{0}\n",m_GraphicsQueueFamily);

  	///////////////////////////////////////////
		////            device info            ////
		///////////////////////////////////////////

  JOE_CORE_INFO("VULKAN [DEVICE INFO]");

  int apiMajor,apiMinor,apiPatch,driverMajor,driverMinor,driverPatch;

  apiMajor = VK_VERSION_MAJOR(physicalDevice.properties.apiVersion);
  apiMinor = VK_VERSION_MINOR(physicalDevice.properties.apiVersion);
  apiPatch = VK_VERSION_PATCH(physicalDevice.properties.apiVersion);

  driverMajor = VK_VERSION_MAJOR(physicalDevice.properties.driverVersion);
  driverMinor = VK_VERSION_MINOR(physicalDevice.properties.driverVersion);
  driverPatch = VK_VERSION_PATCH(physicalDevice.properties.driverVersion);

  if(physicalDevice.properties.vendorID == VendorIDs::AMD){
    JOE_CORE_INFO("VULKAN [VENDOR] AMD");
  }

  if(physicalDevice.properties.vendorID == VendorIDs::NVIDIA){
    JOE_CORE_INFO("VULKAN [VENDOR] NVIDIA");
  }

  if(physicalDevice.properties.vendorID == VendorIDs::INTEL){
    JOE_CORE_INFO("VULKAN [VENDOR] INTEL");
  }

  if(physicalDevice.properties.vendorID == VendorIDs::APPLE){
    JOE_CORE_INFO("VULKAN [VENDOR] APPLE");
  }

  JOE_CORE_INFO("VULKAN [DEVICE NAME] {0}", physicalDevice.properties.deviceName);
  JOE_CORE_INFO("VULKAN [DRIVER VERSION] {0},{1},{2}",driverMajor,driverMinor,driverPatch);
  JOE_CORE_INFO("VULKAN [API VERSION] {0},{1},{2}",apiMajor,apiMinor,apiPatch);

  if(physicalDevice.properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_CPU){
    JOE_CORE_INFO("VULKAN [DEVICE TYPE] CPU\n");
  }
  if(physicalDevice.properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU){
    JOE_CORE_INFO("VULKAN [DEVICE TYPE] DISCRETE GPU\n");
  }
  if(physicalDevice.properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU){
    JOE_CORE_INFO("VULKAN [DEVICE TYPE] INTERGRATED GPU\n");
  }

      /////////////////////////////////////////
      ////              vma                ////
      /////////////////////////////////////////

    VmaAllocatorCreateInfo allocatorInfo = {};
    allocatorInfo.physicalDevice = m_PhysDevice;
    allocatorInfo.device = m_LogicalDevice;
    allocatorInfo.instance = m_Instance;

    if(vmaCreateAllocator(&allocatorInfo, &m_Allocator)!= VK_SUCCESS){
      JOE_CORE_FATAL("VULKAN::VMA::ALLOCATOR::CREATION::FAILED\n");
    }else{
      JOE_CORE_INFO("VULKAN::VMA::ALLOCATOR::CREATION::SUCCESS\n");
    }
	}

	VulkanContext::VulkanContext(SDL_Window* window)
  : m_WindowHandle(window){
	}

	VulkanContext::~VulkanContext(){
		vkDestroyInstance(m_Instance, nullptr);
    vkDestroySurfaceKHR(m_Instance, m_Surface, nullptr);
    vkDestroyDevice(m_LogicalDevice, nullptr);
    vmaDestroyAllocator(m_Allocator);
	}
}
