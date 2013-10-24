/******************************

  Beispielprogramm "Quadrat"

*******************************/

#include <stdio.h>
#include <stdlib.h>
//#include <glew.h>
#include <GL/freeglut.h>
   
static void myinit(void)
{   
	printf( "OpenGL renderer:                  |%s|\n", (char*)glGetString( GL_RENDERER));
	printf( "OpenGL driver version:            |%s|\n", (char*)glGetString( GL_VERSION));	

    /* Initializations */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor (1.0, 1.0, 1, 1.0); //Hintergrundfarbe
}


static void RenderScene(void)
{
    /* Creating the Scene */
    glClear(GL_COLOR_BUFFER_BIT);   
    glColor3f(0.0,0.0,0.0);		  /* White Rahmenfarbe*/
    
    glFlush ();		  /* Flushes OpenGL command queues and buffers */
}



static void myReshape(int w, int h)
{
    /* Callback function to handle window dimensions and size changes */

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);	/* specifies the current matrix */
    glLoadIdentity();			/* Sets the currant matrix to identity */
    gluOrtho2D(0.0,1.0,0.0,1.0);	/* Sets the clipping rectangle extends */
}

/*  Main Loop */

int main(int argc, char** argv)
{
    /* GLUT functions to set up the window */
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowPosition (200, 200);
	glutInitWindowSize(500, 300);
	glutInit(&argc, argv);
    glutCreateWindow (argv[0]);
    
    myinit();			/* Initialization */

    glutReshapeFunc (myReshape); /* Function to call when window changes size */
    glutDisplayFunc(RenderScene); /* Creating the Szene */
    glutMainLoop();	
    return 0;
}

