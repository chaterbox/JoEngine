#include "Joepch.h"
#include "VulkanUtils.h"
#include "VulkanPipeline.h"

namespace Joe{
    void Rasterize::Create(VkDevice logDevice){
        VkGraphicsPipelineCreateInfo PipelineCreateInfo = {};
        PipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;

        VkPipelineCacheCreateInfo PipelineCacheCreateInfo = {};

        vkCreatePipelineCache(logDevice, &PipelineCacheCreateInfo, nullptr, &pipelineCache);

        VkPipelineRasterizationStateCreateInfo rasterizionState = {};
        rasterizionState.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;

        VkPipelineColorBlendStateCreateInfo colorBlendState = {};
        colorBlendState.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;

        PipelineCreateInfo.pRasterizationState = &rasterizionState;
        PipelineCreateInfo.pColorBlendState = &colorBlendState;

        if (vkCreateGraphicsPipelines(logDevice, pipelineCache, 2, &PipelineCreateInfo, nullptr, &pipeline) != VK_SUCCESS) {
            JOE_FATAL("VULKAN::PIPELINE::GRAPHICS::CREATE::FAILED");
        }
    }

    void Raytracing::Create(VkDevice logDevice){
    }
}
