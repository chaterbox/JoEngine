#pragma once
#include <vulkan.h>

namespace Joe {
	enum PipelineType{
			Rasterize = 0,
			Raytracing = 1
	};

	class VulkanPipeline{
	public:
		virtual void Create(VkDevice logDevice) = 0;
	private:
	};

	class Rasterize : public VulkanPipeline{
	public:
		virtual void Create(VkDevice logDevice)override;

		VkPipeline GetPipelineHandle() { return pipeline; }
		VkPipelineCache GetPipelineCacheHandle() { return pipelineCache; }
	private:
		VkPipeline pipeline;
		VkPipelineCache pipelineCache;
	};

	class Raytracing : public VulkanPipeline{
	public:
		virtual void Create(VkDevice logDevice)override;
	private:
		VkPipeline pipeline;
		VkPipelineCache pipelineCache;
	};
}
