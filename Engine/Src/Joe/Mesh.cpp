#include "Mesh.h"
#include "Joe/Renderer/RendererAPI.h"
#include "Renderer/Renderer.h"
#include "Platform/Vulkan/VulkanMesh.h"

namespace Joe {
  Mesh* Mesh::Create(){
    switch (Renderer::GetAPI()) {
      case RendererAPI::API::Vulkan: return new VulkanMesh();
      case RendererAPI::API::None: return nullptr;
    }
  }
}
