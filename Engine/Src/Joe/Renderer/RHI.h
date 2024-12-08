#pragma once
#include <glm/glm.hpp>

namespace Joe{
	class RHI{
	public:
		enum class BACKEND{
			None = 0, SDL3 = 1,Vulkan_WIP = 2
		};
	public:
		virtual void Clear() = 0;
		virtual void SetClearColor(const glm::vec4& color) = 0;

		virtual void DrawIndexed() = 0;

		inline static BACKEND GetAPI() { return s_BACKEND; }
	private:
		static BACKEND s_BACKEND;
	};
}
