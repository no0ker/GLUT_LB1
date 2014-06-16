#include "Polygon.h"
#include <gl/glut.h>



Polygon::Polygon(void)
{
}

Polygon::~Polygon(void)
{
	std::vector<Point>::iterator i;
	for(i=points.begin(); i<points.end(); ++i)
		delete &(*i);
}

void Polygon::addPoint(double x, double y){
	Point* tmp = new Point;
	tmp->x = x;
	tmp->y = y;
	points.push_back(*tmp);
}

void Polygon::draw(void){
	
	glBegin(GL_LINE_LOOP);
		std::vector<Point>::iterator i;
		for(i = points.begin(); i<points.end(); ++i){
			glColor3f(1.0, 0.25, 0.0); 
			glVertex2d(i->x, i->y);
		}
	glEnd();
}