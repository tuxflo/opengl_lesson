#ifndef GLOBAL_H
#define GLOBAL_H
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <array>
#include "point.h"
#include "line.h"
class Point;
class Line;


//For real global stuff like the debug flag
namespace Global {
    extern bool debug_mode;
    extern int width;
    extern int height;
    extern int clickcounter;
    extern std::vector<Point> points;
    extern std::vector<Line> lines;
    extern std::vector<std::array<GLfloat, 3>> ctrlpoints;
}
void addPoint(Point p);
void addPoint();
void addLine(Point start, Point end);

#endif // GLOBAL_H
