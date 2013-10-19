#include "GL/freeglut.h"
#include "GL/gl.h"
#include "math.h"

/* display function - code from:
     http://fly.cc.fer.hr/~unreal/theredbook/chapter01.html
This is the actual usage of the OpenGL library. 
The following code is the same for any platform */
void renderFunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	float pi = 3.14159;
	float radius = 0.8;
	//Draw the circle
	glBegin(GL_LINE_LOOP);
	for(int i = 0; i < 360; i++)
	{
		float tmp = i*(pi/180); //calc from deg to rad system
        	glVertex2f(cos(tmp)*radius,sin(tmp)*radius);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for(float i=0; i<2; i++)
	{
		glVertex2f(0.0, 0.0);
		glVertex2f(0, 0.5);
		glTranslatef(0.0, 0.5, 0.0);
		//glRotatef(30.0, 1.0, 1.0, 0.0);
		glVertex2f(0.0, 0.0);
		glVertex2f(0, 0.5);
	}

	glEnd();
	glFlush();
}

/* Main method - main entry point of application
the freeglut library does the window creation work for us, 
regardless of the platform. */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}


