#ifndef POINT_H
#define POINT_H

class Point {
public:
	int X;
	int Y;

	Point() : X(0), Y(0) {}
	Point(int x, int y) : X(x), Y(y) {}

	void Move(int hor, int ver) { X += hor; Y += ver; }

	bool operator == (const Point& other) { return X == other.X && Y == other.Y; }
	bool operator != (const Point& other) { return !(*this == other); }
};

#endif