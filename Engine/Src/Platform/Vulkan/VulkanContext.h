#pragma once
#include <vulkan_core.h>
#include <vulkan.h>
#include "Joe/Renderer/GraphicsContext.h"
#include <vector>

struct GLFWwindow;

namespace Joe{
	class JOE_API VulkanContext :public GraphicsContext{
	public:
		VulkanContext();
		~VulkanContext();

		virtual void Init() override;
		virtual void Swapbuffers() override;

		static VkInstance GetInstanceHandle() { return instance; }
		static VkPhysicalDevice GetPhyDeviceHandle() { return m_PhysDevice; }
		static VkPhysicalDeviceProperties GetPhyDevicePropHandle() { return m_DeviceProp; }
		static VkDevice GetLogicalDeviceHandle() { return  m_LogicalDevice; }
	private:
		static inline VkInstance instance;
		std::vector<const char*>instanceExtensions = {VK_KHR_SURFACE_EXTENSION_NAME};

		static inline VkPhysicalDevice m_PhysDevice;
		static inline VkPhysicalDeviceProperties m_DeviceProp;

		static inline VkDevice m_LogicalDevice;
	};
}




