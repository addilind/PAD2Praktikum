#include "line.h"

Line::Line() : p1(), p2()
{

}

Line::Line(Point a, Point b) : p1(a), p2(b)
{

}

Line::Line(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2)
{

}

void Line::Draw(Frame* target)
{
	if (p2.X < p1.X)
		swapPoints();
	
	Point start = p1;
	Point end = p2;

	bool flipHoriz = false;
	if (end.Y < start.Y)
	{
		start.Y *= -1;
		end.Y *= -1;
		flipHoriz = true;
	}

	bool flipBisec = false;
	if ((end.X - start.X) < (end.Y - start.Y))
	{
		int tmp = start.X;
		start.X = start.Y;
		start.Y = tmp;
		tmp = end.X;
		end.X = end.Y;
		end.Y = tmp;
		flipBisec = true;
	}

	target->SetPoint(start);
	while (start.X < end.X)
	{
		start.X++;
		if ((end.Y - start.Y) * 2 > end.X - start.X)
			start.Y++;
		target->SetPoint(start);
	}
}

void Line::Move(int hor, int ver)
{
	p1.Move(hor, ver);
	p2.Move(hor, ver);
}

void Line::swapPoints()
{
	auto tmp = p1;
	p1 = p2;
	p2 = tmp;
}