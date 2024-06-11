#include "Joepch.h"
#include "VulkanRenderpass.h"
namespace Joe{
	void VulkanRenderpass::Create(VkDevice logDevice){
		VkRenderPassCreateInfo renderpassCreateInfo = {};
		renderpassCreateInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;

		vkCreateRenderPass(logDevice, &renderpassCreateInfo, nullptr, &renderpass);
	}
}
