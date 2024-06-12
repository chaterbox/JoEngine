#include "Joepch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/Opengl/OpenGLShader.h"
#include "Platform/Vulkan/VulkanShader.h"

namespace Joe{
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc){
		switch(Renderer::GetAPI()){
		case RendererAPI::API::None: JOE_CORE_ASSERT(false, "RendererAPI::None is currently not support");
		case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSrc, fragmentSrc);
		case RendererAPI::API::Vulkan: return new VulkanShader(vertexSrc, fragmentSrc);
		case RendererAPI::API::DX12: return nullptr;
		}
		JOE_CORE_ASSERT(false, "RendererAPI is unknown");
		return nullptr;
	}
}
