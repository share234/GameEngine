/*
 * character.cpp
 *
 *  Created on: 22 May 2021
 *      Author: sam
 */

#include "character.h"
#include "draw.h"




character::character(int ipoint1, int ipoint2, float* pos) {
	point1 = ipoint1;
	point2 = ipoint2;
	drawSquare(point1, point2, 30, 15, 0,127,127, pos);

}

void character::move(int x, int y)
{
	point1 += x;
	point2 += y;
}
