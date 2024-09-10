#include <Joepch.h>
#include "VulkanRenderPass.h"

namespace Joe {
  void VulkanRenderPass::Create(){
    VkRenderPassCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
  }
}
