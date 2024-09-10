#pragma once
#include <vulkan/vulkan.h>
namespace Joe{
  class VulkanRenderPass{
    static VkRenderPass m_RenderPass;
  public:
    static void Create();

    static VkRenderPass GetRenderPassHandle(){ return m_RenderPass;}
  };
}
