#include <Joe.h>
#include "imgui/imgui.h"
#include "Joe/Core.h"

class ExampleLayer : public Joe::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f),m_CameraRotation(0.0f)
	{
		m_VertexArray.reset(Joe::VertexArray::Create());
		std::shared_ptr<Joe::VertexBuffer>vertexBuffer;
		//vertexBuffer.reset(Joe::VertexBuffer::Create(vertices, sizeof(vertices)));
		Joe::BufferLayout layout = {
			{Joe::ShaderDataType::Float3, "a_Position" },
			{Joe::ShaderDataType::Float4, "a_Color"}
		};

		//vertexBuffer->SetLayout(layout);
		//m_VertexArray->AddVertexBuffer(vertexBuffers
		std::shared_ptr<Joe::IndexBuffer>indexbuffer;
		//indexbuffer.reset(Joe::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		//m_VertexArray->SetIndexBuffer(indexbuffer);
	}

	void OnUpdate() override
	{
		if (Joe::Input::IsKeyPressed(JOE_KEY_LEFT))
			m_CameraPosition.x -= m_CameraSpeed;

		else if (Joe::Input::IsKeyPressed(JOE_KEY_RIGHT))
			m_CameraPosition.x += m_CameraSpeed;

		if (Joe::Input::IsKeyPressed(JOE_KEY_UP))
			m_CameraPosition.y += m_CameraSpeed;

		else if (Joe::Input::IsKeyPressed(JOE_KEY_DOWN))
			m_CameraPosition.y -= m_CameraSpeed;

		if (Joe::Input::IsKeyPressed(JOE_KEY_A))
			m_CameraRotation -= m_CameraRotationSpeed;

		else if (Joe::Input::IsKeyPressed(JOE_KEY_D))
			m_CameraRotation += m_CameraRotationSpeed;

		//Joe::RenderCommand::SetClearColor({ 0.1f,0.1f,0.1f,1.0f });
		//Joe::RenderCommand::Clear();
    //
		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Joe::Renderer::BeginScene(m_Camera);

		Joe::Renderer::Submit(m_shaderSQ, m_SquareVertexArray);
		Joe::Renderer::Submit(m_shader, m_VertexArray);

		Joe::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
	}

	void OnEvent(Joe::Event& event)override
	{
	}
private:
	std::shared_ptr<Joe::Shader>m_shader;
	std::shared_ptr<Joe::Shader>m_shaderSQ;
	std::shared_ptr<Joe::VertexArray>m_VertexArray;
	std::shared_ptr<Joe::VertexArray>m_SquareVertexArray;

	Joe::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraSpeed = 0.1f;

	float m_CameraRotation;
	float m_CameraRotationSpeed = 1.0f;
};

class SandBox : public Joe::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}
	~SandBox()
	{}
};

Joe::Application* Joe::CreateApplication()
{
	return new SandBox();
}
