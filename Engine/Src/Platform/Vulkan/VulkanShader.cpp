#include "Joe/Log.h"
#include "Joepch.h"
#include "VulkanShader.h"
#include "VulkanContext.h"
#include "vulkan_core.h"
#include <cstdint>
#include <fstream>
#include <shaderc/shaderc.h>
#include <sstream>
#include <string>

namespace Joe{
  VkShaderModule VulkanShader::Create(const std::string& ShaderSrc,uint8_t kind){
    std::string ShaderCode;
    std::ifstream ShaderFile(ShaderSrc.c_str());

    if(ShaderFile.is_open()){

    }

    //TODO: compile shaders into spirv at runtime
    if(kind == ShaderType::vert){

    }
    //TODO: create VkShaderModule
    VkShaderModuleCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    //createInfo.codeSize = 0;
    //createInfo.pCode = ;
    createInfo.pNext = nullptr;
    createInfo.flags = 0;

    VkShaderModule shader;
    
    //vkCreateShaderModule(VulkanContext::GetLogicalDeviceHandle(), &createInfo, nullptr, &shader);
    return shader;
  }
}
