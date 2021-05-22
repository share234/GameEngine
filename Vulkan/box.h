/*
 * box.h
 *
 *  Created on: 17 Dec 2020
 *      Author: sam
 */

#ifndef BOX_H_
#define BOX_H_

class box {
public:
	box(int width, int height, int point1, int point2, char* pos);
	virtual ~box();
private:
	int width;
	int height;
	int point1;
	int point2;
};

#endif /* BOX_H_ */
