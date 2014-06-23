#pragma once
#include <vector>
#include "Point.h"
#include "Line.h"

class Polygon
{
public:
	Polygon(void);
	~Polygon(void);
	void addPoint(double x, double y);
	void draw(void);
	void citio(Line line_in);
	int Polygon::CB(Line* line_in);
	std::vector<Point> points;
	std::vector<Point> points_normal;
	//Line clip_line;
	
private:
	bool lines_is_right;
	void add_Normals(void);
	bool is_Convex(void);
};

