/*
 * draw.cpp
 *
 *  Created on: 17 Dec 2020
 *      Author: sam
 */




void drawSquare(int h, int w,int sh, int sw, char r, char g, char b, char *pos)
{
	// max you can use for colour is 255 or 0x7f as anything over this goes into the depths of fucking nowhere
	char *temp;
	for(int i = 0; i < sh; i++)
	{
		for (int j = 0; j < sw; j++)
		{
			temp = pos + (((w + j) + (h + i) * 640) * 3);
			*temp = r;
			*(temp + 1) = g;
			*(temp + 2) = b;
		}
	}
}
