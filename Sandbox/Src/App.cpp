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
		PushLayer(new ExampleLayer());
	}
	~SandBox()
	{}
};

Joe::Application* Joe::CreateApplication()
{
	return new SandBox();
}
