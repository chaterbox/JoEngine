#pragma once
#include <vulkan.h>

struct GLFWwindow;

//TODO: create swapchain

namespace Joe{
	class VulkanSwapchain{
	public:
		static void Create(bool VSync);

		static VkSwapchainKHR GetSwapchainKHRHandle() { return m_Swapchain; }
	private:
		static inline VkSwapchainKHR m_Swapchain;
		VkSurfaceCapabilitiesKHR surCap;
		VkSurfaceFormatKHR surFormat;
	};
}
