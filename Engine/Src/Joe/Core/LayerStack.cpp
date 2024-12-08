#include "Joepch.h"
#include "LayerStack.h"

namespace Joe{
	LayerStack::LayerStack(){}

	LayerStack::~LayerStack(){
		for (Layer* layers : m_layers)
			delete layers;
	}

	void LayerStack::PushLayer(Layer* layers){
		m_layers.emplace(m_layers.begin() + m_layersInsertIndex, layers);
		m_layersInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* overlay){
		m_layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layers){
		auto it = std::find(m_layers.begin(), m_layers.end(), layers);
		if (it != m_layers.end()){
			m_layers.erase(it);
			m_layersInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay){
		auto it = std::find(m_layers.begin(), m_layers.end(), overlay);
		if (it != m_layers.end())
			m_layers.erase(it);
	}
}
