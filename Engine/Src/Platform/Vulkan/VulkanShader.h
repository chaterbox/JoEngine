#pragma once
#include <vulkan.h>
#include "Joe/Renderer/Shader.h"
#include <vector>

namespace Joe{
	class VulkanShader : public Shader{
	public:
		VulkanShader(const std::string vertexSrc, const std::string& fragmentSrc);

		virtual void Bind() const override;
		virtual void Unbind() const override;
	private:
		std::vector<char>ReadFile(const std::string& filename);
		VkShaderModule CreateShader(const std::string& source);

		VkShaderModule FragShaderModule,VertShaderModule;
	};
}
