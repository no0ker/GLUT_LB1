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

void Square::citio(Line * line_in){
	reccur_citio(line_in);
}


int Square::reccur_citio(Line * line_in){
	// функция "мечения" линии
	add_flag_to_point(line_in);
	// назначить метки обеим концам отрезка
	// если отрезок длиной ноль. возвращаем нуль.
	// тривиально видимый. возвращаем этот отрезок.
	if(line_in->flag_from == 0 && line_in->flag_to == 0){
		line_in->cropped_point_from = line_in->point_from;
		line_in->cropped_point_to = line_in->point_to;
	}
	// тривиально невидимый. возвращаем нуль.
	// делим пополам и в рекурсию
	return 0;
}

void Square::add_flag_to_point(Line * line_in){
	int x_min = left_down.x;
	int x_max = right_top.x;
	int y_min = left_down.y;
	int y_max = right_top.y;

	if(line_in->point_from.x >= x_min)
		line_in->flag_from &= ~(1<<3);
	else
		line_in->flag_from |= (1<<3);


	if(line_in->point_from.x <= x_max)
		line_in->flag_from &= ~(1<<2);
	else
		line_in->flag_from |= (1<<2);


	if(line_in->point_from.y >= y_min)
		line_in->flag_from &= ~(1<<1);
	else
		line_in->flag_from |= (1<<1);


	if(line_in->point_from.y <= y_max)
		line_in->flag_from &= ~(1<<0);
	else
		line_in->flag_from |= (1<<0);



	if(line_in->point_to.x >= x_min)
		line_in->flag_to &= ~(1<<3);
	else
		line_in->flag_to |= (1<<3);


	if(line_in->point_to.x <= x_max)
		line_in->flag_to &= ~(1<<2);
	else
		line_in->flag_to |= (1<<2);


	if(line_in->point_to.y >= y_min)
		line_in->flag_to &= ~(1<<1);
	else
		line_in->flag_to |= (1<<1);


	if(line_in->point_to.y <= y_max)
		line_in->flag_to &= ~(1<<0);
	else
		line_in->flag_to |= (1<<0);

}