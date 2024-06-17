#include "Joepch.h"
#include "vulkan_core.h"
#include "VulkanSwapchain.h"
#include <GLFW/glfw3.h>
#include <VkBootstrap.h>
#include <vulkan/vulkan_core.h>

namespace Joe{
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
        .set_desired_present_mode(VK_PRESENT_MODE_IMMEDIATE_KHR)
        .set_desired_extent(width,height)
        .set_old_swapchain(VK_NULL_HANDLE)
        .build()
        .value();
    }
    
    m_Swapchain = vkbSwapchain.swapchain;
    m_SwapchainImages = vkbSwapchain.get_images().value();
    m_SwapchainImageView = vkbSwapchain.get_image_views().value();

    m_Extent = vkbSwapchain.extent;
    
    m_SwapchainImageFormat = vkbSwapchain.image_format;
	}
}
