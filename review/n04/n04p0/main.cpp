#include <ctime>
#include <cstdlib>
#include <GL/freeglut.h>
void display()
{
    // Clears the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Set drawing color to black
    glColor3f(0.0f, 0.0f, 0.0f);

    // Draw points
    glBegin(GL_POINTS);
    for (int i = 0; i < 1000; i++)
    {
        GLint x = rand() % 100;
        glVertex2i(x, x);
    }
    glEnd();

    glFlush();
}

int main(int argc, char ** argv)
{
    srand((unsigned int) time(NULL));
    glutInit(&argc, argv);
    glutInitWindowPosition(400, 400);
    glutInitWindowSize(1280, 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("HelloWorld!!!");
    
    //-------------------------------------------------------------------------
    // Set the projection as orthographic (parallel) projection.
    // The gluOrtho2D(0,400,0,400) is the same as glOrtho(0,400,0,400,1,-1).
    //-------------------------------------------------------------------------
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Set the GL_PROJECTION matrix to identity. This is
    // actually redundant since the initial value of
    // GL_PROJECTION *is* the identity.
    
    gluOrtho2D(0.0f, 400.0f, 0.0f, 400.0f);
    
    //-------------------------------------------------------------------------
    // Set up model view (the next two statements can be omitted for this
    // example since the default GL_MODELVIEW matrix *is* the identity.
    //-------------------------------------------------------------------------
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}