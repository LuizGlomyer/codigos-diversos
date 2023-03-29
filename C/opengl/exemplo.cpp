#include<GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
  glColor3f(1, 1, 1);
  glutWireCube(2);
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("OpenGL 3D Scene");
  glutDisplayFunc(display);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  return 0;
}