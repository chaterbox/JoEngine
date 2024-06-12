#include "Joepch.h"
#include "VertexArray.h"

#include "Renderer.h"

#include "Platform/Opengl/OpenGLVertexArray.h"
#include "Platform/Vulkan/VulkanVertexArray.h"

namespace Joe{
	Joe::VertexArray* VertexArray::Create(){
		switch (Renderer::GetAPI()){
		case RendererAPI::API::None:   JOE_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
		case RendererAPI::API::Vulkan: return new VulkanVertexArray();
		case RendererAPI::API::DX12: return nullptr;
		}
		JOE_CORE_ASSERT(false, "RendererAPI is unknown");
		return nullptr;
	}
}
