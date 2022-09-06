#pragma once

#include <utility>

#include "Events/KeyCodes.h"
#include "Events/MouseCodes.h"

namespace FC
{
	class Input
	{
	public:

		static bool IsKeyPressed(KeyCode keyCode);
		static bool IsMouseButtonPressed(MouseButtonCode button);

		static std::pair<double, double> GetMousePos();
		inline static double GetMouseX() { return GetMousePos().first; }
		inline static double GetMouseY() { return GetMousePos().second; }

	};
}