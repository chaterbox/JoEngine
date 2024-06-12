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

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.9f,0.0f,0.0f,1.0f,
			 0.5f, -0.5f, 0.0f, 0.0f,0.9f,0.0f,1.0f,
			 0.0f,  0.5f, 0.0f, 0.0f,0.0f,0.9f,1.0f
		};
		std::shared_ptr<Joe::VertexBuffer>vertexBuffer;
		vertexBuffer.reset(Joe::VertexBuffer::Create(vertices, sizeof(vertices)));
		Joe::BufferLayout layout = {
			{Joe::ShaderDataType::Float3, "a_Position" },
			{Joe::ShaderDataType::Float4, "a_Color"}
		};

		if (Joe::RendererAPI::GetAPI() == Joe::RendererAPI::API::OpenGL)
		{
			vertexBuffer->SetLayout(layout);
			m_VertexArray->AddVertexBuffer(vertexBuffer);
		}

		unsigned int indices[3] = {
			0,1,2
		};
		std::shared_ptr<Joe::IndexBuffer>indexbuffer;
		if (Joe::RendererAPI::GetAPI() == Joe::RendererAPI::API::OpenGL)
		{
			indexbuffer.reset(Joe::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
			m_VertexArray->SetIndexBuffer(indexbuffer);
		}

		m_SquareVertexArray.reset(Joe::VertexArray::Create());

		float SQvertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		std::shared_ptr<Joe::VertexBuffer> squareVB;
		squareVB.reset(Joe::VertexBuffer::Create(SQvertices, sizeof(SQvertices)));

		if (Joe::RendererAPI::GetAPI() == Joe::RendererAPI::API::OpenGL)
		{
			squareVB->SetLayout({ {Joe::ShaderDataType::Float3, "a_Position" } });
			m_SquareVertexArray->AddVertexBuffer(squareVB);
		}

		unsigned int SQindices[6] = {
			0,1,2,2,3,0
		};
		std::shared_ptr<Joe::IndexBuffer> SQIndexBuffer;
		if (Joe::RendererAPI::GetAPI() == Joe::RendererAPI::API::OpenGL)
		{
			SQIndexBuffer.reset(Joe::IndexBuffer::Create(SQindices, sizeof(SQindices) / sizeof(uint32_t)));
			m_SquareVertexArray->SetIndexBuffer(SQIndexBuffer);
		}

		std::string vertexSrc = R"(
		#version 330 core

		layout(location = 0) in vec3 a_Position;
		layout(location = 1) in vec4 a_Color;

		uniform mat4 u_ViewProjection;

		out vec3 v_Position;
		out vec4 v_Color;

		void main()
		{
			v_Position = a_Position;
			v_Color = a_Color;
			gl_Position = u_ViewProjection * vec4(a_Position,1.0);
		}
		)";

		std::string fragmentSrc = R"(
		#version 330 core

		layout(location = 0) out vec4 a_Color;

		in vec3 v_Position;
		in vec4 v_Color;

		void main()
		{
			a_Color = vec4(v_Position * 0.5 + 0.5,1.0);
			a_Color = v_Color;
		}
		)";
		if (Joe::RendererAPI::GetAPI() == Joe::RendererAPI::API::OpenGL) {
			m_shader.reset(Joe::Shader::Create(vertexSrc, fragmentSrc));
		}
		
		std::string vertexSrcSQ = R"(
		#version 330 core

		layout(location = 0) in vec3 a_Position;

		uniform mat4 u_ViewProjection;

		out vec3 v_Position;

		void main()
		{
			v_Position = a_Position;
			gl_Position = u_ViewProjection * vec4(a_Position,1.0);
		}
		)";

		std::string fragmentSrcSQ = R"(
		#version 330 core

		layout(location = 0) out vec4 a_Color;

		in vec3 v_Position;

		void main()
		{
			a_Color = vec4(0.2,0.3,0.8,1.0);
		}
		)";
		if (Joe::RendererAPI::GetAPI() == Joe::RendererAPI::API::OpenGL) {
			m_shaderSQ.reset(Joe::Shader::Create(vertexSrcSQ, fragmentSrcSQ));
		}
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

		if (Joe::RendererAPI::GetAPI() == Joe::RendererAPI::API::OpenGL)
		{
			Joe::RenderCommand::SetClearColor({ 0.1f,0.1f,0.1f,1.0f });
			Joe::RenderCommand::Clear();
		}

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
