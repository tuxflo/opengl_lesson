#include "GL/freeglut.h"
#include "GL/gl.h"
#include "math.h"
#include "stdio.h"

void paintLine(float radius);
void paintCircle(float radius);
/* display function - code from:
     http://fly.cc.fer.hr/~unreal/theredbook/chapter01.html
This is the actual usage of the OpenGL library. 
The following code is the same for any platform */
void renderFunction()
{
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLuint index = glGenLists(1);
	glNewList(index, GL_COMPILE);
		paintCircle(0.8);
		glPushMatrix();
		for(int i=0; i<30; i++)
		{
			glRotatef(12,0,0,1);
			paintLine(0.8);

		}
		glPopMatrix();
	glEndList();
	glCallList(index);
	glFlush();
	//paintCircle(0.8);
//	paintLine(0.8);
}

void paintCircle(float radius)
{
	float pi = 3.14159;
	//Draw the circle
	glBegin(GL_LINE_LOOP);
	for(int i = 0; i < 360; i++)
	{
		float tmp = i*(pi/180); //calc from deg to rad system
        	glVertex2f(cos(tmp)*radius,sin(tmp)*radius);
	}
	glEnd();
	
}
void paintLine(float radius)
{
	glBegin(GL_LINE_STRIP);
	for(float i=0; i<1; i++)
	{
		glVertex2f(0.0, 0.0);
		glVertex2f(0, radius);
	}
	glEnd();
	glFlush();
}
void keyboard(unsigned char key, int x, int y)
{ switch (key) {
	case 'w':
	glRotatef(30,0,0,1);
	paintLine(0.8);
	break;
	case 'a':
	glRotatef(50,0,1,0);
	paintLine(0.8);
	break;
	case 's':
	glRotatef(50,1,0,0);
	paintLine(0.8);
	break;
	default:
	       	printf("Taste %c gedrückt\n", key);
		  break;
	  }
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
    glutKeyboardFunc(keyboard);

    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}


