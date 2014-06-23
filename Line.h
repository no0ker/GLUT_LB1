#pragma once
#include "Point.h"
class Line
{
public:
	Line(void);
	~Line(void);
	void set_point(int x, int y);
	void draw(void);
	Point point_from;
	Point point_to;
	Point cropped_point_from;
	Point cropped_point_to;
private:
	short flag;
};

