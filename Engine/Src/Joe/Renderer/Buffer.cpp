#include "Joepch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/RHI/Vulkan/VulkanBuffer.h"

namespace Joe
{
	  Joe::VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size){
		        switch (Renderer::GetAPI()){
    case RHI::BACKEND::None: JOE_CORE_ASSERT(false, "RendererAPI::None is currently not suported!");return nullptr;
    case RHI::BACKEND::SDL3: return nullptr;
    case RHI::BACKEND::Vulkan_WIP: return new VulkanVertexBuffer(vertices, size);
		}				  
		JOE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Joe::IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size){
		switch (Renderer::GetAPI()){
		case RHI::BACKEND::None:  JOE_CORE_ASSERT(false,"RendererAPI::None is currently not suported") return nullptr;
    case RHI::BACKEND::SDL3: return nullptr;
    case RHI::BACKEND::Vulkan_WIP: return new VulkanIndexBuffer(indices, size);
		}
		JOE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
