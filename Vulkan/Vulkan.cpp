#include<GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>


#include "draw.h"
#include "box.h"
#include "keypress.h"
#include "character.h"

GLFWwindow *init_window(int height, int width, float* pos)
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

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("key was %i\n", key);
}


int main(void)
{

	double last_time = glfwGetTime();
	int frameCount = 0;


	int keys[255];
	int window_width = 640;
	int window_height = 480;
	float window_RGBdata[window_height][window_width][3];
	GLFWwindow* window = NULL;
	if ((window = init_window(window_height, window_width, &window_RGBdata[0][0][0])) == NULL)
	{
		printf("error, closing\n");
		return -1;
	}
	drawSquare(100,200,10,10,255,0,255,&window_RGBdata[0][0][0]);
	drawSquare(200, 200, 30, 50, 127, 126, 0, &window_RGBdata[0][0][0]);

	glRasterPos2i(0,0);
	box test(50,100, 300, 300, &window_RGBdata[0][0][0]);
	glfwMakeContextCurrent(window);


	//glfwSetKeyCallback(window, key_callback);

	//testing updateable objects
	updator* update[100];
	int update_amount;
	character uhh(10, 10, &window_RGBdata[0][0][0]);
	update[0] = &uhh;
	update_amount++;

	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		frameCount++;
		// If a second has passed.
		if ( currentTime - last_time >= 1.0 )
		{
		    // Display the frame count here any way you want.
		    printf("%i\n", frameCount);
		    frameCount = 0;
		    last_time = currentTime;
		}

		for(int i = 0; i < update_amount; i++)
		{
			update[i]->update();
		}

		//printf("uh\n");
		glClear(GL_COLOR_BUFFER_BIT);
		//writes the data to the screen
		glDrawPixels(window_width, window_height, GL_RGB, GL_FLOAT, window_RGBdata);
		glfwSwapBuffers(window);
		glfwPollEvents();

		//checks which keys are pressed
		checkkeyevent(window, &keys[0]);
		if (keys[87] == 1)
		{
			uhh.move(0,10);
		}
	}
	glfwTerminate();
	return 0;
}
