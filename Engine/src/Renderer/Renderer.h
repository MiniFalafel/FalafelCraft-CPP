#pragma once

#include "GLProc.h"

namespace FC
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		static void Init(ProcAddressGetter getProcAddress);

		static void Clear();
		static void SetClearColor(float red, float green, float blue, float alpha);
	};
}
