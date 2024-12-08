#include "Joepch.h"
#include "VulkanSwapchain.h"
#include "VulkanContext.h"
#include <VkBootstrap.h>
#include <vulkan/vulkan.h>

namespace Joe{
  VulkanSwapchain::~VulkanSwapchain(){
  vkDestroySwapchainKHR(VulkanContext::GetLogicalDeviceHandle(), m_Swapchain, nullptr);
}

	void VulkanSwapchain::Create(VkPhysicalDevice phyDevice,VkDevice device,VkSurfaceKHR surface,bool VSync,unsigned int width,unsigned int height){
    vkb::SwapchainBuilder swapchainBuilder{phyDevice,device,surface};
    vkb::Swapchain vkbSwapchain;
    if(VSync){
      vkbSwapchain = swapchainBuilder
        .use_default_format_selection()
        .set_desired_present_mode(VK_PRESENT_MODE_FIFO_KHR)
        .set_desired_extent(width,height)
        .set_old_swapchain(VK_NULL_HANDLE)
        .build()
        .value();
    }
    else{
      vkbSwapchain = swapchainBuilder
        .use_default_format_selection()
        .set_desired_present_mode(VK_PRESENT_MODE_MAILBOX_KHR)
        .set_desired_extent(width,height)
        .set_old_swapchain(VK_NULL_HANDLE)
        .build()
        .value();
    }

    if(vkbSwapchain){
      JOE_ENGINE_INFO("RHIvulkan::SWAPCHAIN::CREATION::SUCCESS\n");
    }else {
      JOE_ENGINE_INFO("RHIvulkan::SWAPCHAIN::CREATION::FAILED\n");
    }
    
    m_Swapchain = vkbSwapchain.swapchain;
    m_SwapchainImages = vkbSwapchain.get_images().value();
    m_SwapchainImageView = vkbSwapchain.get_image_views().value();

    m_Extent = vkbSwapchain.extent;
    
    m_SwapchainImageFormat = vkbSwapchain.image_format;
	}
}
