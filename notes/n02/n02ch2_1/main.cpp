#include <GL/freeglut.h>
void display()
{}
int main(int argc, char ** argv)
{
glutInit(&argc, argv);
glutInitWindowPosition(500, 400);
glutInitWindowSize(800, 500);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);    
glutCreateWindow("OpenGL!!!");
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
