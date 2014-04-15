#ifndef SHAPE_H
#define SHAPE_H

#include <stdexcept>
#include "frame.h"

class Shape {
public:
	Shape();
	virtual void Draw(Frame* target) = 0;
	virtual void Move(int hor, int ver) = 0;

	static Shape* GetLast();
	Shape* GetPrevious();
private:
	static Shape* last;
	Shape* prev;
};

void plotAllShapes(Frame* target);

#endif