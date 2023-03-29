#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void display(void);

int main(int argc, char** argv){
  int width = 700, height = 700;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
    glClearColor(1.0,1.0,1.0,0.0);
    glShadeModel(GL_FLAT);
    glOrtho(-width, width, -height, height,-1,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void desenharCirculo(GLint x, GLint y, GLint raio, int num_linhas) {
  float angulo;
  int i = 0;
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
  for(int i = 0; i < num_linhas; i++) {
  angulo = i * 2 * M_PI / num_linhas;
  glVertex2f(x + (cos(angulo) * raio), y + (sin(angulo) * raio));
  }
  glEnd();
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(3.0f);
  desenharCirculo(0, 0, 20, 100);

  
  // amarelo
  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
		glVertex2f(-300, -300);
		glVertex2f(-300, 300);
		glVertex2f(300, 300);
    glVertex2f(300, -300);
	glEnd();
	
  
  glScalef(0.75,0.75,1.0);
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
		glVertex2f(-300, -300);
		glVertex2f(-300, 300);
		glVertex2f(300, 300);
    glVertex2f(300, -300);
	glEnd();

  glScalef(0.75,0.75,1.0);
  glColor3f(0,0,1);
  glBegin(GL_POLYGON);
		glVertex2f(-300, -300);
		glVertex2f(-300, 300);
		glVertex2f(300, 300);
    glVertex2f(300, -300);
	glEnd();
	
 

	
	glEnd();
	glFlush();
}