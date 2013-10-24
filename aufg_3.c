/******************************

  Beispielprogramm "Quadrat"

*******************************/

#include <stdio.h>
#include <stdlib.h>
//#include <glew.h>
#include <GL/freeglut.h>
#include <math.h>

int _x=0;

int _y=0;
int x_old=0;
int y_old=0;
void draw_circle(float radius)
{

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(_x, _y, 0.0);
	glCallList(1);
	glPopMatrix();
}

void timer(int value)
{
	printf("value: %d\n", value);
	if(value < 50)
	{
		_x = x_old*0.1;
		_y= y_old*0.1;
		glutPostRedisplay();
		glutTimerFunc(200, timer, ++value);

	}
}
void mouse(int button, int state, int x, int y)
{
	switch(button)
	{
		case(GLUT_LEFT_BUTTON):
		if(state == GLUT_DOWN)
		{
			printf("left button: x= %d, y= %d\n", x, y);
			x_old = _x;
			y_old = _y;
			_x = x;
			_y = 500 - y;
			timer(0);
			//glutPostRedisplay();
		}
	}
}


static void myinit(void)
{   
	printf( "OpenGL renderer:                  |%s|\n", (char*)glGetString( GL_RENDERER));
	printf( "OpenGL driver version:            |%s|\n", (char*)glGetString( GL_VERSION));	

	float pi = 3.14159;
	int radius = 10;
    /* Initializations */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor (1.0, 1.0, 1, 1.0); //Hintergrundfarbe
    glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, 1.0);
    glNewList(1, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	for(int i=0; i< 360; i++)
	{
		float tmp = i*(pi/180);
		glVertex2f(cos(tmp)*radius, sin(tmp)*radius);
	}
	glEnd();
    glEndList();
}


static void RenderScene(void)
{
    /* Creating the Scene */
    glClear(GL_COLOR_BUFFER_BIT);   
    //glColor3f(0.0,0.9,0.9);		  /* White Rahmenfarbe*/
    draw_circle(50);  
    glFlush ();		  /* Flushes OpenGL command queues and buffers */
}



static void myReshape(int w, int h)
{
    /* Callback function to handle window dimensions and size changes */

    //glViewport(0, 0, w, h);
    //glMatrixMode(GL_PROJECTION);	/* specifies the current matrix */
    //glLoadIdentity();			/* Sets the currant matrix to identity */
//    gluOrtho2D(0.0,5.0,0.0,5.0);	/* Sets the clipping rectangle extends */
}

/*  Main Loop */

int main(int argc, char** argv)
{
    /* GLUT functions to set up the window */
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowPosition (1800, 200);
	glutInitWindowSize(500, 500);
	glutInit(&argc, argv);
    glutCreateWindow (argv[0]);
    
    myinit();			/* Initialization */

    glutReshapeFunc (myReshape); /* Function to call when window changes size */
    glutMouseFunc(mouse);
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(RenderScene); /* Creating the Szene */
    glutMainLoop();	
    return 0;
}

