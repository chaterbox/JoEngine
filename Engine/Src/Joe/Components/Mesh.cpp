#include <Joepch.h>
#include "Mesh.h"
#include <Joe/Renderer/RHI.h>
#include <Joe/Renderer/Renderer.h>
#include <Platform/RHI/Vulkan/VulkanMesh.h>

namespace Joe {
  Mesh* Mesh::Create(){
    switch (Renderer::GetAPI()) {
      case RHI::BACKEND::None: return nullptr;
      case RHI::BACKEND::SDL3: return nullptr;
      case RHI::BACKEND::Vulkan_WIP: return new VulkanMesh();
    }
  }
}
