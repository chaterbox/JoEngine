#pragma once
#include <vulkan.h>
namespace Joe{
	class VulkanRenderpass{
	public:
		void Create(VkDevice logDevice);

		VkRenderPass GetRenderpassHandle() { return renderpass; }
	private:
		VkRenderPass renderpass;
	};
}
