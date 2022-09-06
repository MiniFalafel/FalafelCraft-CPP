#include "Input.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace FC
{
	bool Input::IsKeyPressed(KeyCode keyCode)
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get()->GetWindow()->GetNativeWindow();
		return glfwGetKey(window, keyCode);
	}
	
	bool Input::IsMouseButtonPressed(MouseButtonCode button)
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get()->GetWindow()->GetNativeWindow();
		return glfwGetMouseButton(window, button);
	}
	
	std::pair<double, double> Input::GetMousePos()
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get()->GetWindow()->GetNativeWindow();
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { xpos, ypos };
	}
}