#pragma once
#include "RHI.h"

namespace Joe{
	class RenderCommand{
	public:
		static inline void Clear(){
			s_RHI->Clear();
		}

		static inline void SetClearColor(const glm::vec4& color){
			s_RHI->SetClearColor(color);
		}

		static inline void DrawIndexed(){
			s_RHI->DrawIndexed();
		}
	private:
		static RHI* s_RHI;
	};
}
