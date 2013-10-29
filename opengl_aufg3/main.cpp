#include <iostream>
#include <GL/freeglut.h>
#include "mouse_func.h"
#include "global.h"
using namespace std;
using namespace Global;

static void initScene()
{
    //Do some initialisation here
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(0,width, 0, height);
    glClear(GL_COLOR_BUFFER_BIT);
    //ctrlpoints.resize(3, std::vector<GLfloat>(10, 0.0)); //resize the 2d vector to 3 cols, 10 rows and default vallue 0.0
    //ctrlpoints[0].fill(0);
}

static void RenderScene()
{
    //Clear the screen
    glClear(GL_COLOR_BUFFER_BIT); //wichtig um Hintergrundfarbe beim ersten aufruf zu setzen
    glColor3f(0.0,0.0,0.0);
    glPointSize(5);
    for(auto it : ctrlpoints)
    {
        glBegin(GL_POINTS);
        glVertex3f(it[0], it[1], it[2]);
        glEnd();
    }
    if(ctrlpoints.size() > 1)
    {
        for(int i = 1; i< ctrlpoints.size(); i++)
        {
            auto start = ctrlpoints.at(i-1);
            auto end = ctrlpoints.at(i);
            glBegin((GL_LINE_STRIP));
            glVertex3f(start.at(0), start.at(1), start.at(2));
            glVertex3f(end.at(0), end.at(1), end.at(2));
            glEnd();
        }
    }

    glutSwapBuffers();

}

int main(int argc, char** argv )
{
    if(debug_mode)
        cout << "running in Debug mode" << endl;
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowPosition (1800, 200);
    glutInitWindowSize(width, height);
    glutInit(&argc, argv);
    glutCreateWindow (argv[0]);
    //set the mouse function
    glutMouseFunc(mouse_func);

//    glutReshapeFunc (myReshape); /* Function to call when window changes size */
    glutDisplayFunc(RenderScene); /* Creating the Szene */
    initScene();


    glutMainLoop();
    return 0;
}

