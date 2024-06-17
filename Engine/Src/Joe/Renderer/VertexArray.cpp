#include "Joepch.h"
#include "VertexArray.h"

#include "Renderer.h"

namespace Joe{
	Joe::VertexArray* VertexArray::Create(){
		switch (Renderer::GetAPI()){
		case RendererAPI::API::None:   JOE_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::API::Vulkan: return nullptr;
		}
		JOE_CORE_ASSERT(false, "RendererAPI is unknown");
		return nullptr;
	}
}
