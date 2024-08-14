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
    std::string ShaderCode;
    std::ifstream ShaderFile(ShaderSrc.c_str());

    if(ShaderFile.is_open()){

    }

    //TODO: compile shaders into spirv at runtime
    if(shaderType == ShaderType::Vert){
      std::ifstream vfile("../../../Assets/Shaders/Vulkan/triVert.spv", std::ios::ate | std::ios::binary);

      if(!vfile.is_open()){
        JOE_CORE_FATAL("VULKAN::VERTEX::SHADER::LOAD::FAILED!");
      }else{
        JOE_CORE_INFO("VULKAN::VERTEX::SHADER::LOAD::SUCCESS!");
      }

      size_t fileSize = (size_t) vfile.tellg();
      std::vector<char> buffer(fileSize);
      vfile.seekg(0);
      vfile.read(buffer.data(),fileSize);
      vfile.close();
  
      auto shadercode = buffer;  
      
    
      VkShaderModuleCreateInfo createInfo = {};
      createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
      createInfo.codeSize = shadercode.size();
      createInfo.pCode = reinterpret_cast<const uint32_t*>(shadercode.data());
      createInfo.pNext = nullptr;
      createInfo.flags = 0;
      
      VkShaderModule shader;
    
      if(vkCreateShaderModule(VulkanContext::GetLogicalDeviceHandle(), &createInfo, nullptr, &shader) != VK_SUCCESS){
        JOE_CORE_FATAL("VULKAN::SHADER::MODULE::CREATION::FAILED");
      }else{
        JOE_CORE_INFO("VULKAN::SHADER::MODULE::CREATION::SUCCESS");
      }
      
      return shader;
    }
    if(shaderType == ShaderType::Frag){
       
      std::ifstream vfile("../../../Assets/Shaders/Vulkan/trifrag.spv", std::ios::ate | std::ios::binary);

      if(!vfile.is_open()){
        JOE_CORE_FATAL("VULKAN::FRAGMENT::SHADER::LOAD::FAILED!");
      }else{
        JOE_CORE_INFO("VULKAN::FRAGMENT::SHADER::LOAD::SUCCESS!");
      }

      size_t fileSize = (size_t) vfile.tellg();
      std::vector<char> buffer(fileSize);
      vfile.seekg(0);
      vfile.read(buffer.data(),fileSize);
      vfile.close();
  
      auto shadercode = buffer;  
      
    
      VkShaderModuleCreateInfo createInfo = {};
      createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
      createInfo.codeSize = shadercode.size();
      createInfo.pCode = reinterpret_cast<const uint32_t*>(shadercode.data());
      createInfo.pNext = nullptr;
      createInfo.flags = 0;
      
      VkShaderModule shader;
    
      if(vkCreateShaderModule(VulkanContext::GetLogicalDeviceHandle(), &createInfo, nullptr, &shader) != VK_SUCCESS){
        JOE_CORE_FATAL("VULKAN::SHADER::MODULE::CREATION::FAILED");
      }else{
        JOE_CORE_INFO("VULKAN::SHADER::MODULE::CREATION::SUCCESS");
      }
      
      return shader;
    }

    else{
      return nullptr;
    }
  }
}
