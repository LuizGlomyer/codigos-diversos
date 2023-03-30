#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void display(void);

int main(int argc, char** argv){
  int width = 700, height = 900;

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


void display(void){
  int width = 700, height = 700;

	glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(3.0f);

  // céu
  glColor3f(0.8,0.8,1);
  glBegin(GL_POLYGON);
		glVertex2f(-width, -height);
		glVertex2f(-width, 7000);
		glVertex2f(width, 7000);
    glVertex2f(width, -height);
	glEnd();

  // mar
  glColor3f(0.2,0.2,1);
  glBegin(GL_POLYGON);
		glVertex2f(-width, -height);
		glVertex2f(-width, 0);
		glVertex2f(width, 0);
    glVertex2f(width, -height);
	glEnd();
  //glTranslatef(0, -200, 1);

	// casco do navio
  glColor3f(0.4,0.2,0.2);
  glBegin(GL_POLYGON);
		glVertex2f(-200, 100);
		glVertex2f(-100, 0);
		glVertex2f(100, 0);
    glVertex2f(200, 100);
	glEnd();
  
  

  // vela esquerda
  glColor3f(0.7,0,1);
  glBegin(GL_POLYGON);
		glVertex2f(0, 100);
		glVertex2f(-100, 100);
		glVertex2f(0, 300);
	glEnd();

  
  glPushMatrix();
  // scale para refletir
  glScalef(-1,1,0);
  // scale para diminuir
  glScalef(0.6,0.6,0);
  glTranslatef(0,65,0);
  
  // vela direita
  glColor3f(0.9,0.9,0.3);
  glBegin(GL_POLYGON);
		glVertex2f(0, 100);
		glVertex2f(-100, 100);
		glVertex2f(0, 300);
	glEnd();
  glPopMatrix();
  

  glPushMatrix();
  // bandeirinha
  glRotatef(-90,0,0,1);
  glScalef(0.4,0.4,0);
  glTranslatef(-600,-100,0);

  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
		glVertex2f(0, 100);
		glVertex2f(-100, 100);
		glVertex2f(0, 300);
	glEnd();

  glPopMatrix();

  // mastro
  glLineWidth(7.0f);
  glColor3f(0.5,0.3,0.);
  glBegin(GL_LINES);
		glVertex2f(0, 100);
		glVertex2f(0, 300);    
	glEnd();


  // ondas
  glPushMatrix();
  int onda1 = -620, onda2 = -670, onda3 = -700;
  for(int i = 0; i < 15; i++){
    glColor3f(0.2,0.2,1);
    glBegin(GL_POLYGON);
      glVertex2f(onda1, 30);
      glVertex2f(onda2, -50);
      glVertex2f(onda3, 0);
    glEnd();

    onda1 += 100;
    onda2 += 100;
    onda3 += 100;
  }


  glPopMatrix();

  glTranslatef(0, -200, 1);
	glEnd();
	glFlush();
}