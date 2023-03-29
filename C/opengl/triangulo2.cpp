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
    glOrtho(0, width, 0, height,-1,1);
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

  // amarelo
  glColor3f(1,1,0);
  glLineWidth(3.0f);
  glBegin(GL_POLYGON);
		glVertex2f(100, 100);
		glVertex2f(200, 100);
		glVertex2f(150, 200);
	glEnd();
	glTranslatef(200, 200, 0.0);
  glTranslatef(0, -200, 0.0);

  glPushMatrix();
  // verde
  glColor3f(0.3,0.8,0.3);
  glScalef(2,2,1.0);
  glTranslatef(-175, 0, 0.0);
  glBegin(GL_POLYGON);
		glVertex2f(100, 100);
		glVertex2f(200, 100);
		glVertex2f(150, 200);
	glEnd();
  glPopMatrix();

  // azul
  glColor3f(0.2,0.2,1);
  desenharCirculo(-50, 420, 20, 100);
  
 

	
	glEnd();
	glFlush();
}