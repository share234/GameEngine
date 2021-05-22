/*
 * box.cpp
 *
 *  Created on: 17 Dec 2020
 *      Author: sam
 */

#include "box.h"
#include "draw.h"
box::box(int iwidth, int iheight, int ipoint1, int ipoint2, char* pos) {
	width = iwidth;
	height = iheight;
	point1 = ipoint1;
	point2 = ipoint2;
	drawSquare(point1, point2, height, width, 0,127,127, pos);
	// TODO Auto-generated constructor stub

}

box::~box() {
	// TODO Auto-generated destructor stub
}

