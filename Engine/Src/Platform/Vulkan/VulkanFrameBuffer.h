#pragma once
#include <vulkan/vulkan.h>

namespace Joe {
  class VulkanFrameBuffer{
    static VkFramebuffer m_FrameBuffer;
  public:
    static void Create();

    static VkFramebuffer GetFrameBufferHandle(){ return m_FrameBuffer;}
  };
}
