#include "Joepch.h"
#include "VulkanBuffer.h"

Joe::VulkanVertexBuffer::VulkanVertexBuffer(float* vertices, uint32_t size){
	VkBufferCreateInfo vertexBufferinfo = {};
	vertexBufferinfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	//vertexBufferinfo.size 
	vertexBufferinfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
	vertexBufferinfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

	/*VkResult res = vkCreateBuffer(m_Device.GetLogicalDeviceHandle(), &vertexBufferinfo, nullptr, &m_VertexBuffer);

	if (res != VK_SUCCESS)
	{
		JOE_CORE_ERROR("failed to create Vertex buffer");
	}
	*/
}

Joe::VulkanVertexBuffer::~VulkanVertexBuffer(){
}

void Joe::VulkanVertexBuffer::Bind() const{
}

void Joe::VulkanVertexBuffer::Unbind() const{
}

Joe::VulkanIndexBuffer::VulkanIndexBuffer(uint32_t* indices, uint32_t size){
}

Joe::VulkanIndexBuffer::~VulkanIndexBuffer(){
}

void Joe::VulkanIndexBuffer::Bind() const{
}

void Joe::VulkanIndexBuffer::Unbind() const{
}
