#include "Square.h"
#include <gl/glut.h>

Square::Square(){
	flag = 0;
}

void Square::addPoint(double x, double y){
	if(flag==0){
		left_down.x = x;
		left_down.y = y;
		flag = 1;
	} else {
		right_top.x = x;
		right_top.y = y;
		flag = 0;
	}
}


void Square::draw(){
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 0.25, 0.0); 
		glVertex2d(left_down.x, left_down.y);

		glColor3f(1.0, 0.25, 0.0); 
		glVertex2d(left_down.x, right_top.y);

		glColor3f(1.0, 0.25, 0.0); 
		glVertex2d(right_top.x, right_top.y);

		glColor3f(1.0, 0.25, 0.0); 
		glVertex2d(right_top.x, left_down.y);
	glEnd();
}

void Square::citio(Line line_in){
	// назначить метки обеим концам отрезка
	// если отрезок длиной ноль. возвращаем нуль.
	// тривиально видимый. возвращаем этот отрезок.
	// тривиально невидимый. возвращаем нуль.
	// делим пополам и в рекурсию
}


int Square::reccur_citio(Line line_in){
	// функция "мечения" линии
	return 0;
}