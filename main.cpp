#include <stdlib.h>
#include <gl/glut.h>
#include <iostream>
#include "Polygon.h"
#include "Line.h"
#include "Square.h"
#include "Parent.h"

int window_width = 500;
int window_height = 250;

Parent * parent;
Line line;


/* эта функция управляет всем выводом на экран */
void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1,1,1,1);
	line.draw();
	parent->draw();
	glFinish();
}

/* Функция вызывается при изменении размеров окна */
void reshape(GLint w, GLint h){
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
}


void mouse(int button, int state, int ax, int ay){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
		parent->addPoint(ax, window_height - ay);
		display();
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP){
		line.set_point(ax, window_height - ay);
		parent->citio(&line);
		display();
	}
}

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Russian");

	while(true){
		std::cout << "\n\n 1. алгоритм Кируса-Бека \n 2. алгоритм средней точки \n";
		int i;
		std::cin >> i;
		if(i==1){
			parent = new Polygon;
			break;
		}
		if(i==2){
			parent = new Square;
			break;
		}
	}

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