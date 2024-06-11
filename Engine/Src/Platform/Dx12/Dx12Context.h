#pragma once
#include "Joe/Renderer/GraphicsContext.h"

namespace Joe{
	class Dx12Context : public GraphicsContext{
	public:
		Dx12Context();
		void Init() override;
		void Swapbuffers()override;
	};
}
