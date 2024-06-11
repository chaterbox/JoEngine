#pragma once
#include "Joe/Core.h"

namespace Joe{
	class GraphicsContext{
	public:
		virtual void Init() = 0;
		virtual void Swapbuffers() = 0;
	};
}
