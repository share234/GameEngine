/*
 * keypress.cpp
 *
 *  Created on: 22 May 2021
 *      Author: sam
 */
#include <GLFW/glfw3.h>
#include <stdio.h>


void checkkeyevent(GLFWwindow* window, int* keys)
{
	for (int i = 0; i < 255; i++){
		int state = glfwGetKey(window, i);
		if (state == GLFW_PRESS)
		{
			*(keys+i*1) = 1;
			printf("%i key was pressed\n", i);
		}
	}
}
//https://www.glfw.org/docs/3.3/input_guide.html#input_keyboard
