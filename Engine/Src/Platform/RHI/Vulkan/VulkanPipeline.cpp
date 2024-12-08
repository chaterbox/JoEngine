#include <Joepch.h>
#include "VulkanPipeline.h"

namespace Joe {
  VkPipeline VulkanPipeline::Create(PipelineType pipeType){
    VkPipeline pipeline;
    if(pipeType == PipelineType::Rasterisation){
      //TODO: VULKAN implement rasterisation pipeline
    }
    return pipeline;
  }
}
