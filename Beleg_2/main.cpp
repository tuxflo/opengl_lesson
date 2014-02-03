#include <iostream>
#include "LoadShaders.h"
#include "./glm/glm/glm.hpp"
#include "./glm/glm/gtc/matrix_transform.hpp"
#include "./glm/glm/gtc/type_ptr.hpp"

using namespace std;
using namespace glm;

//GLobal vars
GLuint ProgramID; //Main programm, contains compiled shaders
int width = 500;  //width of the window
int height = 500; // height of the window

//create a model matrix (identity matrix)
mat4 model;
//create a Projection Matrix
mat4 projection;

//create a vie matrix
mat4 view;

//Model view projection matrix
mat4 MVP;

//ID of the bufferdata
GLuint vertexbuffer;


//the object
GLfloat vertices[] =
{
    0.0f, 0.0f, 0.0f,   //frontside
    30.0f, 0.0f, 0.0f,
    0.0f,  20.0f, 0.0f,

    0.0, 20.0, 0.0,
    30.0, 0.0, 0.0,
    30.0, 20.0, 0.0,

    0.0, 20.0, 0.0,                //top
    30.0, 20.0, 0.0,
    0.0, 20.0, 20.0,

    0.0, 20.0, 20.0,
    30.0, 20.0, 0.0,
    30.0, 20.0, 20.0,

    0.0f, 0.0f, 20.0f,          //backside
    30.0f, 0.0f, 20.0f,
    0.0f,  20.0f, 20.0f,

    0.0, 20.0, 20.0,
    30.0, 0.0, 20.0,
    30.0, 20.0, 20.0,

    0.0, 0.0, 0.0,                //bottom
    30.0, 0.0, 0.0,
    0.0, 0.0, 20.0,

    0.0, 0.0, 20.0,
    30.0, 0.0, 0.0,
    30.0, 0.0, 20.0,

    0.0, 0.0, 0.0,          //rightside
    0.0, 0.0, 20.0,
    0.0, 20.0, 20.0,

    0.0, 20.0, 20.0,
    0.0, 0.0, 0.0,
    0.0, 20.0, 0.0,

    30.0, 0.0, 0.0,          //leftside
    30.0, 0.0, 20.0,
    30.0, 20.0, 20.0,

    30.0, 20.0, 20.0,
    30.0, 0.0, 0.0,
    30.0, 20.0, 0.0,
};

float zoom = -60;




void init()
{
    ProgramID = LoadShaders("../Beleg_2/vertex.vert", "../Beleg_2/fragment.frag");
    glUseProgram(ProgramID);
    model = mat4(1.0);

    projection = perspective(45.0f, 4.0f / 4.0f, 0.1f, 180.0f);


    view = lookAt(
                vec3(40, 3, -120),
                vec3(0, 0, 0),  //the camera looks to x=5, y=5, z=0
                vec3(0, 1, 0) //head is up
                );

    MVP = projection * view  * model ;

    //allocate space on the GPU
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

    //fill the buffer with data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //enable depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

}

void display()
{

    //glMatrixMode(GL_PROJECTION);

    glViewport(0,0, width, height);
    //glOrtho(-100*zoom, 100*zoom, -100*zoom, 100*zoom, -100, 100);

    glClearColor(0.0, 0.0, 0.0, 1.0); //set color to black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear color and depth test

    view = lookAt(
                vec3(40, 3, zoom),
                vec3(0, 0, 0),  //the camera looks to x=5, y=5, z=0
                vec3(0, 1, 0) //head is up
                );

    MVP = projection * view  * model ;

    //enable the first location of the GPU space
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                0,
                3, //size (num of vertices for each triangle)
                GL_FLOAT, //type
                GL_FALSE,
                0,
                (void*)0
                );

    //pass the MVP matrix to the shaders
    GLuint MVP_ID = glGetUniformLocation(ProgramID, "MVP");
    glUniformMatrix4fv(MVP_ID, 1, GL_FALSE, &MVP[0][0]);

    //draw the triangles
    glDrawArrays(GL_TRIANGLES, 0, 30);
    //glutSolidTeapot(1.0);

    glutSwapBuffers();
}


void key_func(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'z':
        zoom -=2;
        display();
        break;
    case 'v':
        zoom += 2;
        display();
        break;
    }

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

