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



	// verde
	glColor3f(0.3,0.8,0.3);
	glBegin(GL_POLYGON);
		glVertex2f(200, 10);
		glVertex2f(500, 10);
		glVertex2f(350, 400);
	glEnd();

  // preto
  glColor3f(0,0,0);
  glLineWidth(3.0f);
  glBegin(GL_LINE_STRIP);
		glVertex2f(350, 400);
		glVertex2f(350, 450);
		glVertex2f(500, 450);
    glVertex2f(500, 450);
    glVertex2f(500, 500);
    glVertex2f(250, 500);
    glVertex2f(250, 550);
    glVertex2f(450, 550);
    glVertex2f(450, 600);
    glVertex2f(300, 600);
    glVertex2f(300, 640);
    glVertex2f(350, 640);
    glVertex2f(350, 680);
	glEnd();
	

	
	glEnd();
	glFlush();
}