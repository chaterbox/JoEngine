#pragma once
#include <cstdint>
#include <shaderc/shaderc.h>
#include <vulkan.h>
#include "vulkan_core.h"
#include <vector>
#include <shaderc/shaderc.hpp>

namespace Joe{
    enum class ShaderType{
      Frag,
      Vert
    };

	class VulkanShader{
	public:
      VulkanShader() = default;

      static VkShaderModule Create(const std::string& ShaderSrc,ShaderType shaderType);
	};
}
