#include "Joepch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/Opengl/OpenGLBuffer.h"
#include "Platform/Vulkan/VulkanBuffer.h"

namespace Joe
{
	  Joe::VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size){
		        switch (Renderer::GetAPI()){
		case RendererAPI::API::None: JOE_CORE_ASSERT(false, "RendererAPI::None is currently not suported!");return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		case RendererAPI::API::Vulkan: return new VulkanVertexBuffer(vertices, size);
			break;
		default:
			break;
		}				  
		JOE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Joe::IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size){
		switch (Renderer::GetAPI()){
		case RendererAPI::API::None:  JOE_CORE_ASSERT(false,"RendererAPI::None is currently not suported") return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, size);
		case RendererAPI::API::Vulkan: return new VulkanIndexBuffer(indices, size);
			break;
		default:
			break;
		}
		JOE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
