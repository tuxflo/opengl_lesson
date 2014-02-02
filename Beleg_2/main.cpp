#include <iostream>
#include "LoadShaders.h"
#include "./glm/glm/glm.hpp"

using namespace std;

//GLobal vars
GLuint ProgramID; //Main programm, contains compiled shaders
int width = 500;  //width of the window
int height = 500; // height of the window



void init()
{
    ProgramID = LoadShaders("../Beleg_2/vertex.vert", "../Beleg_2/fragment.frag");
}

void display()
{

}


void key_func(unsigned char key, int x, int y)
{

}


int main(int argc, char** argv)
{
    cout << "Hello OpenGl!" << endl;
    //cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

    glutInit(&argc, argv);
    if(glewIsSupported("GL_VERSION_1_0"))
    {
        cout << "ready for shading!" << endl;
    }
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width,height);
    glutInitContextVersion(2, 1);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutCreateWindow("Shader example");
    if(glewInit()){
        cerr << "unable to init GLEW!" << endl;
        exit(EXIT_FAILURE);
    }
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(key_func);
    glutMainLoop();
    return 0;
}

