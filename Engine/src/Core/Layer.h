#pragma once

#include "Events/Event.h"

#include <vector>

namespace FC
{
	class Layer
	{
	public:
		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;


		virtual void OnUpdate(double dt) = 0;
		virtual bool OnEvent(const Event& e) = 0;
	};

	class LayerStack
	{
	private:
		std::vector<Layer*> m_Layers;

	public:
		void Shutdown();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void OnUpdate(double dt);
		void OnEvent(const Event& e);

	};
}