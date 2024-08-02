#pragma once
#include <cstdint>
#include <shaderc/shaderc.h>
#include <vulkan.h>
#include "vulkan_core.h"
#include <vector>
#include <shaderc/shaderc.hpp>

namespace Joe{
  struct ShaderType{
    static const uint8_t frag = 0;
    static const uint8_t vert = 1;
  };
	class VulkanShader{
	public:
		VulkanShader() = default;

    static VkShaderModule Create(const std::string& ShaderSrc,uint8_t kind);
	};
}
