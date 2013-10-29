#include "global.h"
namespace Global {
    bool debug_mode = true;
    int width = 500;
    int height = 500;
    std::vector<Point> points;
    std::vector<Line> lines;
    std::vector<std::array<GLfloat, 3>> ctrlpoints;
}

using namespace Global;
void addPoint(Point p)
{
    if(Global::debug_mode)
        std::cout << "drawing point at x: " << p.getX() << " y: " << p.getY() << " z: " <<p.getZ() << std::endl;
    ctrlpoints.push_back(std::array<GLfloat, 3>{{p.getX(), p.getY(),p.getZ()}});
    glutPostRedisplay();
}


void addLine(Point start, Point end)
{

}
