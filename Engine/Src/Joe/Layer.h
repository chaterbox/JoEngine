#pragma once
#include "Joe/Core.h"
#include "Joe/Events/Event.h"

namespace Joe{
	class JOE_API Layer{
	public:
		Layer(const std::string& name = "layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender(){}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}
