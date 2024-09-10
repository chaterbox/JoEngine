#include <Joepch.h>
#include "VulkanFrameBuffer.h"

namespace Joe {
  void VulkanFrameBuffer::Create(){
    VkFramebufferCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
  }
}
