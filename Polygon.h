#pragma once
#include <vector>
#include "Point.h"

class Polygon
{
public:
	Polygon(void);
	~Polygon(void);
	void addPoint(double x, double y);
	void draw(void);

private:
	std::vector<Point> points;
};

