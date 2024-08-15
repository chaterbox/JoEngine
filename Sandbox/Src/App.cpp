#include <Joe/Core/EntryPoint.h>
#include "Actor.h"

class SandBox : public Joe::Application
{
public:
	SandBox()
	{
		std::cout << "\n";
		JOE_INFO("APP::INIT");
		PushLayer(new Actor());
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
