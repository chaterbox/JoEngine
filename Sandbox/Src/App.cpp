#include <Joe/Core/EntryPoint.h>
#include "Actor.h"

class SandBox : public Joe::Application
{
public:
	SandBox()
	{
		JOE_CLIENT_INFO("APP::INIT");
		PushLayer(new Actor());
	}
	~SandBox()
	{
		JOE_CLIENT_INFO("APP::CLOSED");
	}
};

Joe::Application* Joe::CreateApplication()
{
	return new SandBox();
}
