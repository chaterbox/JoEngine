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
  VkShaderModule VulkanShader::Create(const std::string& ShaderPath,ShaderType shaderType){
                ///////////////////////////////////////////
                //////    FOLDER AND SPIR-V CHECK    //////
                ///////////////////////////////////////////
    //check if folders exist if not create them
    if(!std::filesystem::exists("../../../Assets"))
        std::filesystem::create_directory("../../../Assets");
    if(!std::filesystem::exists("../../../Assets/Shaders"))
        std::filesystem::create_directory("../../../Assets/Shaders");
    if(!std::filesystem::exists("../../../Assets/Shaders/SPIR-V"))
        std::filesystem::create_directory("../../../Assets/Shaders/SPIR-V");
    
    //get shader file name from path
    std::string ShaderName = ShaderPath;
    //delete begining of the path
    std::size_t beginStringToDelete = ShaderName.find_last_of("/");
    ShaderName.erase(0,beginStringToDelete + 1);
    //delete file extension
    std::size_t lastStringToDelete = ShaderName.find_last_of(".");
    ShaderName.erase(lastStringToDelete,ShaderName.length() - lastStringToDelete);

    //check if spirv bin exist else compile one
    if(!std::filesystem::exists("../../../Assets/Shaders/SPIR-V/" + ShaderName + ".spv")){
      JOE_CORE_ERROR("VULKAN::SHADER::SPIR-V::{0}.spv::NON_EXIST",ShaderName);

                ///////////////////////////////////////////
                //////   COMPILE SHADER TO SPIR-V    //////
                ///////////////////////////////////////////
      //copy shader to string
      std::ifstream ShaderFile(ShaderPath);
    
      if(!ShaderFile.is_open()){
        JOE_CORE_ERROR("GLSL::FILE::NOT_EXIST");
      }
      
      std::stringstream ss{};
      ss << ShaderFile.rdbuf();
      ShaderFile.close();
    
      JOE_CORE_INFO("VULKAN::SHADER::SPIR-V::{0}::COMPILING::STARTING",ShaderName);
      
      //compiling shader
      shaderc::Compiler compiler;
      shaderc::CompileOptions options;
      options.SetTargetEnvironment(shaderc_target_env_vulkan, shaderc_env_version_vulkan_1_2);
      options.SetOptimizationLevel(shaderc_optimization_level_performance);
      
      shaderc::SpvCompilationResult module;
      if(shaderType == ShaderType::Vert)
        module = compiler.CompileGlslToSpv(ss.str(),shaderc_vertex_shader,"../../../Assets/Shaders/SPIR-V/",options);
      if(shaderType == ShaderType::Frag)
        module = compiler.CompileGlslToSpv(ss.str(),shaderc_fragment_shader,"../../../Assets/Shaders/SPIR-V/",options);

      if(module.GetCompilationStatus() != shaderc_compilation_status_success)
        JOE_CORE_ERROR("VULKAN::SHADER::SPIR-V::{0}::COMPILING::FAILED",ShaderName);
      else
        JOE_CORE_INFO("VULKAN::SHADER::SPIR-V::{0}::COMPILING::SUCCESS",ShaderName);

      auto Sdata = std::vector<uint32_t>(module.cbegin(),module.cend());

                ///////////////////////////////////////////
                //////////   WRITE SPIR-V file   //////////
                ///////////////////////////////////////////

      std::ofstream out("../../../Assets/Shaders/SPIR-V/" + ShaderName + ".spv",std::ios::out | std::ios::binary);
      if(out.is_open()){
        auto data = Sdata;
        out.write((char*)data.data(), data.size() * sizeof(uint32_t));
        out.flush();
        out.close();
      }
    }
    else{
      JOE_CORE_INFO("SPIR-V::{0}::FOUND",ShaderName);
    }
                ///////////////////////////////////////////
                //////////   READ SPIR-V file    //////////
                ///////////////////////////////////////////
  
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
