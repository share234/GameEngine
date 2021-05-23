/*
 * character.h
 *
 *  Created on: 22 May 2021
 *      Author: sam
 */
#ifndef CHARACTER_H_
#define CHARACTER_H_


class updator
{
public:
	updator();
	virtual void update();
	virtual ~updator();
};


class character : public updator{
public:
	character(int point1, int point2, float* pos);
	void move(int x, int y);
	void update();
	virtual ~character();
private:
	float* board;
	int point1;
	int point2;
};



#endif /* CHARACTER_H_ */
