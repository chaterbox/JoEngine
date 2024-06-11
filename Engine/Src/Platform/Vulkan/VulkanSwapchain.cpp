#include "Joepch.h"
#include "VulkanUtils.h"
#include "VulkanSwapchain.h"
#include <GLFW/glfw3.h>

namespace Joe{
	void VulkanSwapchain::Create(VkInstance instance, VkPhysicalDevice phyDevice, VkDevice logDevice,bool VSync){
		VkBool32 surfaceSupport;
		vkGetPhysicalDeviceSurfaceSupportKHR(phyDevice, 0, surface, &surfaceSupport);
		vkGetPhysicalDeviceSurfaceCapabilitiesKHR(phyDevice, surface, &surCap);
		uint32_t surfaceFormatCount = 0;
		vkGetPhysicalDeviceSurfaceFormatsKHR(phyDevice, surface, &surfaceFormatCount, &surFormat);
		
		VkSwapchainCreateInfoKHR swapChainInfo = {};
		swapChainInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		swapChainInfo.surface = surface;
		swapChainInfo.queueFamilyIndexCount = 0;
		swapChainInfo.imageExtent = surCap.currentExtent;
		swapChainInfo.minImageCount = surCap.minImageCount + 1;
		swapChainInfo.preTransform = surCap.currentTransform;

		uint32_t presentModeCount = 0;
		vkGetPhysicalDeviceSurfacePresentModesKHR(phyDevice, surface, &presentModeCount, nullptr);
		if (presentModeCount == 0){
			JOE_CORE_ERROR("VULKAN: No avalible presentModes");
		}

		std::vector<VkPresentModeKHR>presentMode(presentModeCount);
		vkGetPhysicalDeviceSurfacePresentModesKHR(phyDevice, surface, &presentModeCount, presentMode.data());

		VkPresentModeKHR swapchainPresentMode = VK_PRESENT_MODE_FIFO_KHR;

		if (!VSync){
			for (size_t i = 0; i < presentModeCount; i++){
				if (presentMode[i] == VK_PRESENT_MODE_MAILBOX_KHR){
					swapchainPresentMode = VK_PRESENT_MODE_MAILBOX_KHR;
				}
				if ((swapchainPresentMode != VK_PRESENT_MODE_MAILBOX_KHR) && (presentMode[i] == VK_PRESENT_MODE_IMMEDIATE_KHR)){
					swapchainPresentMode = VK_PRESENT_MODE_IMMEDIATE_KHR;
				}
			}
		}

		swapChainInfo.presentMode = swapchainPresentMode;
		swapChainInfo.imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
		swapChainInfo.imageArrayLayers = surCap.maxImageArrayLayers;
		swapChainInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
		swapChainInfo.imageFormat = VK_FORMAT_B8G8R8A8_SRGB;
		swapChainInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
		swapChainInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
		
		if (vkCreateSwapchainKHR(logDevice, &swapChainInfo, nullptr, &m_Swapchain) != VK_SUCCESS) {
			JOE_FATAL("VULKAN::SWAPCHAIN::CREATE::FAILED");
		}
	}

	void VulkanSwapchain::CreateSurface(VkInstance instance, GLFWwindow* m_WindowHandle){
		if (glfwCreateWindowSurface(instance, m_WindowHandle, nullptr, &surface) != VK_SUCCESS) {
			JOE_FATAL("VULKAN::SURFACE::CREATE::FAILED");
		}
	}

	void VulkanSwapchain::CreateImageViews(VkDevice logDevice){
		vkGetSwapchainImagesKHR(logDevice, m_Swapchain, &swapchainCount, nullptr);
		m_SwapImages.resize(swapchainCount);
		vkGetSwapchainImagesKHR(logDevice, m_Swapchain, &swapchainCount, m_SwapImages.data());

		m_Imageview.resize(swapchainCount);

		for (size_t i = 0; i < m_SwapImages.size(); i++){
			VkImageViewCreateInfo viewCreateInfo = {};
			viewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
			viewCreateInfo.image = m_SwapImages[i];
			viewCreateInfo.format = VK_FORMAT_B8G8R8A8_SRGB;
			viewCreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
			viewCreateInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
			viewCreateInfo.subresourceRange.baseMipLevel = 0;
			viewCreateInfo.subresourceRange.levelCount = 1;
			viewCreateInfo.subresourceRange.baseArrayLayer = 0;
			viewCreateInfo.subresourceRange.layerCount = 1;

			if (vkCreateImageView(logDevice, &viewCreateInfo, nullptr, &m_Imageview[i]) != VK_SUCCESS) {
				JOE_CORE_FATAL("VULKAN::SURFACE::CREATE::FAILED");
			}
		}
	}
}
