#pragma once
#include "Joe/Layer.h"

#include "Joe/Events/ApplicationEvents.h"
#include "Joe/Events/KeyEvent.h"
#include "Joe/Events/MouseEvent.h"

namespace Joe{
	class ImGuiLayer : public Layer{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}
