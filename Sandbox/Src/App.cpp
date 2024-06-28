#include <Joe.h>

class ExampleLayer : public Joe::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	virtual void OnImGuiRender() override
	{
	}

	void OnUpdate() override
	{
		if(Joe::Input::IsKeyPressed(KEYS::JOE_KEY_W)){
			JOE_INFO("W key pressed");
		}
	}

	void OnEvent(Joe::Event& event)override
	{

	}
private:
};

class SandBox : public Joe::Application
{
public:
	SandBox()
	{
		JOE_INFO("APP::INIT");
		PushLayer(new ExampleLayer());
	}
	~SandBox()
	{
		JOE_INFO("APP::CLOSED");
	}
};

Joe::Application* Joe::CreateApplication()
{
	return new SandBox();
}
