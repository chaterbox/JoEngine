#pragma once
#include "Joe/Renderer/Buffer.h"
#include <vulkan.h>

namespace Joe{
	class VulkanVertexBuffer : public VertexBuffer{
	public:
		VulkanVertexBuffer(float* vertices, uint32_t size);
		virtual ~VulkanVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;

		VkBuffer m_VertexBuffer;
	};

	class VulkanIndexBuffer : public IndexBuffer{
	public:
		VulkanIndexBuffer(uint32_t* indices, uint32_t size);
		virtual ~VulkanIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual uint32_t GetCount() const { return m_Count; };
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;

		VkBuffer m_IndexBuffer;
		VkDevice m_LogDevice;
	};
}
