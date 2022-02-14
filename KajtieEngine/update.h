#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
	void update(window Window)
	{
		
		glfwSwapBuffers(Window.window);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
	}

	bool KeyPressed(int key, window Window) 
	{
		int keyPressed = glfwGetKey(Window.window, key);
		return keyPressed;
	}
