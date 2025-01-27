#pragma once
#include <cstdint>
#include <vulkan/vulkan.h>
#include "Joe/Renderer/GraphicsContext.h"
#include <vk_mem_alloc.h>
#include <SDL3/SDL.h>

struct SDLwindow;

namespace Joe{
  enum VendorIDs{
	AMD = 0x1002,
	NVIDIA = 0x10DE,
	INTEL = 0x8086,
	APPLE = 0x106B,
	ARM = 0x13B5,
	Qualcomm = 0x5143
  };

  enum DeviceIDs{
	STEAMDECK = 0x163F
  };

	class JOE_API VulkanContext :public GraphicsContext{
	public:
		VulkanContext(SDL_Window* window);
		~VulkanContext();

		virtual void Init() override;

		static VkInstance GetInstanceHandle() { return m_Instance; }

		static inline VkSurfaceKHR GetSurfaceHandle() { return m_Surface; }
		static VkPhysicalDevice GetPhyDeviceHandle() { return m_PhysDevice; }

		static VkDevice GetLogicalDeviceHandle() { return  m_LogicalDevice; }

		static VkQueue GetGraphicsQueueHandle() { return m_GraphicsQueue; }
		static uint32_t GetGraphicsQueueFamily() { return m_GraphicsQueueFamily; }

		static VmaAllocator GetVmaAllotorHandle() { return m_Allocator; }

		static bool IsSteamDeck(){ return bIsSteamDeck;}
	private:
		static inline VkInstance m_Instance;
  
		static inline VkSurfaceKHR m_Surface;
		static inline VkPhysicalDevice m_PhysDevice;
		static inline VkPhysicalDeviceProperties m_DeviceProp;

		static inline bool bIsSteamDeck = false;

		static inline VkDevice m_LogicalDevice;

		static inline VkQueue m_GraphicsQueue;
		static inline uint32_t m_GraphicsQueueFamily;

		static inline VmaAllocator m_Allocator;

		SDL_Window* m_WindowHandle;
	};
}
