#pragma once
#include <vulkan/vulkan.h>
namespace Joe{

  enum class PipelineType{
  Compute,
  Rasterisation,
  RayTracing
  };

  class VulkanPipeline{
  public:
    static VkPipeline Create(PipelineType pipeType);
  private:
    static VkPipeline createRasterisationPipeline();
  };
}
