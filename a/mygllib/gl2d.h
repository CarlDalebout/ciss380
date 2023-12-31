// File: gl2d.h

#ifndef GL2D_H
#define GL2D_H

#include <iostream>
#include <cstring>
#include <GL/freeglut.h>
#include "config.h"

namespace mygllib
{
    using namespace mygllib;

    inline
    void init2d_base(unsigned int display_mode, int w = WIN_W, int h = WIN_H)
    {
        int argc = 0;
        char ** argv = NULL;
        glutInit(&argc, argv);
        glutInitWindowPosition(WIN_X, WIN_Y);
        glutInitWindowSize(w, h);
        glutInitDisplayMode(display_mode);
        glutCreateWindow(WIN_TITLE);
        glClearColor(CLEAR_COLOR_R, CLEAR_COLOR_G, CLEAR_COLOR_B,
        CLEAR_COLOR_A);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(MIN_X, w, MIN_Y, h);
        // Set drawing color to black
        glColor3f(0.0f, 0.0f, 0.0f);
    }

    inline
    void init2d()
    {
        init2d_base(GLUT_SINGLE | GLUT_RGBA);
    }

    inline
    void init2d(int w, int h)
    {
        init2d_base((GLUT_SINGLE | GLUT_RGBA), w, h);
    }
    
    inline
    void init2d_double()
    {
        init2d_base(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    }
}
#endif
