/*
 * character.h
 *
 *  Created on: 22 May 2021
 *      Author: sam
 */
#include "box.h"
#ifndef CHARACTER_H_
#define CHARACTER_H_

class character : public box{
public:
	character(int point1, int point2, float* pos);
	 void move(int x, int y);
	virtual ~character();
private:
	int point1;
	int point2;
};



#endif /* CHARACTER_H_ */
