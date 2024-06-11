#pragma once
#include "Joe/Core.h"
#include "Layer.h"

#include <vector>

namespace Joe{
	class JOE_API LayerStack{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layers);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layers);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_layers.end(); }
	private:
		std::vector<Layer*>m_layers;
		unsigned int m_layersInsertIndex = 0;
	};
}
