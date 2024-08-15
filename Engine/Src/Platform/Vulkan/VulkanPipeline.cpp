#include <Joepch.h>
#include "VulkanPipeline.h"

namespace Joe {
  VkPipeline VulkanPipeline::Create(PipelineType pipeType){
    VkPipeline pipeline;
    if(pipeType == PipelineType::Rasterisation){
      createRasterisationPipeline();
    }
    return pipeline;
  }
  
  VkPipeline VulkanPipeline::createRasterisationPipeline(){
    VkPipeline pipeline;
    return pipeline;
  }
}
