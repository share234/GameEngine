#include<GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>


#include "draw.h"
#include "box.h"

GLFWwindow *init_window(int height, int width, char* pos)
{
	GLFWwindow *window;

	if (glfwInit() == GLFW_FALSE)
	{
		printf("Failed to initialise GLFW\n");
		return NULL;
	}

	window = glfwCreateWindow(width,height,"Hello World!", NULL, NULL);
	if (window == NULL)
	{
		printf("Failed to create window\n");
		glfwTerminate();
		return NULL;
	}


	drawSquare(0,0,height,width,0x00,0x00,0x00,pos);
	return window;
}




int main(void)
{
	int window_width = 640;
	int window_height = 480;
	char window_RGBdata[window_height][window_width][3];
	GLFWwindow* window = NULL;
	if ((window = init_window(window_height, window_width, &window_RGBdata[0][0][0])) == NULL)
	{
		printf("error, closing\n");
		return -1;
	}
	drawSquare(100,200,10,10,0x7f,0x7f,0x7f,&window_RGBdata[0][0][0]);
	drawSquare(200, 200, 30, 50, 0x30, 0x00, 0x00, &window_RGBdata[0][0][0]);

	glRasterPos2i(0,0);
	box test(50,100, 300, 300, &window_RGBdata[0][0][0]);
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawPixels(window_width, window_height, GL_RGB, GL_BYTE, window_RGBdata);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}