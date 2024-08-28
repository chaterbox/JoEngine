#include "Joepch.h"
#include "VulkanShader.h"
#include "VulkanContext.h"
#include <vulkan/vulkan.h>
#include <shaderc/shaderc.hpp>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

namespace Joe{
  VkShaderModule VulkanShader::Create(const std::string& ShaderPath,const std::string ShaderName,ShaderType shaderType){
                ///////////////////////////////////////////
                //////   COMPILE SHADER TO SPIR-V    //////
                ///////////////////////////////////////////
    bool dev = false;
    if(!std::filesystem::exists("../../../Assets/Shaders/SPIR-V")){
      std::filesystem::create_directory("../../../Assets/Shaders/SPIR-V");
    }
    if(!std::filesystem::exists("../../../Assets/Shaders/SPIR-V/" + ShaderName + ".spv")){
      JOE_CORE_ERROR("VULKAN::SHADER::SPIR-V::NONE-EXIST");

    //TODO: copy shader file to string  
      std::ifstream ShaderFile(ShaderPath);
    
      if(ShaderFile.is_open()){

      }
      JOE_CORE_INFO("VULKAN::SHADER::SPIR-V::{0}::COMPILING",ShaderName);
    }
    else{
      JOE_CORE_INFO("SPIR-V::{0}::FOUND",ShaderName);
    }
                ///////////////////////////////////////////
                //////////   READ SPIR-V file    //////////
                ///////////////////////////////////////////
  
    //TODO: compile shaders into spirv at runtime
    #ifdef JOE_DIST
      std::ifstream shaderSpirVFile("../../Assets/Shaders/SPIR-V/" + ShaderName + ".spv", std::ios::ate | std::ios::binary);
    #else
      std::ifstream shaderSpirVFile("../../../Assets/Shaders/SPIR-V/" + ShaderName + ".spv", std::ios::ate | std::ios::binary);
    #endif
    //check if spirv file found and log type of shader found or not found 
    if(!shaderSpirVFile.is_open()){
        JOE_CORE_FATAL("VULKAN::SHADER::{0}::SPIR-V::LOAD::FAILED",ShaderName);
    }else{
        JOE_CORE_INFO("VULKAN::SHADER::{0}::SPIR-V::LOAD::SUCCESS",ShaderName);
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
        JOE_CORE_FATAL("VULKAN::SHADER::{0}::MODULE::CREATION::FAILED",ShaderName);
    }else{
        JOE_CORE_INFO("VULKAN::SHADER::{0}::MODULE::CREATION::SUCCESS",ShaderName);
    }

    std::cout << "\n";    

    return shader;
  }
}
