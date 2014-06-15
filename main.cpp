#include "GL/glut.h"
#include <stdio.h>
#include <iostream>
#include <locale>

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 300
#define WINDOW_TOP 0
#define WINDOW_LEFT 300
#define WINDOW_TITLE "LB #1"


void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200.0, 200.0, -200.0, 200.0, -5.0, 5.0);
}

void renderLine(){
	glClearColor(0.25, 0, 0.25, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);   /* красный */
		glVertex3f(0.0, 0.0, 0.0); 
		glColor3f(0.0, 0.5, 0.0);   /* красный */
		glVertex3f(1, 1, 0); 
	glEnd();

	glutSwapBuffers();
}

void renderScene(void) {
	glClearColor(0.25, 0, 0.25, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.0,0.5,0.0);
		glVertex3f(0.5,-0.5,0.0);
	glEnd();
 
	glutSwapBuffers();
}

int main(int argc,char** argv)
{
	// инициал
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition (WINDOW_LEFT, WINDOW_TOP);
	init();
	//iniitialize();
	glutCreateWindow (WINDOW_TITLE);
	//glutReshapeFunc (reshape);
	//glutMouseFunc(mouse);
	glutDisplayFunc(renderLine);
	//glutKeyboardFunc(keyboard);

	glutMainLoop();
	//getchar();
	return 0;
}