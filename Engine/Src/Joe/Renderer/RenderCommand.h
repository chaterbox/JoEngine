#pragma once
#include "RendererAPI.h"

namespace Joe{
	class RenderCommand{
	public:
		static inline void Clear(){
			s_RendererAPI->Clear();
		}

		static inline void SetClearColor(const glm::vec4& color){
			s_RendererAPI->SetClearColor(color);
		}

		static inline void DrawIndexed(){
			s_RendererAPI->DrawIndexed();
		}
	private:
		static RendererAPI* s_RendererAPI;
	};
}
