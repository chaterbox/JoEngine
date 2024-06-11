#include "Joepch.h"
#include "VulkanShader.h"
#include "VulkanContext.h"
#include <fstream>

namespace Joe{
	VulkanShader::VulkanShader(const std::string vertexSrc, const std::string& fragmentSrc){
		auto VKvertexSrc = ReadFile("");
		auto VKfragmentSrc = ReadFile("");

		VertShaderModule = CreateShader(vertexSrc);
		FragShaderModule = CreateShader(fragmentSrc);
	}

	void VulkanShader::Bind() const{
	}

	void VulkanShader::Unbind() const{
	}

	std::vector<char> Joe::VulkanShader::ReadFile(const std::string& filename){
		std::ifstream file(filename, std::ios::ate | std::ios::binary);

		if (!file.is_open()){
			JOE_CORE_ERROR("VULKAN: couldnt read spir-v file may not be compiled");
		}

		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}

	VkShaderModule VulkanShader::CreateShader(const std::string& source){
		VkShaderModuleCreateInfo shaderInfo;
		shaderInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		shaderInfo.codeSize = source.size();
		shaderInfo.pCode = reinterpret_cast<const uint32_t*>(source.data());

		VkShaderModule shader;
		if (vkCreateShaderModule(VulkanContext::GetLogicalDeviceHandle(), &shaderInfo, nullptr, &shader) != VK_SUCCESS) {
			JOE_FATAL("VULKAN::SHADER::CREATE::FAILED");
		}

		return shader;
	}
}
