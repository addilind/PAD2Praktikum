#ifndef FRAME_H
#define FRAME_H

#include <stdexcept>
#include <array>
#include <iostream>
#include "point.h"

const int frameWidth = 50;
const int frameHeight = 20;

class Frame {
public:
	Frame();
	void SetPoint(int x, int y, bool set = true);
	void SetPoint(Point p, bool set = true);
	void Clear();
	void Print() const;
	bool OnFrame(int x, int y) const;
private:
	std::array<std::array<bool, frameHeight>, frameWidth> data;
};

#endif