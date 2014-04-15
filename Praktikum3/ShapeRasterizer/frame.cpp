#include "frame.h"
#include <sstream>

Frame::Frame() : data()
{

}
void Frame::SetPoint(int x, int y, bool set)
{
	if (!OnFrame(x, y))
	{
		std::stringstream ss;
		ss << "Tried to set (" << x << "|" << y << "), which is out of bounds";
		throw std::runtime_error(ss.str());
	}
	data.at(x).at(y) = set;
}
void Frame::SetPoint(Point p, bool set)
{
	SetPoint(p.X, p.Y, set);
}
void Frame::Clear()
{
	for (std::array<std::array<bool, frameHeight>, frameWidth>::iterator col = data.begin();
		col != data.end();
		col++)
	{
		for (std::array<bool, frameHeight>::iterator cell = col->begin();
			cell != col->end();
			cell++)
		{
			*cell = false;
		}
	}
}
void Frame::Print() const
{
	for (std::array<std::array<bool, frameHeight>, frameWidth>::const_iterator col = data.begin();
		col != data.end();
		col++)
	{
		for (std::array<bool, frameHeight>::const_iterator cell = col->begin();
			cell != col->end();
			cell++)
		{
			std::cout << (*cell ? '#' : ' ');
		}
		std::cout << std::endl;
	}
}
bool Frame::OnFrame(int x, int y) const
{
	return x > 0 && y > 0 && x < frameWidth && y < frameHeight;
}