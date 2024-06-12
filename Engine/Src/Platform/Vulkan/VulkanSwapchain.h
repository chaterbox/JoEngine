#pragma once
#include <vulkan.h>
#include <vector>

struct GLFWwindow;

namespace Joe{
	class VulkanSwapchain{
	public:
		void Create(VkInstance instance,VkPhysicalDevice phyDevice,VkDevice logDevice,bool VSync);
		static void CreateSurface(VkInstance instance, GLFWwindow* m_WindowHandle);
		void CreateImageViews(VkDevice logDevice);

		VkSurfaceKHR GetSurfaceKHRHandle() { return surface; }

		const std::vector<VkImageView> GetImageViewHandle() { return m_Imageview; }
		const std::vector<VkImage> GetSwapImagesHandle() { return m_SwapImages; }
		VkSwapchainKHR GetSwapchainKHRHandle() { return m_Swapchain; }
	private:
		static inline VkSurfaceKHR surface;

		VkSwapchainKHR m_Swapchain;
		VkSurfaceCapabilitiesKHR surCap;
		VkSurfaceFormatKHR surFormat;
		
		uint32_t swapchainCount{ 0u };
		std::vector<VkImage> m_SwapImages;

		std::vector<VkImageView> m_Imageview;
	};
}
