#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display(void);

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
    glClearColor(1.0,1.0,1.0,0.0);
    glShadeModel(GL_FLAT);
    glOrtho(0, 700, 0, 700,-1,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	

	glEnd();
	// laranja
	glColor3f(0.7,0.5,0.1);
	glBegin(GL_POLYGON);
		glVertex2f(100, 100);
		glVertex2f(100, 500);
		glVertex2f(600, 500);
		glVertex2f(600, 100);
	glEnd();

	glColor3f(0.3,0.5,0.8);
	glBegin(GL_POLYGON);
		glVertex2f(150, 100);
		glVertex2f(150, 250);
		glVertex2f(250, 250);
		glVertex2f(250, 100);
	glEnd();

	// verde
	glColor3f(0.3,0.5,0.1);
	glBegin(GL_POLYGON);
		glVertex2f(450, 250);
		glVertex2f(550, 250);
		glVertex2f(550, 350);
		glVertex2f(450, 350);
	glEnd();


	// vermelho
	glColor3f(1,0.1,0.1);
	glBegin(GL_POLYGON);
		glVertex2f(100, 500);
		glVertex2f(600, 500);
		glVertex2f(350, 700);
	glEnd();
	

	
	glEnd();
	glFlush();
}