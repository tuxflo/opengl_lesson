/******************************

  Beispielprogramm "Quadrat"

*******************************/

#include <stdio.h>
#include <stdlib.h>
//#include <glew.h>
#include <GL/freeglut.h>
#include <math.h>

float _x=5;

float _y=5;
float x_new=0;
float y_new=0;
bool finished_move=true;
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
	//printf("value: %d\n", value);
	if(_x < 10 && _x > 0 && _y < 10 && _y > 0)
	{
		_x +=  0.01 * (x_new);
		_y +=  0.01 * (y_new);
		printf("x: %f y: %f \n", _x, _y);
		glutPostRedisplay();
		glutTimerFunc(20, timer, ++value);
	}
	else
	{
		printf("x: %f y: %f \n", _x, _y);
		finished_move = true;
	}

}
void mouse(int button, int state, int x, int y)
{
	switch(button)
	{
		case(GLUT_LEFT_BUTTON):
		if(state == GLUT_DOWN && finished_move)
		{
			finished_move = false;
			printf("left button: x= %d, y= %d\n", x, y);
			x_new = x - _x;
			y_new = 500 - y - _y;
			glPointSize(10);
			glBegin(GL_POINTS);
			glVertex2f(x, y);
			glEnd();
			glFlush();
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
	int radius = 1;
    /* Initializations */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor (1.0, 1.0, 1, 1.0); //Hintergrundfarbe
    glOrtho(0.0, 10, 0.0, 10, 0.0, 1.0);
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

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case('w'):
			break;
		
		
	}


}

void arrow_keys(int key, int x, int y)
{
	switch(key)
	{
		case(GLUT_KEY_UP):
			y_new = 9.9;
			break;
		case(GLUT_KEY_DOWN):
			y_new = 1 - _y;
			break;
		case(GLUT_KEY_RIGHT):
			x_new = 9.9;
			break;
		case(GLUT_KEY_LEFT):
			x_new = 1 - _x;
			break;	
	}
	timer(0);

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
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrow_keys);
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(RenderScene); /* Creating the Szene */
    glutMainLoop();	
    return 0;
}

