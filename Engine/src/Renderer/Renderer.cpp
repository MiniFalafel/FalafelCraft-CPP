#include "Core/Core.h"
#include "Renderer.h"

#include <glad/glad.h>

namespace FC
{
	Renderer::Renderer() {}
	Renderer::~Renderer() {}

	void Renderer::Init(ProcAddressGetter getProcAddress)
	{
		// Initialize glad
		int success = gladLoadGLLoader((GLADloadproc)getProcAddress);
		FC_ASSERT(success, "Glad failed to initlaize!");
	}
	
	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}
	
	void Renderer::SetClearColor(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
	}
}
