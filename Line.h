#pragma once
#include "Point.h"
class Line
{
public:
	Line(void);
	~Line(void);
	void set_point(int x, int y);
	void draw(void);
private:
	Point point_from;
	Point point_to;
	short flag;
};

