#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include "point.h"

class Line : public Shape {
public:
	Line();
	Line(Point p1, Point p2);
	Line(int x1, int y1, int x2, int y2);

	void Draw(Frame* target);
	void Move(int hor, int ver);
private:
	Point p1;
	Point p2;

	void swapPoints();
};

#endif