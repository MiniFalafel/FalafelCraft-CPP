#pragma once

extern FC::Application* FC::CreateApplication();

int main(int argc, char* argv)
{
	FC::Application* app = FC::CreateApplication();

	app->Run();

	delete app;
}
