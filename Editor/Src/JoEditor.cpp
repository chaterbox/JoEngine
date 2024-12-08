#include <Joe/Core/EntryPoint.h>
#include <Joe/Core/Core.h>
#include "Editor.h"

class JoEditor : public Joe::Application
{
public:
	JoEditor(){
		JOE_EDITOR_INFO("EDITOR::INIT");
		Joe::EditorConfig::Init();
		PushLayer(new Editor());
	}
	~JoEditor()
	{
		JOE_EDITOR_INFO("EDITOR::CLOSED");
	}
};

Joe::Application* Joe::CreateApplication()
{
	return new JoEditor();
}
