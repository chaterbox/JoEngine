#pragma once
#include "Shader.h"
#include "RendererAPI.h"

namespace Joe{
	class Renderer{
	public:
		static void BeginScene();
		static void EndScene();
		
		static void Submit();

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData{
			glm::mat4 ViewProjectionMatrix;
		};
		static SceneData* m_SceneData;
	};
}
