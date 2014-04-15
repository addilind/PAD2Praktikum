#include "shape.h"

Shape* Shape::last = 0;

Shape::Shape() : prev(last)
{
	last = this;
}

Shape* Shape::GetLast()
{
	return Shape::last;
}

Shape* Shape::GetPrevious()
{
	return prev;
}

void plotAllShapes(Frame* target)
{
	for (Shape* it = Shape::GetLast();
		it != 0;
		it = it->GetPrevious())
	{
		it->Draw(target);
	}
}