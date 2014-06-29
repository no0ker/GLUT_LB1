#include <gl/glut.h>
#include <stdlib.h>
#include <iostream>
#include "Polygon.h"
#include "Line.h"
#include "Square.h"

int window_width = 500;
int window_height = 250;

Polygon polygon;
Square square;
Line line;

int tmp = 0;


/* эта функция управляет всем выводом на экран */
void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1,1,1,1);
	
	line.draw();
	polygon.draw();
	square.draw();
	//glFinish();
	
	
	/*
	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0); 	
		glVertex2d(0, 0);
		glVertex2d(50, 50);
	glEnd();*/
	glFinish();
}

/* Функция вызывается при изменении размеров окна */
void reshape(GLint w, GLint h)
{
	window_width = w;
	window_height = h;

    /* устанавливаем размеры области отображения */
    glViewport(0, 0, w, h);

    /* ортографическая проекция */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(1,1,1,1);
}


void mouse(int button, int state, int ax, int ay){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
		//polygon.addPoint(ax, window_height - ay);
		square.addPoint(ax, window_height - ay);
		display();
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP){
		line.set_point(ax, window_height - ay);
		//polygon.CB(&line);
		square.citio(&line);
		display();
	}
}

/* Главный цикл приложения */
int main(int argc, char *argv[]){
    
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(100,100);
	
	glutCreateWindow("LB #1");

    glutDisplayFunc(display);
	glutMouseFunc(mouse);
    glutReshapeFunc(reshape);

    glutMainLoop();
	
	return 0;
}