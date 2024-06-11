#pragma once
#include "Joe/Renderer/RendererAPI.h"

namespace Joe{
	class OpenGLRendererAPI : public RendererAPI{
	public:
		virtual void Clear() override;
		virtual void SetClearColor(const glm::vec4& color) override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};
}
