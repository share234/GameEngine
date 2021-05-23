/*
 * character.cpp
 *
 *  Created on: 22 May 2021
 *      Author: sam
 */

#include "character.h"
#include "draw.h"

updator::updator()
{

}

void updator::update()
{

}

updator::~updator()
{

}


character::character(int ipoint1, int ipoint2, float* pos) {
	point1 = ipoint1;
	point2 = ipoint2;
	board = pos;
	//drawSquare(point1, point2, 30, 15, 0,127,127, pos);
}
character::~character()
{
	this->~updator();
}



void character::update()
{
	drawSquare(point1, point2, 30, 15, 0,127,127, board);
}

void character::move(int x, int y)
{
	point1 += x;
	point2 += y;
}
