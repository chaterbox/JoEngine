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
  VkShaderModule VulkanShader::Create(const std::string& ShaderPath,const std::string ShaderName,ShaderType shaderType){
                ///////////////////////////////////////////
                //////   COMPILE SHADER TO SPIR-V    //////
                ///////////////////////////////////////////

    //TODO: copy shader file to string  
    std::ifstream ShaderFile(ShaderPath);

    if(ShaderFile.is_open()){

    }

                ///////////////////////////////////////////
                //////////   READ SPIR-V file    //////////
                ///////////////////////////////////////////

    //TODO: compile shaders into spirv at runtime
    std::ifstream shaderSpirVFile("../../../Assets/Shaders/SPIR-V/" + ShaderName + ".spv", std::ios::ate | std::ios::binary);
    //check if spirv file found and log type of shader found or not found 
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

    //get filesize
    size_t fileSize = (size_t) shaderSpirVFile.tellg();
    std::vector<char> SpirvCode(fileSize);
    shaderSpirVFile.seekg(0);
    //read and copy file to vector to be passed to shadermodule create info struct
    shaderSpirVFile.read(SpirvCode.data(),fileSize);
    shaderSpirVFile.close();

                ///////////////////////////////////////////
                ////////   CREATE SHADER MODULE    ////////
                ///////////////////////////////////////////
    
    //createInfo struct
    VkShaderModuleCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = SpirvCode.size();
    createInfo.pCode = reinterpret_cast<const uint32_t*>(SpirvCode.data());
    createInfo.pNext = nullptr;
    createInfo.flags = 0;
      
    VkShaderModule shader;
    
    //create shader module
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
