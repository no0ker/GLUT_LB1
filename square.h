#pragma once
#include "Line.h"

class square{
public:
	void citio(Line line_in);
	void draw();
private:
	int get_byte_mask(Point point_in);
	void recursive_find_points(Line line_in);
	Point left_down;
	Point right_top;
};