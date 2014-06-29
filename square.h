#pragma once
#include "Line.h"

class Square{
public:
	Square(void);
	//void citio(Line line_in);
	void addPoint(double x, double y);
	void draw();
	void citio(Line * line_in);
private:
	//int get_byte_mask(Point point_in);
	//void recursive_find_points(Line line_in);
	Point left_down;
	Point right_top;
	short flag;
	int reccur_citio(Line * line_in);
	void add_flag_to_point(Line * line_in);
};