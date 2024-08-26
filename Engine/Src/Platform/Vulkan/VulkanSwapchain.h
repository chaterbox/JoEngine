#pragma once
#include <cstdint>
#include <vulkan/vulkan.h>
#include <vector>

namespace Joe{
	class VulkanSwapchain{
	public:
    VulkanSwapchain() = default;
    ~VulkanSwapchain();
  
		static void Create(VkPhysicalDevice phyDevice,VkDevice device,VkSurfaceKHR surface,bool VSync,unsigned int width,unsigned int height);

		static VkSwapchainKHR GetSwapchainKHRHandle() { return m_Swapchain; }
		static VkExtent2D GetExtentHandle() { return m_Extent;}
	private:
		static inline VkSwapchainKHR m_Swapchain;
		static inline VkFormat m_SwapchainImageFormat;

		static inline VkExtent2D m_Extent;
    
		static inline uint32_t m_SwapchainImageCount;
		static inline std::vector<VkImage> m_SwapchainImages;
		static inline std::vector<VkImageView> m_SwapchainImageView;
	};
}
