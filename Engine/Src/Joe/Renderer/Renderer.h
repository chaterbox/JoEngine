#pragma once
#include "RHI.h"

namespace Joe{
	class Renderer{
	public:
		static void BeginScene();
		static void EndScene();
		
		static void Submit();

		inline static RHI::BACKEND GetAPI() { return RHI::GetAPI(); }
	private:
		struct SceneData{
			glm::mat4 ViewProjectionMatrix;
		};
		static SceneData* m_SceneData;
	};
}
