#pragma once
#include <cstdint>
#include <vulkan/vulkan.h>
#include <vector>
#include <shaderc/shaderc.hpp>

namespace Joe{
    enum class ShaderType{
      AnyHitRTX,
      ClosestHitRTX,
      Compute,    
      Frag,
      Geometry,
      IntersectionRTX,
      MissRTX,
      RayGenRTX,
      TessellationControl,
      TessellationEvaluation,
      Vert
    };

	class VulkanShader{
	public:
      VulkanShader() = default;

      static VkShaderModule Create(const std::string& ShaderPath,const std::string ShaderName,ShaderType shaderType);
	};
}
