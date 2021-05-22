/*
 * keypress.cpp
 *
 *  Created on: 22 May 2021
 *      Author: sam
 */
#include <GLFW/glfw3.h>
#include <stdio.h>


void checkkeyevent(GLFWwindow* window, int* keys, int amount)
{

	for (int i = 0; i < amount; i++){
		int state = glfwGetKey(window, *(keys + i));
		if (state == GLFW_PRESS)
		{
			printf("%i key was pressed\n", *(keys + i));
		}
	}
}
