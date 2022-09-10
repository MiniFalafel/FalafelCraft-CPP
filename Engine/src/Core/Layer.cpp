#include "Layer.h"
#include "Core/Core.h"

namespace FC
{
	void LayerStack::Shutdown()
	{
		for (Layer* layer : m_Layers)
		{
			PopLayer(layer);
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace_back(layer);
		layer->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			layer->OnDetach();
			m_Layers.erase(it);
			return;
		}
		FC_ASSERT(false, "Layer not in layerstack");
	}

	void LayerStack::OnUpdate(double dt)
	{
		for (Layer* layer : m_Layers)
			layer->OnUpdate(dt);
	}

	void LayerStack::OnEvent(const Event& e)
	{
		for (Layer* layer : m_Layers)
		{
			// If a layer returns true, the event doesn't make it to other layers.
			if (layer->OnEvent(e))
				return;
		}
	}

}
