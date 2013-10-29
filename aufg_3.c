/******************************

  Beispielprogramm "Quadrat"

*******************************/

#include <stdio.h>
#include <stdlib.h>
//#include <glew.h>
#include <GL/freeglut.h>
#include <math.h>

GLint points = 5;
float height = 10;
float width = 10;
GLfloat ctrlpoints[5][3] = 	{{ 4.0f, 0.0f, 0.0f}, //Endpoint
				 { -6.0f, 4.0f, 0.0f},
				 { 6.0f, -4.0f, 0.0f},
				 { 4.0f, 0.0f, 0.0f},
				{ 8.0f, 2.0f, 0.0f}};//Endpoint
				
int currentClick = 0;

static void RenderScene(void);
void drawLines()
{
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i< currentClick;i++)
		{
			glVertex2fv(ctrlpoints[i]);
			glVertex2fv(ctrlpoints[i+1]);
		}
	glEnd();
	
}

void drawPoints(int x, int y)
{
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0f);
	printf("mous button pressed currentClick: %d  x: %f, y: %f\n",currentClick, x,  y);
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();
}

void setPoints(int button, int state, int x, int y)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN)
			{
				if(currentClick >= 5)
				{
					currentClick = 0;
					glClear(GL_COLOR_BUFFER_BIT);
					glFlush();
					return;
				}
				float _x = x;
				float _y= 500- y;
				//Set the clicked points as controll points
				ctrlpoints[currentClick][0] = _x;
				ctrlpoints[currentClick][1] = _y;
				//draw the controll points
				drawPoints(_x, _y);
				if(currentClick >= 1)
					drawLines();
				currentClick++;	
				//reached max number of controll points, draw the curve
				if(currentClick == 5)
				{
					RenderScene();
				}	
				glFlush();
			}
	}
}

static void myinit(void)
{   
	printf( "OpenGL renderer:                  |%s|\n", (char*)glGetString( GL_RENDERER));
	printf( "OpenGL driver version:            |%s|\n", (char*)glGetString( GL_VERSION));	

    /* Initializations */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor (1.0, 1.0, 1, 1.0); //Hintergrundfarbe
    glClear(GL_COLOR_BUFFER_BIT);
}


static void RenderScene(void)
{
    /* Creating the Scene */
//    glClear(GL_COLOR_BUFFER_BIT);   clears the whole scree
    glColor3f(0.0,0.0,0.0);		  /* White Rahmenfarbe*/
    

    glMap1f(GL_MAP1_VERTEX_3, //type of generated data
		    0.0f,	//lower u range
		   100.0f,	//upper u range
		 3,	//distance between points in data
		 points,	//number of controll points
		 &ctrlpoints[0][0]); //control points array

    glEnable(GL_MAP1_VERTEX_3);

    glBegin(GL_LINE_STRIP);
    glPointSize(5);
    for(int i=0; i<= 100; i++)
    {
	    glEvalCoord1f((GLfloat) i);
    }
    glEnd();

//    drawLines();
    
    glFlush ();		  /* Flushes OpenGL command queues and buffers */
}


static void myReshape(int w, int h)
{
    /* Callback function to handle window dimensions and size changes */

    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);	/* specifies the current matrix */
    glLoadIdentity();			/* Sets the currant matrix to identity */
    gluOrtho2D(0,500,0,500);	/* Sets the clipping rectangle extends */
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
    
    glutMouseFunc(setPoints);
    glutReshapeFunc (myReshape); /* Function to call when window changes size */
    glutDisplayFunc(RenderScene); /* Creating the Szene */
    myinit();			/* Initialization */
    glutMainLoop();	
    return 0;
}

