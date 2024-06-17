#pragma once
#include <cstdint>
#include <vulkan_core.h>
#include <vulkan.h>
#include "Joe/Renderer/GraphicsContext.h"
#include <vk_mem_alloc.h>

struct GLFWwindow;

namespace Joe{
  struct VendorIDs{
	  static const uint32_t AMD = 0x1002;
	  static const uint32_t NVIDIA = 0x10DE;
	  static const uint32_t INTEL = 0x8086;
    static const uint32_t APPLE = 0x106B;
	  static const uint32_t ARM = 0x13B5;
	  static const uint32_t Qualcomm = 0x5143;
  };

	class JOE_API VulkanContext :public GraphicsContext{
	public:
		VulkanContext(GLFWwindow* window);
		~VulkanContext();

		virtual void Init() override;
		virtual void Swapbuffers() override;

		static VkInstance GetInstanceHandle() { return m_Instance; }

    static inline VkSurfaceKHR GetSurfaceHandle() { return m_Surface; }
		static VkPhysicalDevice GetPhyDeviceHandle() { return m_PhysDevice; }

		static VkDevice GetLogicalDeviceHandle() { return  m_LogicalDevice; }

    static VkQueue GetGraphicsQueueHandle() { return m_GraphicsQueue; }
    static uint32_t GetGraphicsQueueFamily() { return m_GraphicsQueueFamily; }

    static VmaAllocator GetVmaAllotorHandle() { return m_Allocator; }
	private:
		static inline VkInstance m_Instance;
  
    static inline VkSurfaceKHR m_Surface;
		static inline VkPhysicalDevice m_PhysDevice;
		static inline VkPhysicalDeviceProperties m_DeviceProp;

		static inline VkDevice m_LogicalDevice;

    static inline VkQueue m_GraphicsQueue;
    static inline uint32_t m_GraphicsQueueFamily;

    static inline VmaAllocator m_Allocator;

		GLFWwindow* m_WindowHandle;
	};
}




