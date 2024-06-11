#pragma once
#include "Joe/Input.h"

namespace Joe{
	class GlfwInput : public Input{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button)override;
		virtual std::pair<float, float> GetMousePositionImpl()override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}
