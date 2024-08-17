#include "Joe/Core/Log.h"
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
  VkShaderModule VulkanShader::Create(const std::string& ShaderSrc,ShaderType shaderType){
    //TODO: copy shader file to string  
    std::ifstream ShaderFile(ShaderSrc);

    if(ShaderFile.is_open()){

    }

    //TODO: compile shaders into spirv at runtime
    std::string spirvSrc = ShaderSrc;
    //delete begining shader location
    spirvSrc.erase(0,44);
    //delete file extension
    spirvSrc.erase(spirvSrc.size() - 5, 5);

    std::ifstream shaderSpirVFile("../../../Assets/Shaders/SPIR-V/" + spirvSrc + ".spv", std::ios::ate | std::ios::binary);

    if(!shaderSpirVFile.is_open()){
      if(shaderType == ShaderType::Vert)
        JOE_CORE_FATAL("VULKAN::SHADER::VERTEX::SPIR-V::LOAD::FAILED");
      if(shaderType == ShaderType::Frag)
        JOE_CORE_FATAL("VULKAN::SHADER::FRAGMENT::SPIR-V::LOAD::FAILED") ;
    }else{
      if(shaderType == ShaderType::Vert)
        JOE_CORE_INFO("VULKAN::SHADER::VERTEX::SPIR-V::LOAD::SUCCESS");
      if(shaderType == ShaderType::Frag)
        JOE_CORE_INFO("VULKAN::SHADER::FRAGMENT::SPIR-V::LOAD::SUCCESS");
    }

    size_t fileSize = (size_t) shaderSpirVFile.tellg();
    std::vector<char> buffer(fileSize);
    shaderSpirVFile.seekg(0);
    shaderSpirVFile.read(buffer.data(),fileSize);
    shaderSpirVFile.close();
  
    auto shadercode = buffer;  
         
    VkShaderModuleCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = shadercode.size();
    createInfo.pCode = reinterpret_cast<const uint32_t*>(shadercode.data());
    createInfo.pNext = nullptr;
    createInfo.flags = 0;
      
    VkShaderModule shader;
    
    if(vkCreateShaderModule(VulkanContext::GetLogicalDeviceHandle(), &createInfo, nullptr, &shader) != VK_SUCCESS){
      if(shaderType == ShaderType::Vert)
        JOE_CORE_FATAL("VULKAN::SHADER::VERTEX::MODULE::CREATION::FAILED");
      if(shaderType == ShaderType::Frag)
        JOE_CORE_FATAL("VULKAN::SHADER::FRAGMENT::MODULE::CREATION::FAILED");
    }else{
      if(shaderType == ShaderType::Vert)
        JOE_CORE_INFO("VULKAN::SHADER::VERTEX::MODULE::CREATION::SUCCESS");
      if(shaderType == ShaderType::Frag)
        JOE_CORE_INFO("VULKAN::SHADER::FRAGMENT::MODULE::CREATION::SUCCESS");
    }
      
    return shader;
  }
}
