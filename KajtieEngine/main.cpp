#include <iostream>
#include <GLFW/glfw3.h>
struct window
{
	GLFWwindow* window;
	int Width;
	int Height;
	const char* title;
	int close;
};

#include "update.h"
#include "ui.h"

window Window;



void SetupWindow(window* Window, int width, int height, const char* title)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	Window->Height = height;
	Window->Width = width;
	Window->title = title;
	Window->close = 0;
	Window->window = glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), NULL);
}

void initializeEngine(window Window)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_ALPHA_BITS, 8);
	glfwWindowHint(GLFW_DEPTH_BITS, 24);
	glfwWindowHint(GLFW_STENCIL_BITS, 8);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwMakeContextCurrent(Window.window);
	glfwSwapInterval(1);
}

int main()
{
	if (!glfwInit()) 
	{
		std::cout << "GLFW failed to initialize.";
		std::cin.ignore();
		return 0;
	}
	SetupWindow(&Window, 1920, 1080, "Katjie");
	initializeEngine(Window);
	int width = 1080, height = 1080;
	glViewport(0, 0, width, height);
	while (Window.close == 0) 
	{
		if(glfwWindowShouldClose(Window.window))
		{
			Window.close = 1;
		}
		update(Window);
	}
	return 0;
}