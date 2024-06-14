#pragma once
#include <vulkan.h>

struct GLFWwindow;

namespace Joe{
	class VulkanSwapchain{
	public:
		void Create(bool VSync);

		VkSwapchainKHR GetSwapchainKHRHandle() { return m_Swapchain; }
	private:
		VkSwapchainKHR m_Swapchain;
		VkSurfaceCapabilitiesKHR surCap;
		VkSurfaceFormatKHR surFormat;
	};
}
